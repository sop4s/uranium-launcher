#include "launcher.h"
#include <stdio.h>

int get_command(
    LaunchCommand cmd, 
    LaunchOptions* opts, 
    MinecraftPath minecraft_dir, 
    MinecraftVersion version) {
  MinecraftArguments args = "";
  snprintf(cmd, COMMAND_MAX, "%s %s %s %s", 
  "/home/sopas/.minecraft/runtime/jre-legacy/linux/jre-legacy/bin/java",
  "-Xmx2G -jar /home/sopas/.minecraft/versions/1.12.2/1.12.2.jar",
  "-username", opts->username);
  return 0;
}

int set_username(LaunchOptions *options, const char* name) {
  return snprintf(options->username, USERNAME_MAX, "%s", name);
}
