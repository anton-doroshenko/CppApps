/***********************************************************************
* Module:  Hr_manager.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:57:48 PM
* Purpose: Declaration of the class Hr_manager
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Hr_manager_h)
#define __UML_Class_Diagram_1_Hr_manager_h

class Candidate;

class Hr_manager
{
public:
	Hr_manager();
	void prepareVacancyList(void);
	void chooseCandidates(void);
	void get(void);
	void set(void);

	Candidate** candidate;

protected:
private:
	std::string name;


};

#endif