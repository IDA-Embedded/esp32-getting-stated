#ifndef _COMPONENTS_PROTOCOLS_HTTP_INCLUDE_ESP32_SAL_HPP_
#define _COMPONENTS_PROTOCOLS_HTTP_INCLUDE_ESP32_SAL_HPP_
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  @file  esp32_sal.hpp
 |
 |  @author        :  Nikolaj Gliese Pedersen
 |  @email         :  <nikolajgliese@tutanota.com>
 |  @date		   : 2022-01-07
 |
 |  @brief  	   :  This class, esp32_sal.hpp, is designed as:
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

#include <array>
#include <iostream>
#ifdef __ESP32__
#include <esp_http_client.h>
#endif

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class esp32_http_sal
{
#ifdef __UNITTEST__
	friend class friend_esp32_sal;
#endif
  public:
	explicit esp32_http_sal(const std::string& server, const int& port = 80);
	~esp32_http_sal();
	/**
	 * @brief Call a basic GET function to the specified server
	 *
	 * @param api_call : specifed remote function, example "/get_status_of_something"
	 * @param [out] output : buffer for the recieved content payload
	 * @return general_err_t
	 */
	general_err_t get(const std::string& api_call, std::string& output);

	enum class content_type
	{
		IMAGE,
		TEXT

	};
	/**
	 * @brief Call a basic POST function to the specific server
	 *
	 * @param api_call : specifed remote function, example "/post_to_database"
	 * @param content : content of the payload
	 * @return general_err_t
	 */
	general_err_t post(const std::string& api_call, const content_type& type,
					   const std::string& content);
	/**
	 * @brief  Call a basic POST function to the specific server
	 *
	 * @param api_call : specifed remote function, example "/post_to_database"
	 * @param type     : speicify the package type
	 * @param content  : content of the payload
	 * @param content_length : length of the payload
	 * @return general_err_t
	 */
	general_err_t post(const std::string& api_call, const content_type& type,
					   const uint8_t* content, const size_t& content_length);

  private:
	std::string m_server;
	int m_port;

#ifdef __ESP32__
	esp_http_client_handle_t m_client;
	static esp_err_t _http_event_handle(esp_http_client_event_t* evt);

#endif
};

/*------------------------------------------------------------------------------+
 |   		 				 Unit Test Class               		                |
 +------------------------------------------------------------------------------*/

#ifdef __UNITTEST__
class friend_esp32_sal
{
  public:
	explicit friend_esp32_sal(esp32_http_sal* sensor) : m_sensor{sensor} {};
	~friend_esp32_sal();

  private:
	esp32_http_sal* m_sensor;
};
#endif

#endif //_COMPONENTS_PROTOCOLS_HTTP_INCLUDE_ESP32_SAL_HPP_