set(CSRC         ${CMAKE_CURRENT_LIST_DIR}/src/vl53l0x_platform.c)
set(CSRC ${CSRC} ${CMAKE_CURRENT_LIST_DIR}/src/vl53l0x_platform_log.c)
set(CSRC ${CSRC} ${CMAKE_CURRENT_LIST_DIR}/src/vl53l0x_i2c_platform.c)

add_library(pifinder ${CSRC})
target_link_libraries(pifinder VL53L0X)
