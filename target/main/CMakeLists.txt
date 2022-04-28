
cmake_minimum_required(VERSION 3.18.4)
###############################################################################################################
#							INSTALL SiP-Library
###############################################################################################################

# User input: Path to library
set(PATH_TO_LIBRARY "/home/$ENV{USER}/Projects/SiP_Embedded/Library")
# User input: Library name and version
set(LIB_NAME "LibraryModule-1.0-Source")

###############################################################################################################
set(INSTALL_PATH "${CMAKE_CURRENT_LIST_DIR}/")
include(../../cmake/installLibrary.cmake)
# even with a custum target, we need to install it manually the first time ...
installSiPLib(${PATH_TO_LIBRARY} "${LIB_NAME}.zip" ${INSTALL_PATH})
set(TOOLS_PATH "${CMAKE_CURRENT_LIST_DIR}/../../tools")

###############################################################################################################
#						Get the source and header folders for the SiP lib
###############################################################################################################

set(INSTALL_PATH "${CMAKE_CURRENT_LIST_DIR}/")
include(${INSTALL_PATH}${LIB_NAME}/cmake/LibraryGetter.cmake)
set(UNWANTED_LIBS  CMake latex Template Collection AnalysisTools Sensor )
GetLibraryFiles(COSTUM_SOURCE_LIST COSTUM_HEADER_LIST UNWANTED_LIBS)

set(WANTED_OBJECTS_LIBS CO2Sensor ColorSensor Distsensor mlx90640Cam TemperatureAndHumiditySensor TemperaturePointSensor esp32Cam)
GetLibraryFilesBaseOnFolders(ADD_SOURCE_LIST ADD_HEADER_LIST WANTED_OBJECTS_LIBS)
###############################################################################################################
#                               Basic ESP32 setup
###############################################################################################################

idf_component_register(SRC_DIRS "."
             INCLUDE_DIRS ""   
             SRC_DIRS "${COSTUM_SOURCE_LIST}"
             INCLUDE_DIRS "${COSTUM_HEADER_LIST}"
             SRC_DIRS "${ADD_SOURCE_LIST}"
             INCLUDE_DIRS "${ADD_HEADER_LIST}"
             )

###############################################################################################################
#						ADDON FOR ESP32 SPECIFIC SiP DEFINITIONS
###############################################################################################################
            
target_compile_definitions(${COMPONENT_LIB} PRIVATE
__ESP32__=1
LOGGER_MQTT=1 #define logger interface LOGGER_STDOUT | LOGGER_MQTT
PROJECT_NAME="TEMPLATE"
)

target_compile_definitions(${COMPONENT_LIB} PRIVATE
GLOBAL_MQTT_SERVER="mqtt://10.212.13.90:1883"
#GLOBAL_MQTT_SERVER="mqtt://192.168.1.157:1883"
MQTT_OTA_TOPIC="mqtt/${PROJECT_NAME}"
)

###############################################################################################################
#						CUSTUM COMMAND FOR INSTALLING
###############################################################################################################
add_custom_target(install_sip_lib 
COMMAND sh ${TOOLS_PATH}/installLibrary.sh ${PATH_TO_LIBRARY}/build/${LIB_NAME} ${INSTALL_PATH}
)
