cmake_minimum_required(VERSION 3.0)
project(tracking)

set(CMAKE_CXX_STANDARD 17)

# message("visp_dir = $ENV{VISP_DIR}")

# message("whoami = $ENV{HOME}")
# message("ws = $ENV{VISP_WS}")
# message("path = $ENV{VISP_INPUT_IMAGE_PATH}")
# message("${CMAKE_VERSION}")


set(CMAKE_FIND_DEBUG_MODE TRUE)
# find_package(VISP CONFIG REQUIRED PATH /root/visp-ws/visp-build/VISPConfig.cmake)
find_package(VISP REQUIRED PATHS /root/visp-ws/visp-build)

add_subdirectory(examples)
