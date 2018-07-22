/***********************************************************************
* Module:  Hr_manager.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:57:48 PM
* Purpose: Declaration of the class Hr_manager
***********************************************************************/

#if !defined(__UML_Class_Diagram_1_Hr_manager_h)
#define __UML_Class_Diagram_1_Hr_manager_h

#include <iostream>
#include <vector>
#include "Worker.h"

class Candidate;

class Hr_manager : public Worker
{
public:
	//constructors
	Hr_manager() : Worker()/*: name("Name")*/ {}
	/*Hr_manager(std::string name) : name(name) {}
	Hr_manager(Hr_manager &sHr_manager) : name(sHr_manager.name) {}*/

	//destructor
	~Hr_manager() {}

	////////////////////////////////////////
	std::vector<std::string> prepareVacancyList(int max, int cur);

	void chooseCandidates(std::vector<std::string> list);
	////////////////////////////////////////

	//getters

	/*std::string  Hr_manager::getName(void) const
	{
		return name;
	}*/

	//operators
	friend std::ostream &operator<< (std::ostream &stream, Hr_manager hrmanager);

	Hr_manager operator + (Candidate &right);
	/*{
		this->candidate.push_back(&right);
		return *this;
	}*/

	void showPosition()
	{
		std::cout << "HR-manager" << std::endl;
	}

	std::vector<Candidate*> candidate;

protected:
private:
	//const std::string name;
};

#endif