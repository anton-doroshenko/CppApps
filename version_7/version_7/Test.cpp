/***********************************************************************
* Module:  Test.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:01 PM
* Purpose: Implementation of the class Test
***********************************************************************/
#include <vector>
#include <string>
#include "Test.h"

std::ostream &operator<< (std::ostream &stream, Test test)
{
	stream << "type: " << test.type << "\nresult of passing: " << (test.result ? "passed" : "failed\n");
	return stream;
}
//Test::Test():
//	type("type"),
//	result(false)
//{
//	//std::cout << "Test was created (dafault)" << std::endl;
//}
//
//Test::Test(std::string type, bool result):
//	type(type),
//	result(result)
//{
//	//std::cout << "Test was created (inicialisation)" << std::endl;
//}
//
//Test::Test(Test &sTest):
//	type(sTest.type),
//	result(sTest.result)
//{
//	//std::cout << "Test was created (copy)" << std::endl;
//}
//
//Test::Test(std::string str):
//	type(str.substr(0, 4)),
//	result(atoi(str.substr(4, 1).c_str()))
//{
//	//type = ;
//	//result = ;
//	//std::cout << "Test was created (transform)" << std::endl;
//}
//
//Test::~Test()
//{
//	//std::cout << "Test was destroyed" << std::endl;
//	//std::cout << std::endl;
//}
////////////////////////////////////////////////////////////////////////
// Name:       Test::get()
// Purpose:    Implementation of Test::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//std::string Test::getType(void)
//{
//	return type;
//}


////////////////////////////////////////////////////////////////////////
// Name:       Test::set()
// Purpose:    Implementation of Test::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//void Test::setType(std::string t)
//{
//	type = t;
//}
//
//void Test::setResult(bool r)
//{
//	result = r;
//}
//
//bool Test::successOfPassing(void)
//{
//	return result;
//}