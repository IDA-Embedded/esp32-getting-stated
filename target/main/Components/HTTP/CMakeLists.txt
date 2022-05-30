
#[[ 
We must always set the miminum required version
This will also explicit set the cmake behavior.
It is recommendend to use 3.17+ due to some changes (?)
]]
cmake_minimum_required(VERSION 3.18.4)
set(LIBNAME HTTP)


set(COSTUM_SRC_FILES ${COSTUM_SRC_FILES} "${CMAKE_CURRENT_LIST_DIR}/src/esp32_http_sal.cpp;" CACHE STRING "avaliable build src" FORCE)

set(COSTUM_INC_FILES ${COSTUM_INC_FILES} "${CMAKE_CURRENT_LIST_DIR}/include" CACHE STRING "avaliable build inc" FORCE)

if(BUILD_TESTING)
## add the source folder to the cmake list:
add_subdirectory(test)
endif()
