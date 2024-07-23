#include "utils.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
int get_minecraft_dir(MinecraftPath path) {
  char *home = getenv("HOME");
  if (home == NULL) {
    return 1;
  }
  snprintf(path, PATH_MAX, "%s/.minecraft/", home);
  return 0;
}
