#ifndef LOGS_H
#define LOGS_H

#include "../cli/colors.h"

#define INFO  FG_RESET "[" FG_LIGHT_GREEN "INFO"  FG_RESET "] "
#define ERROR FG_RESET "[" FG_RED "ERROR" FG_RESET "] "
#define WARN  FG_RESET "[" FG_YELLOW "WARN"  FG_RESET "] "

void log_info(const char *format, ...);
void log_error(const char *format, ...);
void log_warn(const char *format, ...);

#endif // !LOGS_H
