/***********************************************************************
* Module:  Technical_manager.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 7:09:04 PM
* Purpose: Implementation of the class Technical_manager
***********************************************************************/
#include <vector>
#include <string>
#include "Interview.h"
#include "Test.h"
#include "Technical_manager.h"

//constructors
Technical_manager::Technical_manager() :
	test(1, new Test),
	interview(1, new Interview),
	name("name"),
	requirementLevel(1),
	commutabilityLevel(1),
	state("free")
{
	/*for (int i = 0; i < 1; i++)
	{
	interview[i] = new Interview;
	}
	for (int i = 0; i < 1; i++)
	{
	test[i] = new Test;
	}*/
	//std::cout << "Technical_manager was created (default)" << std::endl;
}

Technical_manager::Technical_manager(std::string name, int rLevel, int cLevel) :
	test(1, new Test),
	interview(1, new Interview),
	name(name),
	requirementLevel(rLevel),
	commutabilityLevel(cLevel),
	state("free")
{
	/*for (int i = 0; i < 1; i++)
	{
	interview[i] = new Interview;
	}
	for (int i = 0; i < 1; i++)
	{
	test[i] = new Test;
	}*/
	//std::cout << "Technical_manager was created (inicialisation)" << std::endl;
}

Technical_manager::Technical_manager(Technical_manager &sTechnical_manager) :
	test(1, new Test),
	interview(1, new Interview),
	name(sTechnical_manager.name),
	requirementLevel(sTechnical_manager.requirementLevel),
	commutabilityLevel(sTechnical_manager.commutabilityLevel),
	state(sTechnical_manager.state)
{
	//std::cout << "Technical_manager was created (copy)" << std::endl;
}

Technical_manager::Technical_manager(std::string str) :
	test(1, new Test),
	interview(1, new Interview),
	name(str.substr(0, 5)),
	requirementLevel(atoi(str.substr(5, 2).c_str())),
	commutabilityLevel(atoi(str.substr(7, 2).c_str())),
	state("free")
{
	//name = ;
	//requirementLevel = ;
	//commutabilityLevel = ;
	//std::cout << "Technical_manager was created (transform)" << std::endl;
}

//destructor
Technical_manager::~Technical_manager()
{
	//std::cout << "Technical manager was destroyed" << std::endl;
	//std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::prepareTest()
// Purpose:    Implementation of Technical_manager::prepareTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Technical_manager::prepareTest(std::vector<std::string> list)
{
	int numOfQuations = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (test.empty() || i > 0)
		{
			test.push_back(new Test);
		}
		test[test.size() - 1]->setType(list[i]);
		std::cout << "Enter number of quastions" << std::endl;
		std::cin >> numOfQuations;
		std::vector<std::string> list;
		for (int j = 0; j < numOfQuations; j++)
		{
			std::string str;
			std::cout << "Enter dificulty of quastion" << std::endl;
			std::cin >> str;
			list.push_back(str);
		}
		test[test.size() - 1]->setQuestions(list);//TODO: get index of test with nacessary type
	}
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::checkTest()
// Purpose:    Implementation of Technical_manager::checkTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

std::string Technical_manager::checkTest(std::vector<std::string> listOfAnswers)
{
	// TODO : implement
	int amountOfcorrectAnsw = 0;
	for (int i = 0; i < listOfAnswers.size(); i++)
	{
		amountOfcorrectAnsw = listOfAnswers[i] == "done" ? amountOfcorrectAnsw + 1 : amountOfcorrectAnsw;
	}
	if ((float)amountOfcorrectAnsw / (float)listOfAnswers.size() >= 0.66)
	{
		return "DoneTest";
	}
	else
	{
		return "FailTest";
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::holdingInterview()
// Purpose:    Implementation of Technical_manager::holdingInterview()
// Return:     void
////////////////////////////////////////////////////////////////////////

std::string Technical_manager::holdingInterview(int cLevel, int wLevel, std::string name)//REMAKE!!!
{
	// TODO : implement
	if (interview.empty() || !interview[interview.size() - 1]->getWhoPass().empty())
	{
		interview.push_back(new Interview);
	}
	bool res = false;
	res = (cLevel * commutabilityLevel) / (wLevel * requirementLevel) != 0 ? true : false;
	interview[interview.size() - 1]->setResult(res);
	interview[interview.size() - 1]->setWhoPass(name);
	if (res == true)
	{
		return "getWork";
	}
	else
	{
		return "Fail";
	}
}

Test* Technical_manager::getTestForCandidate(std::string competence)
{
	for (int i = 0; i < test.size(); i++)
	{
		if (test[i]->getType() == competence)
		{
			return test[i];
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::get()
// Purpose:    Implementation of Technical_manager::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//getters
std::string Technical_manager::getName(void)
{
	return name;
}

int Technical_manager::getReqLevel(void)
{
	return requirementLevel;
}

int Technical_manager::getComLevel(void)
{
	return commutabilityLevel;
}

std::string Technical_manager::getState(void)
{
	return state;
}

////////////////////////////////////////////////////////////////////////
// Name:       Technical_manager::set()
// Purpose:    Implementation of Technical_manager::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//setters
void Technical_manager::setName(std::string n)
{
	name = n;
}

void Technical_manager::setReqLevel(int r)
{
	requirementLevel = r;
}

void Technical_manager::setComLevel(int c)
{
	commutabilityLevel = c;
}

void Technical_manager::setState(std::string s)
{
	state = s;
}