#include "launcher.h"
#include <linux/limits.h>
#include <stdio.h>
#include <dirent.h>

int get_command(
      LaunchCommand cmd, 
      LaunchOptions* opts, 
      MinecraftPath minecraft_dir, 
      MinecraftVersion version) {
  MinecraftArguments args;
  MinecraftPath version_dir;
  MinecraftPath version_json_path;
  snprintf(cmd, COMMAND_MAX, "%s%s", 
    minecraft_dir, 
    "runtime/jre-legacy/linux/jre-legacy/bin/java -version");
  
  snprintf(version_dir, PATH_MAX, "%s%s%s/", minecraft_dir, "versions/", version);
  snprintf(version_json_path, PATH_MAX, "%s%s.json", version_dir, version);
  
  return 0;
}

int set_username(LaunchOptions *options, const char* name) {
  return snprintf(options->username, USERNAME_MAX, "%s", name);
}
