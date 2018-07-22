/***********************************************************************
* Module:  Hr_manager.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 6:57:48 PM
* Purpose: Implementation of the class Hr_manager
***********************************************************************/
#include <vector>
#include <string>
#include "Candidate.h"
#include "Hr_manager.h"
#include "Technical_manager.h"

//constructors
Hr_manager::Hr_manager():
	name("Name")
{
	//std::cout << "HR-manager was created (default)" << std::endl;
}

Hr_manager::Hr_manager(std::string name) :
	name(name)
{
	//std::cout << "HR-manager was created (inicialisation)" << std::endl;
}

Hr_manager::Hr_manager(Hr_manager &sHr_manager):
	name(sHr_manager.name)
{
	//std::cout << "HR-manager was created (copy)" << std::endl;
}

//destructor
Hr_manager::~Hr_manager()
{
	//std::cout << "HR- manager was destroyed" << std::endl;
	//std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::prepareVacancyList()
// Purpose:    Implementation of Hr_manager::prepareVacancyList()
// Return:     void
////////////////////////////////////////////////////////////////////////

std::vector<std::string> Hr_manager::prepareVacancyList(int max, int cur)//can be better
{
	std::vector<std::string> list;
	for (int i = 0; i < (max - cur); i++)
	{
		std::string vac;
		std::cin >> vac;
		list.push_back(vac);
	}
	return list;
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::chooseCandidates()
// Purpose:    Implementation of Hr_manager::chooseCandidates()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Hr_manager::chooseCandidates(std::vector<std::string> list)
{
	for (int i = 0; i < candidate.size(); i++)
	{
		for (int j = 0; j < list.size(); j++)
		{
			if (candidate[i]->resume.getCompetence() == list[j])
			{
				candidate[i]->setState("review");
				break;
			}
		}
	}
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::get()
// Purpose:    Implementation of Hr_manager::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//getters
std::string  Hr_manager::getName(void)
{
	return name;
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::set()
// Purpose:    Implementation of Hr_manager::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//setters
void Hr_manager::setName(std::string n)
{
	name = n;
}