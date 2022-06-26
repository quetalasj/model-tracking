cmake_minimum_required(VERSION 3.0)
project(examples)

set(CMAKE_CXX_STANDARD 17)


include_directories(${VISP_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/camera)


add_executable(camera main.cpp)

target_link_libraries(camera ${VISP_LIBRARIES})
target_link_libraries(camera modelTrackingLib::modelTrackingLib)
