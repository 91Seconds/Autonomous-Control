cmake_minimum_required(VERSION 3.5)
project(Autonomous_Control)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Correlation/Correlation.cpp
    Correlation/Correlation2.cpp
    E101/LibE101/obj/Release/e101lib.h
    E101/LibE101/obj/Release/lib_test.cpp
    E101/LibE101/obj/Release/LibE101.h
    E101/LibE101/camera.cpp
    E101/LibE101/camera.h
    E101/LibE101/cameracontrol.cpp
    E101/LibE101/cameracontrol.h
    E101/LibE101/graphics.cpp
    E101/LibE101/graphics.h
    E101/LibE101/lib_test.cpp
    E101/LibE101/main.cpp
    E101/LibE101/main.h
    E101/LibE101/mmalincludes.h
    E101/LibTest/libtest/lt.cpp
    Filters/EdgeDetection.cpp
    MoreFilters/EdgeDetection.cpp
    PD-Controller/PD-Controller.cpp)

add_executable(Autonomous_Control ${SOURCE_FILES})