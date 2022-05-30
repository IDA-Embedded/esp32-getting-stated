/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
//#include "../../../SSP/main/components/Sensor_Handler/include/Sensor_Dummy_Handler.hpp"

#include "../../include/esp32_http_sal.hpp"
#include <iostream>

#include "CppUTest/TestHarness.h"

TEST_GROUP(HTTP_GRP)
{
	esp32_http_sal m_http{"10.212.13.90", 1880};
	void setup() {}
	void teardown()
	{
		// Uninit stuff
	}
};

// test init
TEST(HTTP_GRP, post)
{
	auto err = m_http.post("/esp32_postTest", esp32_http_sal::content_type::IMAGE, "{image}");
	CHECK_EQUAL(GE_OK, err);
}
