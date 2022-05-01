/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
//#include "../../../SSP/main/components/Sensor_Handler/include/Sensor_Dummy_Handler.hpp"

#include <iostream>

#include "CppUTest/TestHarness.h"

TEST_GROUP(GE_GRP){void setup(){

} void teardown(){
	// Uninit stuff

}};

// test init
TEST(GE_GRP, init)
{
	CHECK(true);
}
