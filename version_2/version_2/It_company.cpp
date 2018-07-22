/***********************************************************************
* Module:  It_company.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 6:55:11 PM
* Purpose: Implementation of the class It_company
***********************************************************************/
#include <vector>
#include <string>

#include "Technical_manager.h"
#include "Hr_manager.h"
#include "It_company.h"

It_company::It_company() :
	technical_manager(1),
	hr_manager(1),
	name("NAME"),
	vacancyList(1, "vacancy")
{
	std::cout << "IT-company was created (default)" << std::endl;
}
It_company::It_company(std::string name, std::vector<std::string> vacancies):
	technical_manager(1),
	hr_manager(1),
	name(name),
	vacancyList(vacancies)
{
	std::cout << "IT-company was created (inicialisation)" << std::endl;
}

It_company::It_company(It_company &sIt_company):
	technical_manager(1),
	hr_manager(1),
	name(sIt_company.name),
	vacancyList(sIt_company.vacancyList)
{
	std::cout << "IT-company was created (copy)" << std::endl;
}

It_company::It_company(std::string str):	
	technical_manager(1),
	hr_manager(1),
	name(str.substr(0, 6)),
	vacancyList(1, str.substr(6))
{
	//name = str.substr(0, 6);
	/*for (int i = 0; i < str.substr(6).size() / 7; i++)
	{
		int ind = 6 + 7 * i;
		vacancyList.push_back(str.substr((ind), 7));
	}*/
	std::cout << "IT-company was created (transform)" << std::endl;
}

It_company::~It_company()
{
	std::cout << "IT-company was destroyed" << std::endl;
	std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       It_company::get()
// Purpose:    Implementation of It_company::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

void It_company::get(void)
{
	// TODO : implement
}
////////////////////////////////////////////////////////////////////////
// Name:       It_company::set()
// Purpose:    Implementation of It_company::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

void It_company::set(void)
{
	// TODO : implement
}