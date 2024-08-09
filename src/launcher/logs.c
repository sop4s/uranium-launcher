#include "logs.h"
#include <stdio.h>
#include <stdarg.h>

#define MK_LOG(IDENT, MSG) \
void IDENT(const char *format, ...) { \
  va_list args; \
  va_start(args, format); \
  printf(MSG); \
  vprintf(format, args); \
  va_end(args); \
}

MK_LOG(log_info, INFO);
MK_LOG(log_error, ERROR);
MK_LOG(log_warn, WARN);
