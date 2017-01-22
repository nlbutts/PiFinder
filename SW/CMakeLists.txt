cmake_minimum_required (VERSION 3.5)
project (piFinder)

SET(CMAKE_C_FLAGS "-O0 -std=c11 -g3")
SET(CMAKE_CXX_FLAGS "-O0 -std=c++11 -g3")

add_executable(piFinder src/main.cpp src/vl53l0x_i2c_platform.c)

add_subdirectory(libVL53L0X)
target_link_libraries(piFinder VL53L0X)

include_directories(${PROJECT_SOURCE_DIR}/libVL53L0X/core/inc)
include_directories(${PROJECT_SOURCE_DIR}/libVL53L0X/platform/inc)
