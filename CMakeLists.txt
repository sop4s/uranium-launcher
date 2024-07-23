cmake_minimum_required(VERSION 3.10)
project(
  uranium-launcher
  VERSION 0.1
  LANGUAGES C
)
set(SOURCES
  src/main.c
  src/launcher/launcher.c
  src/launcher/utils.c
  src/cli/option_selector.c
  src/cli/input.c
)
add_executable(${PROJECT_NAME} ${SOURCES})
