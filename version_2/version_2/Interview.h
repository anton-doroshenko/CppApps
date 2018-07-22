/***********************************************************************
* Module:  Interview.h
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:37 PM
* Purpose: Declaration of the class Interview
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Interview_h)
#define __UML_Class_Diagram_1_Interview_h

class Interview
{
public:
	Interview();
	Interview(bool result);
	Interview(Interview &sInterview);
	Interview(std::string str);
	~Interview();
	void get(void);

protected:
private:
	bool result;
};

#endif