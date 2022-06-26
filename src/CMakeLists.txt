cmake_minimum_required(VERSION 3.0)
project(examples)

set(CMAKE_CXX_STANDARD 17)


include_directories(${VISP_INCLUDE_DIRS})



set(SOURCES 
        camera/Camera.cpp)
set(HEADERS 
        camera/BaseCamera.h
        camera/Camera.h)

add_library(modelTrackingLib STATIC ${SOURCES} ${HEADERS})
# target_include_directories(modelTrackingLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS modelTrackingLib EXPORT modelTrackingLibTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)

install(FILES ${HEADERS} DESTINATION include)

install(EXPORT modelTrackingLibTargets
        FILE modelTrackingLibConfig.cmake
        NAMESPACE modelTrackingLib::
        DESTINATION lib/cmake/modelTrackingLib)
