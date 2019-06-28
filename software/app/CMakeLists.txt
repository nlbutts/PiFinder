add_executable(piFinder ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)
target_link_libraries(piFinder VL53L0X pifinder)
