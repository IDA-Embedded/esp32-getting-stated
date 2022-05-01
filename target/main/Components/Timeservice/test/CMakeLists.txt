#[[ 
We must always set the miminum required version
This will also explicit set the cmake behavior.
It is recommendend to use 3.17+ due to some changes (?)
]]
cmake_minimum_required(VERSION 3.18.4)

add_executable(${LIBNAME}_tests )

set(COSTUM_TEST_FILES ${COSTUM_TEST_FILES} "${LIBNAME}_tests;" CACHE STRING "avaliable build tests" FORCE)



target_include_directories(${LIBNAME}_tests PRIVATE mock test )
target_link_libraries(${LIBNAME}_tests PRIVATE  CppUTest CppUTestExt LibraryModule ${COSTUM_LIBRARIES})

###############################################################
#															  #
# 					USER CHANGE START						  #
#															  #
#	In the following the user needs to specify the test files #
#	in the "target_sources(  )" command.					  #
#	example of syntax: 										  #
#       target_sources(${LIBNAME}_tests PRIVATE test_main.cpp #
#       test/time_test.cpp  # <- test file					  #
#       )													  #
#															  #
###############################################################
target_sources(${LIBNAME}_tests PRIVATE test_main.cpp
test/time_test.cpp
)
###############################################################
#															  #
#					USER CHANGE END							  #
#															  #
###############################################################

add_test(NAME ${LIBNAME}.Test
	COMMAND ${LIBNAME}_tests
)



