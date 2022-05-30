
#include "CppUTest/CommandLineTestRunner.h"

#include "CppUTest/TestHarness.h"

int main(int argc, char** argv)
{
	// @ATTENTION: OpenCV is deallocating the memory after end-of-scope,
	// but OpenCV do not own the memory, therfor will there be a deallocation on non memory error.
	// we are therefore ignoring
	MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
#if 0 // test different groups
	char *arg[10];

	arg[1] = "-v";
	//arg[2] = "-sg";
	//arg[3] = "CAM_HAL_GRP";
	//arg[3] = "CAM_LEPTON_GRP";
	//arg[3] = "IMAGE_GRP";
	return CommandLineTestRunner::RunAllTests(2, arg);
#endif
	// it is expected that the creat function makes some static allocation, which is removed after
	// the unit test main functin is done evaluation -> therefor it is false memory leak detections

	return CommandLineTestRunner::RunAllTests(argc, argv);
}
