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

Hr_manager::Hr_manager():
	name("Name")
{
	std::cout << "HR-manager was created (default)" << std::endl;
}
Hr_manager::Hr_manager(std::string name) :
	name(name)
{
	std::cout << "HR-manager was created (inicialisation)" << std::endl;
}

Hr_manager::Hr_manager(Hr_manager &sHr_manager):
	name(sHr_manager.name)
{
	std::cout << "HR-manager was created (copy)" << std::endl;
}

Hr_manager::~Hr_manager()
{
	std::cout << "HR- manager was destroyed" << std::endl;
	std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::prepareVacancyList()
// Purpose:    Implementation of Hr_manager::prepareVacancyList()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Hr_manager::prepareVacancyList(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::chooseCandidates()
// Purpose:    Implementation of Hr_manager::chooseCandidates()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Hr_manager::chooseCandidates(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::get()
// Purpose:    Implementation of Hr_manager::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Hr_manager::get(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Hr_manager::set()
// Purpose:    Implementation of Hr_manager::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Hr_manager::set(void)
{
	// TODO : implement
}