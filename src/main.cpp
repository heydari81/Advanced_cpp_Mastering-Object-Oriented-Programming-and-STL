#include <gtest/gtest.h>

#include <iostream>

#include "message.h"
#include "server.h"
#include "user.h"

int main(int argc, char **argv) {
	if (false)	// make false to run unit-tests
	{
		// std::time_t result = std::time(nullptr);
		// auto time = std::asctime(std::localtime(&result));
		// std::cout << time << std::endl;

	} else {
		::testing::InitGoogleTest(&argc, argv);
		std::cout << "RUNNING TESTS ..." << std::endl;
		int ret{RUN_ALL_TESTS()};
		if (!ret)
			std::cout << "<<<SUCCESS>>>" << std::endl;
		else
			std::cout << "FAILED" << std::endl;
	}
	return 0;
}