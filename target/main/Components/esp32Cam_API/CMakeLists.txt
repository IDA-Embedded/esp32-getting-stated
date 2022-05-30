
#[[ 
We must always set the miminum required version
This will also explicit set the cmake behavior.
It is recommendend to use 3.17+ due to some changes (?)
]]
cmake_minimum_required(VERSION 3.18.4)
set(LIBNAME ESP32CAM_API)


set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/cam_hal.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/esp_camera.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/ll_cam.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/ov3660.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/sccb.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/sensor.c;" CACHE STRING "avaliable build src" FORCE)
set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/xclk.c;" CACHE STRING "avaliable build src" FORCE)


set(COSTUM_INC_FILES ${COSTUM_INC_FILES} "${CMAKE_CURRENT_LIST_DIR}/include" CACHE STRING "avaliable build inc" FORCE)


