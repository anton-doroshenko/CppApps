/***********************************************************************
* Module:  Test.h
* Author:  Anton
* Modified: Monday, November 7, 2016 7:14:01 PM
* Purpose: Declaration of the class Test
***********************************************************************/
#include <iostream>
#include <string>

#if !defined(__UML_Class_Diagram_1_Test_h)
#define __UML_Class_Diagram_1_Test_h

class Test
{
public:
	//constructors
	Test() : type("type"), result(false), questions() {}
	Test(std::string type, bool result) : type(type), result(result), questions() {}
	Test(Test &sTest) : type(sTest.type), result(sTest.result), questions(sTest.questions) {}
	//Test(std::string str) : type(str.substr(0, 4)), result(atoi(str.substr(4, 1).c_str())) {}

	//destructor
	~Test() {}

	//getters
	std::string Test::getType(void) const
	{
		return type;
	}
	std::vector<std::string> getQuestions(void) const
	{
		return questions;
	}

	//setters
	void setType(std::string t)
	{
		type = t;
	}
	void setResult(bool r)
	{
		result = r;
	}
	void setQuestions(std::vector<std::string> q)
	{
		questions = q;
	}

	//predicate
	bool successOfPassing(void)
	{
		return result;
	}

	//operators
	friend std::ostream &operator<< (std::ostream &stream, Test test);

	Test &operator+=(std::vector<std::string> const &que)
	{
		this->questions = que;
		return *this;
	}

protected:
private:
	std::string type;
	bool result;
	std::vector<std::string> questions;
};

#endif