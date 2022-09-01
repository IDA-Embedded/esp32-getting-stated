#ifndef Components_Connector_WiFi_v2_include_WiFi_SAL_esp32_hpp
#define Components_Connector_WiFi_v2_include_WiFi_SAL_esp32_hpp
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  WiFi_SAL_esp32.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 	      :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, WiFi_SAL_esp32.hpp, is designed as:
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
#include "WiFiBase.hpp"

#include <Timeservice.hpp>

#include <cstring>
#include <iostream>
#include <string>
#ifdef __ESP32__

#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#endif
/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/
#ifdef __UNITTEST__
#define esp_event_base_t int
#define esp_event_handler_instance_t int
#define wifi_init_config_t int
#endif

struct wifi_conf_t
{
	std::string ssid;
	std::string password;
};
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class WiFi_SAL_esp32 final : public WiFiBase
{
  public:
	enum class max_power_t : uint8_t
	{
		MIN,
		MEDIUM,
		MAX
	};
	WiFi_SAL_esp32(const wifi_conf_t& config);
	WiFi_SAL_esp32(const std::string& ssid, const std::string& pwd,
				   const max_power_t& wifi_power = max_power_t::MAX);
	virtual ~WiFi_SAL_esp32();
	general_err_t connect() override;
	general_err_t disconnect() override;

  private:
	esp_event_handler_instance_t instance_any_id; // initialized @ connect()
	esp_event_handler_instance_t instance_got_ip; // initialized @ connect()
	wifi_init_config_t m_cfg; // initialized @ connect()

	static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id,
							  void* event_data);
	int8_t wifi_enum_to_power(const max_power_t& wifi_power);

	WiFi_SAL_esp32& operator=(WiFi_SAL_esp32 const& rhs) = delete;
	WiFi_SAL_esp32(WiFi_SAL_esp32 const& src) = delete;
	int8_t m_wifi_power;
};

#endif /*Components_Connector_WiFi_v2_include_WiFi_SAL_esp32_hpp*/