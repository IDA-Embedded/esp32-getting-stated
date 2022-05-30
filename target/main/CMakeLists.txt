
cmake_minimum_required(VERSION 3.18.4)
###############################################################################################################
#                               Basic ESP32 setup
###############################################################################################################
set(COMP_PATH "./Components")


idf_component_register(SRC_DIRS "."
             INCLUDE_DIRS ""   
             SRC_DIRS "${COMP_PATH}/ErrorHandler/src/"
             INCLUDE_DIRS "${COMP_PATH}/ErrorHandler/include/"
             SRC_DIRS "${COMP_PATH}/Timeservice/src/"
             INCLUDE_DIRS "${COMP_PATH}/Timeservice/include/"
             INCLUDE_DIRS "${COMP_PATH}/Common_Include/"
             
              SRC_DIRS "${COMP_PATH}/esp32Cam_API/src/"
             INCLUDE_DIRS "${COMP_PATH}/esp32Cam_API/include/"
             
              SRC_DIRS "${COMP_PATH}/esp32Cam/src/"
             INCLUDE_DIRS "${COMP_PATH}/esp32Cam/include/"
             
              SRC_DIRS "${COMP_PATH}/HTTP/src/"
             INCLUDE_DIRS "${COMP_PATH}/HTTP/include/"
             
              SRC_DIRS "${COMP_PATH}/WiFi/src/"
             INCLUDE_DIRS "${COMP_PATH}/WiFi/include/"
             
             )

###############################################################################################################
#						ADDON FOR ESP32 SPECIFIC SiP DEFINITIONS
###############################################################################################################
            
target_compile_definitions(${COMPONENT_LIB} PRIVATE
__ESP32__=1
PROJECT_NAME="TEMPLATE"
)

###############################################################################################################
#						INSTALL SECRETS
###############################################################################################################

include(../../cmake/secrets.cmake)


