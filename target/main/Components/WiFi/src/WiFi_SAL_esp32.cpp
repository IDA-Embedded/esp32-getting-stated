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
 *  \file       WiFi_SAL_esp32.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2022
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/WiFi_SAL_esp32.hpp"

//#define DEBUG // default uncommeted

static const char* LOG_TAG = "WiFi_SAL_esp32";

static int s_retry_num = 0;
constexpr int MAXIMUM_RETRY = 10;

static bool WIFI_CONNECTION_SUCCESS = false;
static bool WIFI_CONNECTION_FAIL = false;

WiFi_SAL_esp32::WiFi_SAL_esp32(const std::string& ssid, const std::string& pwd,
							   const max_power_t& wifi_power)
	: WiFiBase(ssid, pwd), m_wifi_power{wifi_enum_to_power(wifi_power)}
{
#ifdef __ESP32__
	// Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);
#endif
}

WiFi_SAL_esp32::WiFi_SAL_esp32(const wifi_conf_t& config)
	: WiFiBase(config.ssid, config.password), m_wifi_power{wifi_enum_to_power(
												  WiFi_SAL_esp32::max_power_t::MAX)}
{
#ifdef __ESP32__
	// Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);
#endif
}

WiFi_SAL_esp32::~WiFi_SAL_esp32() {}

int8_t WiFi_SAL_esp32::wifi_enum_to_power(const max_power_t& wifi_power)
{
	switch(wifi_power)
	{
		case max_power_t::MIN:
			return 8;

		case max_power_t::MEDIUM:
			return 50;
		case max_power_t::MAX:
			return 80;

		default:
			return 80;
	}
}

general_err_t WiFi_SAL_esp32::connect()
{
#ifdef DEBUG
	std::cout << " >> WiFi_SAL_esp32::connect >> \n";
#endif
	// do magic
#ifdef __ESP32__
	ESP_ERROR_CHECK(esp_netif_init());

	ESP_ERROR_CHECK(esp_event_loop_create_default());
	esp_netif_create_default_wifi_sta();

	m_cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK(esp_wifi_init(&m_cfg));

	ESP_ERROR_CHECK(esp_event_handler_instance_register(
		WIFI_EVENT, ESP_EVENT_ANY_ID, &WiFi_SAL_esp32::event_handler, NULL, &instance_any_id));
	ESP_ERROR_CHECK(esp_event_handler_instance_register(
		IP_EVENT, IP_EVENT_STA_GOT_IP, &WiFi_SAL_esp32::event_handler, NULL, &instance_got_ip));

	wifi_config_t wifi_config{};

	::memcpy(wifi_config.sta.ssid, m_ssid.data(), m_ssid.size());
	::memcpy(wifi_config.sta.password, m_pwd.data(), m_pwd.size());
	wifi_config.sta.scan_method = WIFI_ALL_CHANNEL_SCAN;
	wifi_config.sta.bssid_set = false;
	wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
	wifi_config.sta.pmf_cfg.capable = true;
	wifi_config.sta.pmf_cfg.required = false;

	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
	std::cout << " start WiFi .. \n";
	ESP_ERROR_CHECK(esp_wifi_start());
	ESP_ERROR_CHECK(esp_wifi_set_max_tx_power(m_wifi_power));

#endif

	while(!WIFI_CONNECTION_SUCCESS and !WIFI_CONNECTION_FAIL)
	{
		std::cout << "waiting for wifi ... \n";
		Timeservice::wait_sec(1);
	}
	if(WIFI_CONNECTION_SUCCESS)
	{
		std::cout << " we have sucessfully connected to wifi! \n";
#ifdef __ESP32__
		std::cout << "wifi info : \n";
		wifi_ap_record_t ap_info;
		esp_wifi_sta_get_ap_info(&ap_info);

		std::cout << " RSSI valus for <" << m_ssid << "> is : " << (int)ap_info.rssi << "\n";
#endif
		return GE_OK;
	}
	else
	{
		std::cout << "we failed to connect to wifi ... \n";
		return GE_FAIL;
	}

#ifdef DEBUG
	std::cout << " << WiFi_SAL_esp32::connect << \n";
#endif

	return GE_OK;
}

general_err_t WiFi_SAL_esp32::disconnect()
{
#ifdef DEBUG
	std::cout << " >> WiFi_SAL_esp32::disconnect >> \n";
#endif
	// do magic

#ifdef DEBUG
	std::cout << " << WiFi_SAL_esp32::disconnect << \n";
#endif

	return GE_OK;
}

void WiFi_SAL_esp32::event_handler(void* arg, esp_event_base_t event_base, int32_t event_id,
								   void* event_data)
{
	std::cout << "recieved an event! \n";
#ifdef __ESP32__
	if(event_base == WIFI_EVENT)
	{
		std::cout << "The event is WiFi and id is {" << (int)event_id << " } \n";
	}
	else
	{
		std::cout << "The event was no a wifi event... \n";
	}

	if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
	{
		std::cout << " event is : WIFI_EVENT_STA_START ... starting wifi \n";
		esp_wifi_connect();
	}
	else if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
	{
		std::cout << " event is : WIFI_EVENT_STA_DISCONNECTED ... retrying to connect \n";
		WIFI_CONNECTION_SUCCESS = false;

		if(s_retry_num < MAXIMUM_RETRY)
		{
			esp_wifi_connect();
			s_retry_num++;
		}
		else
		{
			std::cout << " could not connect to wifi ... \n";
			WIFI_CONNECTION_FAIL = true;
		}
	}
	else if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
	{
		std::cout << " event is : WIFI_EVENT_STA_CONNECTED ... WiFI connected! \n";
	}
	else if(event_base == WIFI_EVENT && event_id == IP_EVENT_STA_GOT_IP)
	{
		std::cout << " event is : IP_EVENT_STA_GOT_IP ... Got IP! \n";
		ip_event_got_ip_t* event = (ip_event_got_ip_t*)event_data;
		ESP_LOGI(LOG_TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
		s_retry_num = 0;
		WIFI_CONNECTION_SUCCESS = true;
		WIFI_CONNECTION_FAIL = false;
	}
	else if(event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
	{
		ip_event_got_ip_t* event = (ip_event_got_ip_t*)event_data;
		ESP_LOGI(LOG_TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
		s_retry_num = 0;
		WIFI_CONNECTION_SUCCESS = true;
		WIFI_CONNECTION_FAIL = false;
	}
#endif
}