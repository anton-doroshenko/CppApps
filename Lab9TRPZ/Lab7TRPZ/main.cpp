#include <iostream>
#include "Solver.h"
#include <math.h>
#include <regex>
#include <stdlib.h>
#include "gtest\gtest.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int returnValue = RUN_ALL_TESTS();
	std::cin.get();
	return returnValue;
}