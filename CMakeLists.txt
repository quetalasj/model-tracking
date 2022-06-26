cmake_minimum_required(VERSION 3.0)
project(tracking)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_FIND_DEBUG_MODE TRUE)
# find_package(VISP CONFIG REQUIRED PATH /root/visp-ws/visp-build/VISPConfig.cmake)

find_package(VISP REQUIRED PATHS /root/visp-ws/visp-build)

add_subdirectory(src)
add_subdirectory(examples)
