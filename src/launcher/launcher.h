#ifndef LAUNCHER_H
#define LAUNCHER_H
  #include "constants.h"
  typedef struct {
    char username[USERNAME_MAX];
  } LaunchOptions;

  int get_command(
    LaunchCommand cmd, 
    LaunchOptions* opts, 
    MinecraftPath minecraft_dir, 
    MinecraftVersion version);
  int set_username(LaunchOptions *options, const char* name);
#endif
