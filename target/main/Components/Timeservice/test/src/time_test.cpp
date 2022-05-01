/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
//#include "../../../SSP/main/components/Sensor_Handler/include/Sensor_Dummy_Handler.hpp"
#include "../../../../Utility/utils/include/utils.h"
#include "../../include/Timeservice.hpp"
#include <iostream>
#include <sys/time.h>

#include "CppUTest/TestHarness.h"

TEST_GROUP(TIME_GRP){void setup(){

} void teardown(){
	// Uninit stuff

}};

// test init
TEST(TIME_GRP, test_date)
{
	// CHECK(basic_utils::is_even(3));
	std::cout << "current date test_date : " << Timeservice::getCurrentDate() << "\n";
}

// test init
TEST(TIME_GRP, test_date2)
{
	timeval tp;
	gettimeofday(&tp, NULL);
	std::cout << "current date test_date2 : " << Timeservice::getCurrentDate(tp) << "\n";
}

// test init
TEST(TIME_GRP, test_date_convert)
{
	timeval tp;
	gettimeofday(&tp, NULL);
	auto time = Timeservice::getTimeNow();

	LONGS_EQUAL(time, Timeservice::convertTimevalToTime(tp));
}

// test init
IGNORE_TEST(TIME_GRP, test_date_convert_multi)
{
	for(size_t i = 0; i < 100; i++)
	{
		timeval tp;
		gettimeofday(&tp, NULL);
		auto time = Timeservice::getTimeNow();

		LONGS_EQUAL(time, Timeservice::convertTimevalToTime(tp));
		Timeservice::wait_ms(126);
	}
}

// test init
TEST(TIME_GRP, test_date_convert_test2)
{
	timeval tp;
	gettimeofday(&tp, NULL);

	auto time = Timeservice::convertTimevalToTime(tp);
	timeval tval;
	tval.tv_sec = time / 1000;
	tval.tv_usec = (time % 1000) * 1000;

	// get the millisec part

	tm* time_now = gmtime(&tval.tv_sec);
	char buffer[80];
	strftime(buffer, 80, "'%Y-%m-%dT%H:%M:%S", time_now);

	char currentTime[84] = "";
	sprintf(currentTime, "%s.%ldZ'", buffer, (tval.tv_usec));
	std::cout << "time : " << currentTime << "\n";
}

// test init
TEST(TIME_GRP, get_yymmdd_test)
{
	std::cout << "Todays date is :" << Timeservice::getYearMonthDay() << "\n";
}
