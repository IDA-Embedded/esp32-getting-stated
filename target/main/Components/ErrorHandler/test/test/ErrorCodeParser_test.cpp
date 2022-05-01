/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
// #include "../../include/esp32Cam.hpp" // example of include
#define __WITH_MOCK_TIME__ (1)

#include "../../include/ErrorCodeParser.hpp"
#include <iostream>

// ------------- INCLUDE ABOVE ----------------
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(TEMP_GRP){

	
	
	void setup(){

	}
	void teardown(){
	// Uninit stuff
	}
};
// clang-format on

// test init
TEST(TEMP_GRP, init)
{
	std::string str =
		"105," + std::to_string(Timeservice::getTimeNow()) + "," + "13" + "," + "TEST";
	STRCMP_EQUAL(
		str.c_str(),
		friend_ErrorCodeParser::toString(db_id::DOGFEEDER_ERROR_CODE, GE_OVERFLOW, "TEST").c_str());
}
