/***********************************************************************
* Module:  Test.h
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:01 PM
* Purpose: Declaration of the class Test
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Test_h)
#define __UML_Class_Diagram_1_Test_h

class Test
{
public:
	Test();
	void get(void);
	void set(void);

protected:
private:
	std::string type;
	bool result;


};

#endif