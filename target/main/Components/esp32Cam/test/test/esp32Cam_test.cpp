/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */

#include "../../include/esp32Cam.hpp"
#include <iostream>

#include "CppUTest/TestHarness.h"
// clang-format off
TEST_GROUP(ESP32CAM_GRP){
	//esp32Cam m_cam;
	esp32Cam& m_cam = esp32Cam::Instance();
	void setup(){

	}
	void teardown(){
	// Uninit stuff
	m_cam.releasePicture();
	}
};
// clang-format on

// test init
TEST(ESP32CAM_GRP, init)
{
	auto err = m_cam.takePicture();
	CHECK_EQUAL(GE_OK, err);
}
// test init
TEST(ESP32CAM_GRP, initx2_fail)
{
	auto err = m_cam.takePicture();
	err = m_cam.takePicture(); // this should fail, because we have not release the image
	CHECK_EQUAL(GE_NOT_READY, err);
}

// test init
TEST(ESP32CAM_GRP, singleton_initx2_fail)
{
	esp32Cam& m_cam1 = esp32Cam::Instance();
	esp32Cam& m_cam2 = esp32Cam::Instance();
	auto err = m_cam1.takePicture();
	CHECK_EQUAL(GE_OK, err);
	err = m_cam2.takePicture();
	CHECK_EQUAL(GE_NOT_READY, err);
}

// test init
TEST(ESP32CAM_GRP, singleton_initx2_release_OK)
{
	esp32Cam& m_cam1 = esp32Cam::Instance();
	esp32Cam& m_cam2 = esp32Cam::Instance();
	esp32Cam& m_cam3 = esp32Cam::Instance();
	auto err = m_cam1.takePicture();
	CHECK_EQUAL(GE_OK, err);
	err = m_cam2.takePicture();
	CHECK_EQUAL(GE_NOT_READY, err);
	err = m_cam3.releasePicture();
	CHECK_EQUAL(GE_OK, err);
	err = m_cam2.takePicture();
	CHECK_EQUAL(GE_OK, err);
}

// test init
TEST(ESP32CAM_GRP, release_fail)
{
	auto err = m_cam.releasePicture();
	CHECK_EQUAL(GE_NO_DATA, err);
}

// test init
TEST(ESP32CAM_GRP, release_OK)
{
	auto err = m_cam.releasePicture();
	CHECK_EQUAL(GE_NO_DATA, err);
	for(size_t i = 0; i < 10; i++)
	{
		auto err = m_cam.takePicture();
		CHECK_EQUAL(GE_OK, err);
		err = m_cam.releasePicture();
		CHECK_EQUAL(GE_OK, err);
	}
}

// test init
TEST(ESP32CAM_GRP, get_img_fail)
{
	auto img = m_cam.getPicture();
	CHECK_EQUAL(nullptr, img);
}