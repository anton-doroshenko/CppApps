/***********************************************************************
* Module:  Test.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:01 PM
* Purpose: Implementation of the class Test
***********************************************************************/
#include <vector>
#include <string>
#include "Test.h"

//constructors
Test::Test():
	type("type"),
	result(false),
	questions()
{
	//std::cout << "Test was created (dafault)" << std::endl;
}

Test::Test(std::string type, bool result):
	type(type),
	result(result),
	questions()
{
	//std::cout << "Test was created (inicialisation)" << std::endl;
}

Test::Test(Test &sTest):
	type(sTest.type),
	result(sTest.result),
	questions()
{
	//std::cout << "Test was created (copy)" << std::endl;
}

Test::Test(std::string str):
	type(str.substr(0, 4)),
	result(atoi(str.substr(4, 1).c_str())),
	questions()
{
	//type = ;
	//result = ;
	//std::cout << "Test was created (transform)" << std::endl;
}


//destructor
Test::~Test()
{
	//std::cout << "Test was destroyed" << std::endl;
	//std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Test::get()
// Purpose:    Implementation of Test::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//getters
std::string Test::getType(void)
{
	return type;
}

std::vector<std::string> Test::getQuestions(void)
{
	return questions;
}


////////////////////////////////////////////////////////////////////////
// Name:       Test::set()
// Purpose:    Implementation of Test::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//setters
void Test::setType(std::string t)
{
	type = t;
}

void Test::setResult(bool r)
{
	result = r;
}

void Test::setQuestions(std::vector<std::string> q)
{
	questions = q;
}

//predicate
bool Test::successOfPassing(void)
{
	return result;
}