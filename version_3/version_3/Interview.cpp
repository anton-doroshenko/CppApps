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

//constructors
Interview::Interview():
	result(false),
	whoPass("")
{
	//std::cout << "Interview was created (default)" << std::endl;
}

Interview::Interview(bool result):
	result(result),
	whoPass("")
{
	//std::cout << "Interview was created (inicialisation)" << std::endl;
}

Interview::Interview(Interview &sInterview):
	result(sInterview.result),
	whoPass(sInterview.whoPass)
{
	//std::cout << "Interview was created (copy)" << std::endl;
}

Interview::Interview(std::string str):
	result(atoi(str.c_str())),
	whoPass("")
{
	//result = ;
	//std::cout << "Interivew was created (transform)" << std::endl;
}

//destructor
Interview::~Interview()
{
	//std::cout << "Interview was destroyed" << std::endl;
	//std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Interview::get()
// Purpose:    Implementation of Interview::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//setters
void Interview::setResult(bool r)
{
	result = r;
}

void Interview::setWhoPass(std::string name)
{
	whoPass = name;
}

//getters
bool Interview::successOfPassing(void)
{
	return result;
}

std::string Interview::getWhoPass(void)
{
	return whoPass;
}