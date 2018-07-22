/***********************************************************************
* Module:  Technical_manager.h
* Author:  Anton
* Modified: Monday, November 7, 2016 7:09:04 PM
* Purpose: Declaration of the class Technical_manager
***********************************************************************/
#include <iostream>
#include <vector>
#if !defined(__UML_Class_Diagram_1_Technical_manager_h)
#define __UML_Class_Diagram_1_Technical_manager_h

class Interview;
class Test;

class Technical_manager
{
public:
	Technical_manager();
	Technical_manager(std::string name, int rLevel, int cLevel);
	Technical_manager(Technical_manager &sTechnical_manager);
	Technical_manager(std::string str);
	~Technical_manager();
	void prepareTest(void);
	void checkTest(void);
	void holdingInterview(void);
	void get(void);
	void set(void);

	std::vector<Test*> test;
	std::vector<Interview*> interview;

protected:
private:
	std::string name;
	int requirementLevel;
	int commutabilityLevel;

};

#endif