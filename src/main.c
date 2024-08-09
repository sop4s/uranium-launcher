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
#include "launcher/logs.h"
#include "launcher/utils.h"
#include "config.h"

void ctrl_c(int s) {
  printf("\n");
  log_info("Closing game\n");
  exit(0);
}
int versions_to_selector(OptionSelector* selector) {
  DIR *d;
  MinecraftPath minecraft_dir;
  struct dirent *dir;
  
  get_minecraft_dir(minecraft_dir);
  strncat(minecraft_dir, "/versions/", strlen(minecraft_dir) + 10);
  d = opendir(minecraft_dir);
  
  if (!d) return 1; 
  while ((dir = readdir(d)) != NULL) {
    if (dir->d_name[0] != '.')
      selector_add(selector, dir->d_name);
  }
  closedir(d);
  return 0;
}
int main() {
  LaunchOptions options;
  LaunchCommand cmd;
  MinecraftVersion version;
  MinecraftPath minecraft_dir; 

  OptionSelector selector;
  
  signal(SIGINT, ctrl_c);
  printf(BANNER);

  printf("Enter your username: ");
  read_line(options.username);
  
  selector_init(&selector);
  versions_to_selector(&selector);

  printf("Select your version:\n");
  if (selector_select(&selector, version) != 0) return 1;

  get_minecraft_dir(minecraft_dir);
  get_command(cmd, &options, minecraft_dir, version);

  printf("Version: " FG_MAIN "%s\n" FG_RESET, version);
  printf("Command: " FG_MAIN "%s\n" FG_RESET, cmd);
  printf("Starting minecraft: " FG_MAIN);
  
  fflush(stdout);
  int exitcode = system(cmd);
  printf(FG_RESET);
  printf("Minecraft closed with code " FG_MAIN "%d\n" FG_RESET, exitcode);
  return exitcode;
}
