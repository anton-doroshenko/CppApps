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
	Test();
	Test(std::string type, bool result);
	Test(Test &sTest);
	Test(std::string str);

	//destructor
	~Test();

	//getters
	std::string getType(void);
	std::vector<std::string> getQuestions(void);

	//setters
	void setType(std::string t);
	void setResult(bool r);
	void setQuestions(std::vector<std::string>);

	//predicate
	bool successOfPassing(void);

protected:
private:
	std::string type;
	bool result;
	std::vector<std::string> questions;//remake
};

#endif