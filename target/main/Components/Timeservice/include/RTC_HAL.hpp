/*
 * HAL.hpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_
#define COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  HAL.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, HAL.hpp, is designed as:
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

#ifdef __ESP32__
#include "esp_sntp.h"
#endif

#include <ctime>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class RTC_HAL
{
  public:
	RTC_HAL() = default;
	~RTC_HAL() = default;
	static auto sntp_update() -> general_err_t;

  private:
};

#endif /* COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_ */
