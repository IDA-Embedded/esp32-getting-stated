#ifndef _MODULES_SENSOR_ESP32CAM_INCLUDE_ESP32CAM_HPP_
#define _MODULES_SENSOR_ESP32CAM_INCLUDE_ESP32CAM_HPP_
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  @file  esp32Cam.hpp
 |
 |  @author        :  Nikolaj Gliese Pedersen
 |  @email         :  <nikolajgliese@tutanota.com>
 |  @date		   : 2021-12-28
 |
 |  @brief  	   :  This class, esp32Cam.hpp, is designed as:
 |
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
#include "../../image_conversions/include/img_converters.h"
#include "m5stack_settings.hpp"
#include <Timeservice.hpp>
#include <esp_camera.h>
#include <iostream>

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/
#ifndef __ESP32__
using camera_fb_t = char; // for utest env
#endif
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
// TODO make Threadsafe .................
/**
 * @class This class is an esp32Camera module class which uses m5stack as the devboard
 * 		  The class is a singleton because we can only have ONE(1) camera per system
 * 		  It is, however, possible to generate multiple variables of the camera class
 * 		  But it is not anything more than a pointer to the singleton
 * @warning This class is <br> NOT <\br> threadsafe. Do <br> NOT <\br> create multiple
 * 			instances, because the image buffer can be released by 1 instance while kept pointing
 * 			at by another.
 * @todo We need to implement smart_pointers to enable threadsafe-ing
 *
 *
 */

class esp32Cam
{
#ifdef __UNITTEST__
	friend class friend_esp32Cam;
#endif
  public:
	/**
	 * @brief Singleton - constructor, this ensures us that only ONE(1) instance of esp32cam exists
	 *
	 * @return esp32Cam&
	 */
	inline static esp32Cam& Instance()
	{
		static esp32Cam instance;
		return instance;
	}
	/**
	 * @brief This function takes a picture with the esp32 camera
	 * @return: error code based on result
	 */
	general_err_t takePicture();
	/**
	 * @brief Get the Picture object
	 * @warning  This is a raw pointer, and should have been implemented as a smartpointer
	 *
	 * @return camera_fb_t*
	 */
	camera_fb_t* getPicture();
	/**
	 * @brief release the image buffer
	 * @warning it is required to call this whenever the prior image is not
	 * 			longer needed. We are blocking the opotunity to retrieve another
	 * 			image as long as this has not been called
	 *
	 * @return general_err_t
	 */
	general_err_t releasePicture();

	/**
	 * @brief get the picture in JPG format
	 * @warning we are using pointers here since the underlying SDK is requesting it
	 *
	 * @param out
	 * @param length
	 * @return general_err_t
	 */
	general_err_t getJPGPicture(uint8_t* out, size_t* length);
	/**
	 * @brief reboot the camera
	 *
	 * @return general_err_t
	 */
	static general_err_t reboot_camera();

  private:
	inline esp32Cam() : m_hasImageBeenReleased{true}, m_pic{nullptr}
	{
		auto err = init_camera();
		if(err != GE_OK)
		{
			Timeservice::wait_sec(5);
			exit(-1);
		}
	};
	inline ~esp32Cam(){};
	static general_err_t init_camera();
	static general_err_t deinit_camera();
	bool m_hasImageBeenReleased;

	camera_fb_t* m_pic;
};

/*------------------------------------------------------------------------------+
 |   		 				 Unit Test Class               		                |
 +------------------------------------------------------------------------------*/

#ifdef __UNITTEST__
class friend_esp32Cam
{
  public:
	explicit friend_esp32Cam(esp32Cam* sensor) : m_sensor{sensor} {};
	~friend_esp32Cam();

  private:
	esp32Cam* m_sensor;
};
#endif

#endif //_MODULES_SENSOR_ESP32CAM_INCLUDE_ESP32CAM_HPP_
