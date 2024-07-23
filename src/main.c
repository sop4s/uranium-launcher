#include <signal.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "cli/input.h"
#include "cli/option_selector.h"
#include "cli/colors.h"
#include "launcher/constants.h"
#include "launcher/launcher.h"
#include "launcher/utils.h"
#include "config.h"

void ctrl_c(int s) {
  printf("\nClosing\n");
  exit(0);
}
int versions_to_selector(OptionSelector* selector) {
  DIR *d;
  MinecraftPath minecraft_dir;
  get_minecraft_dir(minecraft_dir);
  strncat(minecraft_dir, "/versions/", strlen(minecraft_dir) + 10);
  struct dirent *dir;
  d = opendir(minecraft_dir);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_name[0] != '.') {
        add_option(selector, dir->d_name);
      }
    }
    closedir(d);
  }
  return 0;
}
int main() {
  signal(SIGINT, ctrl_c);

  printf(FG_MAIN BANNER FG_RESET);
  
  LaunchOptions options;
  
  char username[USERNAME_MAX];
  printf("Enter your username: ");
  read_line(options.username);
  
  LaunchCommand cmd;
  MinecraftVersion version = "1.12.2";
  MinecraftPath minecraft_dir; 
  
  OptionSelector selector;
  init_option_selector(&selector);
  versions_to_selector(&selector);
 
  printf("Select your version:\n");
  char* selection;
  wait_selection(&selector, selection);

  get_minecraft_dir(minecraft_dir);
  printf("minecraft_dir: " FG_MAIN "%s\n" FG_RESET, minecraft_dir);
  
  get_command(cmd, &options, minecraft_dir, version);

  printf("options.username: " FG_MAIN "%s" FG_RESET "\n", options.username);
  printf("cmd: " FG_MAIN "%s" FG_RESET "\n", cmd);
  printf("\nStarting minecraft: " FG_MAIN);
  fflush(stdout);
  int exitcode = system(cmd);
  printf(FG_RESET);
  printf("Minecraft closed with code: " FG_MAIN "%d" FG_RESET "\n", exitcode);
  return exitcode;
}
