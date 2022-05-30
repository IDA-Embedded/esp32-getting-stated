#ifndef _MODULES_SENSOR_ESP32CAM_INCLUDE_M5STACK_SETTINGS_HPP_
#define _MODULES_SENSOR_ESP32CAM_INCLUDE_M5STACK_SETTINGS_HPP_
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  @file  m5stack_settings.hpp
 |
 |  @author        :  Nikolaj Gliese Pedersen
 |  @email         :  <nikolajgliese@tutanota.com>
 |  @date		   : 2021-12-28
 |
 |  @brief  	   :  This class, m5stack_settings.hpp, is designed as:
 |                  a settings overlay for the esp32Cam - ov3660, M5STACK module
 |
 |
 |
 |
 |
 |
 |  @version       : 1.0
 |
 |  @bug  		   :   no known bugs
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*----------------- DEFAULT INCLUDE -------------------------------------------*/
#include <BASIC.hpp>
#include <General_Error.hpp>
/*-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/// The following defines are seen @https://github.com/espressif/esp32-camera/blob/master/Kconfig
/// and implemented here for easier-to-use, instead of relliance of a Kconfig file
#define CONFIG_OV3660_SUPPORT (1)
#define CONFIG_CAMERA_DMA_BUFFER_SIZE_MAX (32768)

#include "esp_camera.h"

#ifdef __ESP32__

#define BOARD_ESP32CAM_M5STACK (1)

// WROVER-KIT PIN Map
#ifdef BOARD_WROVER_KIT

#define CAM_PIN_PWDN -1 // power down is not used
#define CAM_PIN_RESET -1 // software reset will be performed
#define CAM_PIN_XCLK 21
#define CAM_PIN_SIOD 26
#define CAM_PIN_SIOC 27

#define CAM_PIN_D7 35
#define CAM_PIN_D6 34
#define CAM_PIN_D5 39
#define CAM_PIN_D4 36
#define CAM_PIN_D3 19
#define CAM_PIN_D2 18
#define CAM_PIN_D1 5
#define CAM_PIN_D0 4
#define CAM_PIN_VSYNC 25
#define CAM_PIN_HREF 23
#define CAM_PIN_PCLK 22

#endif

// ESP32Cam (AiThinker) PIN Map
#ifdef BOARD_ESP32CAM_AITHINKER

#define CAM_PIN_PWDN 32
#define CAM_PIN_RESET -1 // software reset will be performed
#define CAM_PIN_XCLK 0
#define CAM_PIN_SIOD 26
#define CAM_PIN_SIOC 27

#define CAM_PIN_D7 35
#define CAM_PIN_D6 34
#define CAM_PIN_D5 39
#define CAM_PIN_D4 36
#define CAM_PIN_D3 21
#define CAM_PIN_D2 19
#define CAM_PIN_D1 18
#define CAM_PIN_D0 5
#define CAM_PIN_VSYNC 25
#define CAM_PIN_HREF 23
#define CAM_PIN_PCLK 22

#endif
// ESP32Cam (M5Stack) PIN Map
#ifdef BOARD_ESP32CAM_M5STACK

#define CAM_PIN_PWDN -1
#define CAM_PIN_RESET 15 // software reset will be performed
#define CAM_PIN_XCLK 27
#define CAM_PIN_SIOD 25
#define CAM_PIN_SIOC 23

#define CAM_PIN_D7 19
#define CAM_PIN_D6 36
#define CAM_PIN_D5 18
#define CAM_PIN_D4 39
#define CAM_PIN_D3 5
#define CAM_PIN_D2 34
#define CAM_PIN_D1 35
#define CAM_PIN_D0 32
#define CAM_PIN_VSYNC 22
#define CAM_PIN_HREF 26
#define CAM_PIN_PCLK 21

#endif
#endif

#endif //_MODULES_SENSOR_ESP32CAM_INCLUDE_M5STACK_SETTINGS_HPP_
