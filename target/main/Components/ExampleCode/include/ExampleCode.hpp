#ifndef target_main_Components_ExampleCode_include_ExampleCode_hpp
#define target_main_Components_ExampleCode_include_ExampleCode_hpp
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  ExampleCode.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 	      :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, ExampleCode.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*----------------- DEFAULT INCLUDE -------------------------------------------*/

#include <BASIC.hpp>
#include <General_Error.hpp>

/*-----------------------------------------------------------------------------*/
#include <Timeservice.hpp>
#include <WiFi_SAL_esp32.hpp>
#include <esp32Cam.hpp>
#include <esp32_http_sal.hpp>
#include <iostream>

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
namespace Not_Visible
{
const std::string WIFI_SSID = "IDA Embedded Workshop";
const std::string WIFI_PASS = "abcd1234";
const std::string SERVER_IP = "192.168.0.197";
const uint16_t SERVER_PORT = 1880;
} // namespace Not_Visible

class ExampleCode
{
  public:
	static void startWifi();
	static void sendHttpText(const std::string& text = "test string");
	static void captureImage();
	static void postImageToServer();

  private:
};

#endif /*target_main_Components_ExampleCode_include_ExampleCode_hpp*/