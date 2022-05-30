/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       esp32Cam.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2021-12-28
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/esp32Cam.hpp"

#define DEBUG // default uncommeted

#ifdef __ESP32__

static camera_config_t camera_config = {
	.pin_pwdn = CAM_PIN_PWDN,
	.pin_reset = CAM_PIN_RESET,
	.pin_xclk = CAM_PIN_XCLK,
	.pin_sscb_sda = CAM_PIN_SIOD,
	.pin_sscb_scl = CAM_PIN_SIOC,

	.pin_d7 = CAM_PIN_D7,
	.pin_d6 = CAM_PIN_D6,
	.pin_d5 = CAM_PIN_D5,
	.pin_d4 = CAM_PIN_D4,
	.pin_d3 = CAM_PIN_D3,
	.pin_d2 = CAM_PIN_D2,
	.pin_d1 = CAM_PIN_D1,
	.pin_d0 = CAM_PIN_D0,
	.pin_vsync = CAM_PIN_VSYNC,
	.pin_href = CAM_PIN_HREF,
	.pin_pclk = CAM_PIN_PCLK,

	// XCLK 20MHz or 10MHz for OV2640 double FPS (Experimental)
	.xclk_freq_hz = 20000000,
	.ledc_timer = LEDC_TIMER_0,
	.ledc_channel = LEDC_CHANNEL_0,

	//.pixel_format = PIXFORMAT_GRAYSCALE,
	//.pixel_format = PIXFORMAT_RGB565, // YUV422,GRAYSCALE,RGB565,JPEG
	.pixel_format = PIXFORMAT_JPEG, // YUV422,GRAYSCALE,RGB565,JPEG
	.frame_size = FRAMESIZE_FHD, // QQVGA-UXGA Do not use sizes above QVGA when not JPEG
	//.frame_size = FRAMESIZE_QVGA, // QQVGA-UXGA Do not use sizes above QVGA when not JPEG

	.jpeg_quality = 12, // 0-63 lower number means higher quality
	.fb_count = 1, // if more than one, i2s runs in continuous mode. Use only with JPEG
	.fb_location = CAMERA_FB_IN_PSRAM,
	.grab_mode = CAMERA_GRAB_WHEN_EMPTY,
};
#endif

#ifdef DEBUG
static const char* LOG_TAG = "esp32Cam";
#endif

general_err_t esp32Cam::takePicture()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> esp32Cam::fcn>> ");
#endif
	// Executable code:
	std::cout << "taking a picture! \n";
	if(!m_hasImageBeenReleased)
	{
#ifdef DEBUG
		std::cout << "We have not released the previous image!!! \n";
#endif
		return GE_NO_DATA;
	}

#ifdef __ESP32__

	m_pic = esp_camera_fb_get();

#endif
	m_hasImageBeenReleased = false;
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<<  esp32Cam:: << ");
#endif

	return GE_OK;
}

general_err_t esp32Cam::init_camera()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> esp32Cam::init_camera >> ");
#endif
// Executable code:
#ifdef __ESP32__

	auto esp_err = esp_camera_init(&camera_config);
	if(esp_err != ESP_OK)
	{
		std::cout << " esp error is : " << (int)esp_err << "\n";
		return GE_FAIL;
	}
#endif

#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<<  esp32Cam::init_camera << ");
#endif

	return GE_OK;
}
general_err_t esp32Cam::releasePicture()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> esp32Cam::fcn >> ");
#endif
	if(m_hasImageBeenReleased)
	{
#ifdef DEBUG
		std::cout << "Nothing to be released! \n";
#endif
		return GE_NO_DATA;
	}
	// Executable code:
#ifdef __ESP32__
	esp_camera_fb_return(m_pic);
#endif

	m_hasImageBeenReleased = true;
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<<  esp32Cam::fcn << ");
#endif

	return GE_OK;
}
camera_fb_t* esp32Cam::getPicture()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> esp32Cam::fcn >> ");
#endif
	// Executable code:
	if(m_hasImageBeenReleased)
	{
#ifdef DEBUG
		std::cout << "Nothing to be returned! \n";
#endif
		return nullptr;
	}
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<<  esp32Cam::fcn << ");
#endif

	return m_pic;
}

general_err_t esp32Cam::getJPGPicture(uint8_t* out, size_t* length)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> esp32Cam::getJPGPicture >> ");
#endif
	// Executable code:
	// Executable code:
	if(m_hasImageBeenReleased)
	{
#ifdef DEBUG
		std::cout << "Nothing to be returned! \n";
#endif
		return GE_NO_DATA;
	}
#ifdef __ESP32__
	if(!frame2jpg(m_pic, 80, &out, length))
	{
#ifdef DEBUG
		std::cout << "Nothing to be returned! \n";
#endif
		return GE_NO_DATA;
	}
#endif
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<<  esp32Cam::getJPGPicture << ");
#endif

	return GE_OK;
}

general_err_t esp32Cam::deinit_camera()
{
	auto err = GE_OK;
#ifdef __ESP32__
	err = esp_camera_deinit() == ESP_OK ? GE_OK : GE_FAIL;
#endif
	return err;
}

general_err_t esp32Cam::reboot_camera()
{
	std::cout << " rebooting camera ... \n";

	std::cout << " ... deinit ... \n";
	auto err = deinit_camera();
	if(err != GE_OK)
	{
		std::cout << " failed to deinit ...  we reboot\n";
		exit(-1);
	}
	std::cout << " deinit OK \n";

	std::cout << " init camera \n";
	err = init_camera();
	if(err != GE_OK)
	{
		std::cout << " failed to init ...  we reboot\n";
		exit(-1);
	}
	return GE_OK;
}
