/***********************************************************************
* Module:  Interview.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:37 PM
* Purpose: Implementation of the class Interview
***********************************************************************/
#include <vector>
#include <string>
#include "Interview.h"
#include "Technical_manager.h"

std::ostream &operator<< (std::ostream &stream, Interview interview)
{
	stream << "result of passing: " << (interview.result ? "passed" : "failed\n");
	return stream;
}
//Interview::Interview():
//	result(false)
//{
//	//std::cout << "Interview was created (default)" << std::endl;
//}
//
//Interview::Interview(bool result):
//	result(result)
//{
//	//std::cout << "Interview was created (inicialisation)" << std::endl;
//}
//
//Interview::Interview(Interview &sInterview):
//	result(sInterview.result)
//{
//	//std::cout << "Interview was created (copy)" << std::endl;
//}
//
//Interview::Interview(std::string str):
//	result(atoi(str.c_str()))
//{
//	//result = ;
//	//std::cout << "Interivew was created (transform)" << std::endl;
//}
//
//Interview::~Interview()
//{
//	//std::cout << "Interview was destroyed" << std::endl;
//	//std::cout << std::endl;
//}
////////////////////////////////////////////////////////////////////////
// Name:       Interview::get()
// Purpose:    Implementation of Interview::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//void Interview::setResult(bool r)
//{
//	result = r;
//}
//
//bool Interview::successOfPassing(void)
//{
//	return result;
//}