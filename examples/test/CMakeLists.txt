cmake_minimum_required(VERSION 3.0)
project(examples)

set(CMAKE_CXX_STANDARD 17)



include_directories(${VISP_INCLUDE_DIRS})

add_executable(test main.cpp)

target_link_libraries(test ${VISP_LIBRARIES})

