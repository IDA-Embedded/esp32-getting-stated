
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
#						ADDON FOR PROJECT SPECIFIC DEFINITIONS
###############################################################################################################
            
target_compile_definitions(${COMPONENT_LIB} PRIVATE
__ESP32__=1
PROJECT_NAME="IDAE_ESP_GETTING_STARTED"
)
target_compile_definitions(${COMPONENT_LIB} PRIVATE
GLOBAL_MQTT_SERVER="mqtt://1.1.1.1:1883"
MQTT_OTA_TOPIC="mqtt/${PROJECT_NAME}"
#WIFI_SSID_LOCAL="IDA Embedded Workshop"
#WIFI_PWD_LOCAL="abcd1234"
WIFI_SSID_LOCAL="Drone01"
WIFI_PWD_LOCAL="14Louise"
SERVER_IP="192.168.1.157"
SERVER_PORT=1880
)

###############################################################################################################
#						INSTALL SECRETS
###############################################################################################################

#include(../../cmake/secrets.cmake)


