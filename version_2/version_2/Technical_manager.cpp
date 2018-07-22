/***********************************************************************
* Module:  Technical_manager.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 7:09:04 PM
* Purpose: Implementation of the class Technical_manager
***********************************************************************/
#include <vector>
#include <string>
#include "Interview.h"
#include "Test.h"
#include "Technical_manager.h"

Technical_manager::Technical_manager():
	test(1, new Test),
	interview(1, new Interview),
	name("name"),
	requirementLevel(1),
	commutabilityLevel(1)
{
	/*for (int i = 0; i < 1; i++)
	{
		interview[i] = new Interview;
	}
	for (int i = 0; i < 1; i++)
	{
		test[i] = new Test;
	}*/
	std::cout << "Technical_manager was created (default)" << std::endl;
}
Technical_manager::Technical_manager(std::string name, int rLevel, int cLevel) :
	test(1, new Test),
	interview(1, new Interview),
	name(name),
	requirementLevel(rLevel),
	commutabilityLevel(cLevel)
{
	/*for (int i = 0; i < 1; i++)
	{
		interview[i] = new Interview;
	}
	for (int i = 0; i < 1; i++)
	{
		test[i] = new Test;
	}*/
	std::cout << "Technical_manager was created (inicialisation)" << std::endl;
}

Technical_manager::Technical_manager(Technical_manager &sTechnical_manager):
	test(1, new Test),
	interview(1, new Interview),
	name(sTechnical_manager.name),
	requirementLevel(sTechnical_manager.requirementLevel),
	commutabilityLevel(sTechnical_manager.commutabilityLevel)
{
	std::cout << "Technical_manager was created (copy)" << std::endl;
}

Technical_manager::Technical_manager(std::string str):
	test(1, new Test),
	interview(1, new Interview),
	name(str.substr(0, 5)),
	requirementLevel(atoi(str.substr(5, 2).c_str())),
	commutabilityLevel(atoi(str.substr(7, 2).c_str()))
{
	//name = ;
	//requirementLevel = ;
	//commutabilityLevel = ;
	std::cout << "Technical_manager was created (transform)" << std::endl;
}

Technical_manager::~Technical_manager()
{
	std::cout << "Technical manager was destroyed" << std::endl;
	std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::prepareTest()
// Purpose:    Implementation of Technical_manager::prepareTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::prepareTest(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::checkTest()
// Purpose:    Implementation of Technical_manager::checkTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::checkTest(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::holdingInterview()
// Purpose:    Implementation of Technical_manager::holdingInterview()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::holdingInterview(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::get()
// Purpose:    Implementation of Technical_manager::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::get(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::set()
// Purpose:    Implementation of Technical_manager::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::set(void)
{
	// TODO : implement
}