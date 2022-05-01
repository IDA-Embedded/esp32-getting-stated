
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
             )

###############################################################################################################
#						ADDON FOR ESP32 SPECIFIC SiP DEFINITIONS
###############################################################################################################
            
target_compile_definitions(${COMPONENT_LIB} PRIVATE
__ESP32__=1
PROJECT_NAME="TEMPLATE"
)

