#ifndef CONSTANTS_H
#define CONSTANTS_H

  #include <linux/limits.h>
  #define USERNAME_MAX 17
  #define COMMAND_MAX 200

  typedef char MinecraftVersion[20];
  typedef char LaunchCommand[COMMAND_MAX];
  typedef char MinecraftPath[PATH_MAX];
  typedef char MinecraftArguments[200];

#endif // !CONSTANTS_H
