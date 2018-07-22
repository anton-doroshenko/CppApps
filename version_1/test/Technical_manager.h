/***********************************************************************
* Module:  Technical_manager.h
* Author:  Anton
* Modified: Monday, November 7, 2016 7:09:04 PM
* Purpose: Declaration of the class Technical_manager
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Technical_manager_h)
#define __UML_Class_Diagram_1_Technical_manager_h

class Interview;
class Test;

class Technical_manager
{
public:
	Technical_manager();
	void prepareTest(void);
	void checkTest(void);
	void holdingInterview(void);
	void get(void);
	void set(void);

	Interview** interview;
	Test** test;

protected:
private:
	std::string name;
	int requirementLevel;
	int commutabilityLevel;


};

#endif