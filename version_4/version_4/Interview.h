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
	Interview() : result(false), whoPass("") {}
	Interview(bool result) : result(result), whoPass("") {}
	Interview(Interview &sInterview) : result(sInterview.result), whoPass(sInterview.whoPass) {}
	//Interview(std::string str) : result(atoi(str.c_str())) {}

	//destructor
	~Interview() {}

	//getters
	std::string getWhoPass(void)
	{
		return whoPass;
	}

	//setters
	void setResult(bool r)
	{
		result = r;
	}

	void setWhoPass(std::string name)
	{
		whoPass = name;
	}

	//predicate
	bool successOfPassing(void)
	{
		return result;
	}

protected:
private:
	bool result;
	std::string whoPass;
};

#endif