/*
 * RTC_HAL.cpp
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
 *  \file       RTC_HAL.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/RTC_HAL.hpp"

//#define DEBUG (1)
#ifdef DEBUG
static const char* LOG_TAG = "RTC_HAL";
#endif

auto RTC_HAL::sntp_update() -> general_err_t
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> RTC_HAL::sntp_update >> ");
#endif
	// Executable code:
#ifdef __ESP32__
	sntp_setoperatingmode(SNTP_OPMODE_POLL);
	sntp_setservername(0, "pool.ntp.org");
	sntp_init();

	// wait for time to be set
	time_t now = 0;
	struct tm timeinfo = {0};
	int retry = 0;
	const int retry_count = 10;
	while(sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && ++retry < retry_count)
	{
		vTaskDelay(2000 / portTICK_PERIOD_MS);
	}
	if(retry >= retry_count)
	{
		return GE_FAIL;
	}
	time(&now);
	localtime_r(&now, &timeinfo);

#endif

#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< RTC_HAL::sntp_update << ");
#endif

	return GE_OK;
}
