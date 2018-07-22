/***********************************************************************
* Module:  Hr_manager.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:57:48 PM
* Purpose: Declaration of the class Hr_manager
***********************************************************************/
#include <iostream>
#include <vector>
#if !defined(__UML_Class_Diagram_1_Hr_manager_h)
#define __UML_Class_Diagram_1_Hr_manager_h

class Candidate;

class Hr_manager
{
public:
	//constructors
	Hr_manager() : name("Name") {}
	Hr_manager(std::string name) : name(name) {}
	Hr_manager(Hr_manager &sHr_manager) : name(sHr_manager.name) {}

	//destructor
	~Hr_manager() {}

	////////////////////////////////////////
	std::vector<std::string> prepareVacancyList(int max, int cur);

	void chooseCandidates(std::vector<std::string> list);
	////////////////////////////////////////

	//getters
	std::string  Hr_manager::getName(void) const
	{
		return name;
	}

	//void setName(std::string n);

	std::vector<Candidate*> candidate;

protected:
private:
	const std::string name;
};

#endif