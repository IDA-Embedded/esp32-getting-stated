/*
 * General_Error.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef BPS_INCLUDE_GENERAL_ERROR_HPP_
#define BPS_INCLUDE_GENERAL_ERROR_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  General_Error.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, General_Error.hpp, is designed as:
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
 |  	Link:[ ], May 22, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], May 22, 2020
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

#include <string>

#include <iostream>
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

enum general_err_t
{
	GE_OK = 0,
	GE_FAIL,
	GE_OUT_OF_RANGE,
	GE_OVERFLOW,
	GE_UNDERFLOW,
	GE_NULLPTR,
	GE_TIMEOUT,
	GE_NO_DATA,
	GE_UPPER_BOUNDERY,
	GE_LOWER_BOUNDERY,
	GE_NOT_INITIALIZED,
	GE_CLOSED,
	GE_OPEN,
	GE_EMPTY,
	GE_SEMAPHORE_NOT_TAKEN,
	GE_VIRTUAL_SENSOR,
	GE_NOT_CONNECTED,
	GE_PROTOCOL_FAILED
};

enum general_resp_t
{
	GR_NO_RESPONSE = 0,
	GR_REBOOT,
	GR_EXIT
};

/**
 * @class basic error class used for detecting failures in the system
 */
class General_Error
{
  public:
	//   static const char* errorToString(general_err_t errCode);
	static std::string errorToString(general_err_t errCode);
	static const char* responseToString(general_resp_t respCode);
	static void printError(general_err_t errCode);
	static void printError(const std::string& LOGTAG, general_err_t errCode);
	static bool check_error(const general_err_t& errcode, const std::string& msg,
							const general_err_t& expected = GE_OK);

  private:
};

#endif /* BPS_INCLUDE_GENERAL_ERROR_HPP_ */
