/***********************************************************************
* Module:  Resume.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:25:26 PM
* Purpose: Declaration of the class Resume
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Resume_h)
#define __UML_Class_Diagram_1_Resume_h

class Resume
{
public:
	Resume();
	void set(void);
	void get(void);

protected:
private:
	std::string aim;
	std::string competence;
	std::vector<std::string> courses;
	std::string education;
	std::vector<std::string> languages;
	int experience;
	std::string email;
	std::vector<int> phoneNumbers;
	std::string address;
	std::string name;
	std::string birthday;


};

#endif