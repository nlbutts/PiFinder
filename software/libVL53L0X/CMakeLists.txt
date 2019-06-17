set(CORESRCDIR     ${CMAKE_CURRENT_LIST_DIR}/core/src)
set(PLATFORMSRCDIR ${CMAKE_CURRENT_LIST_DIR}/platform/src)

set(CSRC         ${CORESRCDIR}/vl53l0x_api.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_calibration.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_core.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_ranging.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_strings.c)

set(CSRC ${CSRC} ${PLATFORMSRCDIR}/vl53l0x_platform.c)
set(CSRC ${CSRC} ${PLATFORMSRCDIR}/vl53l0x_platform_log.c)

add_library(VL53L0X ${CSRC})

target_include_directories(VL53L0X PUBLIC ${CMAKE_CURRENT_LIST_DIR}/core/inc)
target_include_directories(VL53L0X PUBLIC ${CMAKE_CURRENT_LIST_DIR}/platform/inc)