cmake_minimum_required(VERSION 3.0)
project(examples)

set(CMAKE_CXX_STANDARD 17)

#find_package(VISP REQUIRED)

include_directories(${VISP_INCLUDE_DIRS})

add_executable(camera main.cpp)


target_link_libraries(camera ${VISP_LIBRARIES})

