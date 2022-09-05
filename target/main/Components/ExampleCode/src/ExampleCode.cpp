/***********************************************************************************************+
 *  \brief      BRIEF TEXT
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       ExampleCode.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2022
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/ExampleCode.hpp"

//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "ExampleCode";
#endif

void ExampleCode::startWifi()
{
	std::cout << "Running a test : starting wifi ! \n ";
	WiFi_SAL_esp32 m_wifi{{Not_Visible::WIFI_SSID, Not_Visible::WIFI_PASS}};
	m_wifi.connect();

	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(5);
	}
}

void ExampleCode::sendHttpText(const std::string& text)
{
	std::cout << "Running a test : starting wifi ! \n ";
	WiFi_SAL_esp32 m_wifi{{Not_Visible::WIFI_SSID, Not_Visible::WIFI_PASS}};
	m_wifi.connect();

	esp32_http_sal m_http{Not_Visible::SERVER_IP, Not_Visible::SERVER_PORT};
	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(5);
		m_http.post("/esp32_postTest", esp32_http_sal::content_type::TEXT, text);
	}
}

void ExampleCode::captureImage()
{
	std::cout << "Create Campera Component\n ";
	esp32Cam& m_cam = esp32Cam::Instance();

	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(1);
		m_cam.takePicture();
		auto img = m_cam.getPicture();
		std::cout << " image length is : <" << (int)(img->len) << ">\n";
		m_cam.releasePicture();
	}
}

void ExampleCode::postImageToServer()
{
	std::cout << "Running a test : starting wifi ! \n ";
	WiFi_SAL_esp32 m_wifi{{Not_Visible::WIFI_SSID, Not_Visible::WIFI_PASS}};
	m_wifi.connect();

	esp32_http_sal m_http{Not_Visible::SERVER_IP, Not_Visible::SERVER_PORT};
	esp32Cam& m_cam = esp32Cam::Instance();

	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(1);
		if(m_cam.takePicture() != GE_OK)
		{
			Timeservice::wait_sec(5);
			m_cam.reboot_camera();
			continue;
		}
		auto img = m_cam.getPicture();
		m_http.post("/esp32_postImage", esp32_http_sal::content_type::IMAGE, img->buf, img->len);
		std::cout << " image length is : <" << (int)(img->len) << ">\n";
		m_cam.releasePicture();
	}
}