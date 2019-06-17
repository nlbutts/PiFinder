cmake_minimum_required (VERSION 3.7)
project (piFinder)

SET(CMAKE_C_FLAGS "-O0 -std=c11 -g3")
SET(CMAKE_CXX_FLAGS "-O0 -std=c++11 -g3")

add_subdirectory(libVL53L0X)
add_subdirectory(libpifinder)
add_subdirectory(app)

