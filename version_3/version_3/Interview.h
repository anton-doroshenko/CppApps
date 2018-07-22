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
	//constructors
	Interview();
	Interview(bool result);
	Interview(Interview &sInterview);
	Interview(std::string str);

	//destructor
	~Interview();

	//getters
	std::string getWhoPass(void);

	//setters
	void setResult(bool r);
	void setWhoPass(std::string name);

	//predicate
	bool successOfPassing(void);
protected:
private:
	bool result;
	std::string whoPass;//TODO: make private
};

#endif