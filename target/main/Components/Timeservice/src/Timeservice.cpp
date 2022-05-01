/*
 * Timeservice.cpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */

/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       Timeservice.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/Timeservice.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char* LOG_TAG = "Timeservice";
#endif

general_err_t Timeservice::initialize_sntp()
{
#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> Timeservice::refresh_time >> ");
#endif
	// Executable code:
	return RTC_HAL::sntp_update();

#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< Timeservice::refresh_time << ");
#endif

	return GE_OK;
}
general_err_t Timeservice::wait_sec(size_t sec_to_wait)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> Timeservice::wait_sec >> ");
#endif
	// Executable code:
#ifdef __ESP32__
	vTaskDelay((sec_to_wait * 1000UL) / portTICK_PERIOD_MS);
#else
	std::this_thread::sleep_for(std::chrono::seconds(sec_to_wait));
#endif

#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< Timeservice::wait_sec << ");
#endif

	return GE_OK;
}
general_err_t Timeservice::wait_ms(size_t ms_to_wait)
{
#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> Timeservice::wait_poll_ms >> ");
#endif
// Executable code:
#ifdef __ESP32__
	vTaskDelay(ms_to_wait / portTICK_PERIOD_MS);
#else
	std::this_thread::sleep_for(std::chrono::milliseconds(ms_to_wait));
#endif

#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< Timeservice::wait_poll_ms << ");
#endif

	return GE_OK;
}
/**
 * @brief  return the time in ms
 *
 * @attention
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
uint64_t Timeservice::getTimeNow() noexcept
{
#ifdef __UNITTEST__
#ifdef __WITH_MOCK_TIME__ // can be used to overwrite the timestamp in unit tests
	return 1000UL;
#endif
#endif
	return std::chrono::duration_cast<std::chrono::milliseconds>(
			   std::chrono::system_clock::now().time_since_epoch())
		.count();
}

/**
 * @brief  return the time in µs
 *
 * @attention
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
uint64_t Timeservice::getTimeInUsNow() noexcept
{
	return std::chrono::duration_cast<std::chrono::microseconds>(
			   std::chrono::system_clock::now().time_since_epoch())
		.count();
}

general_err_t Timeservice::wait_untill_ms(const uint64_t& start_time, const uint64_t& ms_to_wait)
{
#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> Timeservice::wait_untill_ms >> ");
#endif
	// Executable code:
	uint64_t time_now = getTimeNow();
	if(start_time > time_now)
	{
		// we have to please the watchdog even with an error
		wait_ms(ms_to_wait);
		return GE_FAIL;
	}
	auto time_diff = time_now - start_time;
	if(time_diff > ms_to_wait)
	{
#ifdef __DEBUG__
		std::cout << "time_diff : " << (int)time_diff << " ms to wait : " << (int)ms_to_wait
				  << "\n";
#endif

		// we have to please the watchdog even with an error
		wait_ms(ms_to_wait);
		return GE_TIMEOUT;
	}

	wait_ms(ms_to_wait - time_diff);
#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< Timeservice::wait_untill_ms << ");
#endif

	return GE_OK;
}

std::string Timeservice::getCurrentDate() noexcept
{
	time_t now = time(nullptr);
	struct tm tstruct
	{
	};
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M_%S", &tstruct);

	const auto ms = Timeservice::getTimeNow() % 1000;
	std::string str = buf;
	str.append("_");
	str.append(std::to_string(ms));

	return str;
}

std::string Timeservice::getCurrentDate(const timeval& time) noexcept
{
	time_t now = time.tv_sec;
	struct tm tstruct
	{
	};
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M_%S", &tstruct);

	const auto ms = Timeservice::getTimeNow() % 1000;
	std::string str = buf;
	str.append("_");
	str.append(std::to_string(ms));

	return str;
}

uint64_t Timeservice::convertTimevalToTime(const timeval& time) noexcept
{
	if(time.tv_usec > 1000)
	{
		// add the milisec part
		return (time.tv_sec * 1000) + (time.tv_usec / 1000);
	}
	return time.tv_sec * 1000;
}

std::string Timeservice::getYearMonthDay() noexcept
{
	time_t now = time(nullptr);
	struct tm tstruct
	{
	};
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d", &tstruct);
	std::string str = buf;
	return str;
}
