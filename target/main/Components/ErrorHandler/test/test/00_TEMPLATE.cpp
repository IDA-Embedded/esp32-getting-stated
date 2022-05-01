/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
// #include "../../include/esp32Cam.hpp" // example of include
#include <iostream>

// ------------- INCLUDE ABOVE ----------------
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(TEMP_GRP){
	esp32Cam m_cam;
	
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
	FAIL("FAIL ME!");
}
