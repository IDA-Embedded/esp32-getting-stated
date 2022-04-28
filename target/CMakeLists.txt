
cmake_minimum_required(VERSION 3.18.4)

# set the default c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
###############################################################################################################
#							INSTALL Dependencies
###############################################################################################################
include(../cmake/installDependencies.cmake)
installESP32Dependencies()


###############################################################################################################
#							STANDARD ESP32 CMAKE SETUP
###############################################################################################################


include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(IntegrationTest)







