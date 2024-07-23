#include <stdio.h>
#include <string.h>
#include "input.h"
#include "colors.h"
#include "../config.h"

int read_line(char *buf) {
  printf(FG_MAIN);
  if (!fgets(buf, sizeof(buf), stdin)) return 1;
  buf[strcspn(buf, "\n")] = '\0';
  printf(FG_RESET);
  return 0;
}
int read_int(int *num) {
  char buf[8];
  if (read_line(buf) != 0) return 1;
  return sscanf(buf, "%d", num);
}
