#include "launcher.h"
#include <stdio.h>

int get_command(
    LaunchCommand cmd, 
    LaunchOptions* opts, 
    MinecraftPath minecraft_dir, 
    MinecraftVersion version) {
  MinecraftArguments args;
  
  snprintf(cmd, COMMAND_MAX, "%s%s", 
    minecraft_dir, 
    "runtime/jre-legacy/linux/jre-legacy/bin/java -version");
  return 0;
}

int set_username(LaunchOptions *options, const char* name) {
  return snprintf(options->username, USERNAME_MAX, "%s", name);
}
