
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
 *  \file       General_Error.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/General_Error.hpp"

#define DEBUG (1)
#ifdef DEBUG
static const char* LOG_TAG = "General_Error";
#endif
std::string General_Error::errorToString(general_err_t errCode)
{
	// #lizard forgives the complexity
	switch(errCode)
	{
		case GE_OK:
			return ("OK");
		case GE_FAIL:
			return ("FAIL");
		case GE_OUT_OF_RANGE:
			return ("GE_OUT_OF_RANGE");
		case GE_OVERFLOW:
			return ("GE_OVERFLOW");
		case GE_UNDERFLOW:
			return ("GE_UNDERFLOW");
		case GE_NULLPTR:
			return ("GE_NULLPTR");
		case GE_TIMEOUT:
			return ("GE_TIMEOUT");
		case GE_NO_DATA:
			return ("GE_NO_DATA");
		case GE_UPPER_BOUNDERY:
			return ("GE_UPPER_BOUNDERY");
		case GE_LOWER_BOUNDERY:
			return ("GE_LOWER_BOUNDERY");
		case GE_NOT_INITIALIZED:
			return ("GE_NOT_INITIALIZED");
		case GE_CLOSED:
			return ("GE_CLOSED");
		case GE_EMPTY:
			return ("GE_EMPTY");
		case GE_SEMAPHORE_NOT_TAKEN:
			return ("GE_SEMAPHORE_NOT_TAKEN");
		case GE_VIRTUAL_SENSOR:
			return ("GE_VIRTUAL_SENSOR");
		case GE_OPEN:
			return ("GE_OPEN");
		case GE_NOT_CONNECTED:
			return ("GE_NOT_CONNECTED");
		case GE_PROTOCOL_FAILED:
			return ("GE_PROTOCOL_FAILED");
		default:
			return ("UNKNOWN ERROR CODE");
	}
}

void General_Error::printError(general_err_t errCode)
{
	if(errCode == GE_OK)
	{
		return;
	}
#ifdef DISABLE_LOG_TO_OUTPUT
	return;
#endif
	std::cout << LOG_TAG << "ERROR :: " << errorToString(errCode) << "\n";
	return;
}

void General_Error::printError(const std::string& LOGTAG, general_err_t errCode)
{
	if(errCode == GE_OK)
	{
		return;
	}
#ifdef DISABLE_LOG_TO_OUTPUT
	return;
#endif
	std::cout << LOGTAG << " ERROR :: " << errorToString(errCode) << "\n";
	return;
}

bool General_Error::check_error(const general_err_t& err, const std::string& msg,
								const general_err_t& expected)
{
	if(err != expected)
	{
		std::cout << msg << "\n"
				  << "mismatch in expected error code:\n";
		std::cout << "got : " << errorToString(err) << " expected : " << errorToString(expected)
				  << "\n";
		return false;
	}
	return true;
}

const char* General_Error::responseToString(general_resp_t respCode)
{
	switch(respCode)
	{
		case GR_NO_RESPONSE:
			return ("NO RESPONSE");
		case GR_REBOOT:
			return ("REBOOT");
		case GR_EXIT:
			return ("EXIT");
		default:
			return ("UNKNOWN RESPONSE CODE");
	}
}
