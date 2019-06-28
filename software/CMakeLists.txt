cmake_minimum_required (VERSION 3.12)
project (piFinder)

SET(CMAKE_C_FLAGS "-O0 -std=c11 -g3")
SET(CMAKE_CXX_FLAGS "-O0 -std=c++11 -g3")
SET(PIFINDER_PYTHON_C_MODULE_NAME "laser" CACHE STRING "Name of the C extension module file")

add_subdirectory(libVL53L0X)
add_subdirectory(libpifinder)
add_subdirectory(app)

find_package (Python3 COMPONENTS Development)
#find_package(PythonInterp 3.5 REQUIRED)
#find_package(PythonLibs  3.5 REQUIRED)
add_subdirectory(python)

