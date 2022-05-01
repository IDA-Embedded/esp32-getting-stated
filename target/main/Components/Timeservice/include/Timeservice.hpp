/*
 * Timeservice.hpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_TIMESERVICE_INCLUDE_TIMESERVICE_HPP_
#define COMPONENTS_TIMESERVICE_INCLUDE_TIMESERVICE_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Timeservice.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Timeservice.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Sep 6, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Sep 6, 2020
 |
 |		Brief:
 |
 |
 |
 |
 |
  +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*----------------- DEFAULT INCLUDE -------------------------------------------*/
#include <BASIC.hpp>
#include <General_Error.hpp>
/*-----------------------------------------------------------------------------*/

#include <RTC_HAL.hpp>
#include <chrono>
#include <iomanip>
#include <thread>
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Timeservice
{
  public:
	Timeservice() = default;
	~Timeservice() = default;
	static uint64_t getTimeNow() noexcept;
	static uint64_t getTimeInUsNow() noexcept;
	static general_err_t wait_ms(size_t ms_to_wait);
	static general_err_t wait_sec(size_t sec_to_wait);
	static general_err_t wait_untill_ms(const uint64_t& start_time, const uint64_t& ms_to_wait);
	static general_err_t initialize_sntp();
	static std::string getCurrentDate() noexcept;
	static std::string getCurrentDate(const timeval& time) noexcept;
	//@breif converter function to go from one timedomain to another
	static uint64_t convertTimevalToTime(const timeval& time) noexcept;
	/**
	 * function to return the year, month and day
	 * in the formate "YYYYMMDD" as an example : "20211102"
	 * @usage this function can be used for folder structure if we want to save images to a given
	 * location with seperation for each new day.
	 */
	static std::string getYearMonthDay() noexcept;

  private:
};

#endif /* COMPONENTS_TIMESERVICE_INCLUDE_TIMESERVICE_HPP_ */
