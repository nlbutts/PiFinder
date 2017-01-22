set(CORESRCDIR     ${PROJECT_SOURCE_DIR}/libVL53L0X/core/src)
set(PLATFORMSRCDIR ${PROJECT_SOURCE_DIR}/libVL53L0X/platform/src)

set(CSRC         ${CORESRCDIR}/vl53l0x_api.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_calibration.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_core.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_ranging.c)
set(CSRC ${CSRC} ${CORESRCDIR}/vl53l0x_api_strings.c)

set(CSRC ${CSRC} ${PLATFORMSRCDIR}/vl53l0x_platform.c)
set(CSRC ${CSRC} ${PLATFORMSRCDIR}/vl53l0x_platform_log.c)

add_library(VL53L0X ${CSRC})

include_directories(${PROJECT_SOURCE_DIR}/libVL53L0X/core/inc)
include_directories(${PROJECT_SOURCE_DIR}/libVL53L0X/platform/inc)