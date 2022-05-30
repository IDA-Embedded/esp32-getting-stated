/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <Timeservice.hpp>
#include <WiFi_SAL_esp32.hpp>
#include <esp32Cam.hpp>
#include <esp32_http_sal.hpp>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
void app_main(void);
// Your prototype or Definition
#ifdef __cplusplus
}
#endif

void startWiFi()
{
	std::cout << "Running a test : starting wifi ! \n ";
	WiFi_SAL_esp32 m_wifi{{WIFI_SSID_LOCAL, WIFI_PWD_LOCAL}};
	m_wifi.connect();

	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(5);
	}
}

void sendHTTP()
{
	std::cout << "Running a test : starting wifi ! \n ";
	WiFi_SAL_esp32 m_wifi{{WIFI_SSID_LOCAL, WIFI_PWD_LOCAL}};
	m_wifi.connect();

	esp32_http_sal m_http{SERVER_IP, SERVER_PORT};
	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(5);
		m_http.post("/esp32_test", esp32_http_sal::content_type::TEXT, "test string");
	}
}

void captureImage()
{
	esp32Cam& m_cam = esp32Cam::Instance();

	for(;;)
	{
		std::cout << "looping ...\n ";
		Timeservice::wait_sec(1);
		m_cam.takePicture();
		auto img = m_cam.getPicture();
		std::cout << " image length is : <" << (int)img->len << ">\n";
		m_cam.releasePicture();
	}
}

void postImageToServer()
{
	WiFi_SAL_esp32 m_wifi{{WIFI_SSID_LOCAL, WIFI_PWD_LOCAL}};
	m_wifi.connect();
	esp32_http_sal m_http{SERVER_IP, SERVER_PORT};
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
		std::cout << " image length is : <" << (int)img->len << ">\n";
		m_cam.releasePicture();
	}
}

void app_main(void)
{
	postImageToServer();
}
