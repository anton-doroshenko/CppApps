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
	//constructors
	Technical_manager();
	Technical_manager(std::string name, int rLevel, int cLevel);
	Technical_manager(Technical_manager &sTechnical_manager);
	Technical_manager(std::string str);

	//destructor
	~Technical_manager();

	/////////////////////////////////////////////
	void prepareTest(std::vector<std::string> list);

	std::string checkTest(std::vector<std::string> listOfAnswers);

	std::string holdingInterview(int cLevel, int wLevel, std::string name);

	Test* getTestForCandidate(std::string competence);
	///////////////////////////////////////////////

	//getters
	std::string getName(void);
	int getReqLevel(void);
	int getComLevel(void);
	std::string getState(void);

	//setters
	void setName(std::string n);
	void setReqLevel(int r);
	void setComLevel(int c);
	void setState(std::string state);

	std::vector<Test*> test;
	std::vector<Interview*> interview;


protected:
private:
	std::string name;
	int requirementLevel;
	int commutabilityLevel;
	std::string state; // TODO: make private
};

#endif