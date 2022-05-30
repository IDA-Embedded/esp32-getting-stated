/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */

//#include "../../include/Ping_API.hpp"

#include "../../include/WiFiBase.hpp"
#include "../../include/WiFi_SAL_esp32.hpp"
#include <iostream>

#include "CppUTest/TestHarness.h"

class MOCK_WIFI final : public WiFiBase
{
  private:
	/* data */
  public:
	MOCK_WIFI(/* args */) : WiFiBase("TEST_SSID", "TEST_PWD"){};
	~MOCK_WIFI(){};
	general_err_t connect() override
	{
		return GE_OK;
	}
	general_err_t disconnect() override
	{
		return GE_OK;
	}
};

TEST_GROUP(WiFiV2_GRP){void setup(){

} void teardown(){
	// Uninit stuff

}};

// test init
TEST(WiFiV2_GRP, init)
{
	MOCK_WIFI m_wifi;
	LONGS_EQUAL(2 * sizeof(std::string) + 8, sizeof(m_wifi));
}
// test init
TEST(WiFiV2_GRP, init_esp32)
{
	WiFi_SAL_esp32 m_wifi{"TEST_SSID", "TEST_PWD"};
	LONGS_EQUAL(2 * sizeof(std::string) + 24, sizeof(m_wifi));
}