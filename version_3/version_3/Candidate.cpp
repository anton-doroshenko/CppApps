/***********************************************************************
* Module:  Candidate.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 6:50:33 PM
* Purpose: Implementation of the class Candidate
***********************************************************************/

#include <vector>
#include <string>
#include "Resume.h"
#include "Candidate.h"

//constructors
Candidate::Candidate() :
	commutabilityLevel(1),
	worryingLevel(2),
	work(false),
	name("Anderson"),
	state(""),
	resume()
{
	//std::cout << "Candidate was created (default)" << std::endl;
}

Candidate::Candidate(int cLevel, int wLevel, bool work, std::string name, std::string state):
	commutabilityLevel(cLevel),
	worryingLevel(wLevel),
	work(work),
	name(name),
	state(state),
	resume()
{
	//resume = new Resume;
	//std::cout << "Candidate was created (inicialisation)" << std::endl;
}

Candidate::Candidate(Candidate &sCandidate):
	commutabilityLevel(sCandidate.commutabilityLevel),
	worryingLevel(sCandidate.worryingLevel),
	work(sCandidate.work),
	name(sCandidate.name),
	state(sCandidate.state),
	resume()
{
	//resume = new Resume;
	//std::cout << "Candidate was created (copy)" << std::endl;
}

Candidate::Candidate(std::string str):
	resume(),
	commutabilityLevel(atoi(str.substr(0, 2).c_str())),
	worryingLevel(atoi(str.substr(2, 2).c_str())),
	work(atoi(str.substr(4, 1).c_str())),
	name("Anderson"),
	state("")
{
	//commutabilityLevel = atoi(str.substr(0, 2).c_str());
	//worryingLevel = atoi(str.substr(2, 2).c_str());
	//work = atoi(str.substr(4, 1).c_str());
	//std::cout << "Candidate was ceated (transform)" << std::endl;
}

//destructors
Candidate::~Candidate()
{
	//delete resume;
	//std::cout << "Candidate was destroyed" << std::endl;
	//std::cout << std::endl;
	//std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Candidate::prepareResume()
// Purpose:    Implementation of Candidate::prepareResume()
// Return:     void
////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////
void Candidate::prepareResume(void)
{
	/*std::cout << "Set aim: ";
	std::string aim;
	std::cin >> aim;
	resume.setAim(aim);*/
	std::cout << "Set Competence: ";
	std::string comp;
	std::cin >> comp;
	resume.setCompetence(comp);
	/*std::cout << "Set Courses: ";
	std::vector<std::string> c;
	while (true)
	{
		char answer = 'y';
		std::cout << "Add course: ";
		std::string cour;
		std::cin >> cour;
		c.push_back(cour);
		std::cout << "Do you want to continue adding courses? (y/n)" << std::endl;
		std::cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setCourses(c);*/
	std::cout << "Set Education: ";
	std::string e;
	std::cin >> e;
	resume.setEducation(e);
	std::cout << "Set Languages: ";
	/*std::vector<std::string> l;
	while (true)
	{
		char answer = 'y';
		std::cout << "Add clanguage: ";
		std::string lang;
		std::cin >> lang;
		l.push_back(lang);
		std::cout << "Do you want to continue adding languages? (y/n)" << std::endl;
		std::cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setLanguages(l);*/
	std::cout << "Set Experience: ";
	int exp;
	std::cin >> exp;
	resume.setExperience(exp);
	/*std::cout << "Set Email: ";
	std::string mail;
	std::cin >> mail;
	resume.setEmail(mail);
	std::cout << "Set Phones: ";
	std::vector<int> p;
	while (true)
	{
		char answer = 'y';
		std::cout << "Add phone: ";
		int num;
		std::cin >> num;
		p.push_back(num);
		std::cout << "Do you want to continue adding phones? (y/n)" << std::endl;
		std::cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setPhones(p);*/
	/*std::cout << "Set Address: ";
	std::string ad;
	std::cin >> ad;
	resume.setAddress(ad);
	resume.setName(name);
	std::cout << "Set birthday: ";
	std::string b;
	std::cin >> b;
	resume.setBirthday(b);*/
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::takeTest()
// Purpose:    Implementation of Candidate::takeTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

std::vector<std::string> Candidate::takeTest(std::vector<std::string> listOfQuations)
{
	std::vector<std::string> listOfAnswers;
	state = "testing";
	for (int i = 0; i < listOfQuations.size(); i++)
	{
		//std::cout <<  << std::endl;
		listOfAnswers.push_back(answerQuestion(listOfQuations[i]));
	}
	return listOfAnswers;
	// TODO : implement
}

std::string Candidate::answerQuestion(std::string dificult)
{
	// TODO : implement, stoi(dificult) is wrong
	int result = this->resume.getExperience() / (1 * this->worryingLevel);
	return result != 0 ? "done" : "fail";//TODO: make better
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::passInterview()
// Purpose:    Implementation of Candidate::passInterview()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::passInterview(void)
{
	// TODO : implement
	state = "interview";
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::get()
// Purpose:    Implementation of Candidate::get()
// Return:     void
////////////////////////////////////////////////////////////////////////


void Candidate::getWork(int time, std::vector<std::string> quetions, std::vector<std::string> *answ)//TODO: make void (answ make as atribute probably ptr)
{
	//std::vector<std::string> answ;
	if (time == 1)
	{
		std::cout << "...Candidate create resume...\n" << std::endl;
		prepareResume();
	}
	if (time == 3)
	{
		std::cout << "...Candidate take test...\n" << std::endl;
		*answ = takeTest(quetions);
	}
	if (time == 5 && state == "DoneTest")
	{
		std::cout << "...Candidate pass interview...\n" << std::endl;
		passInterview();
	}
	//return *answ;
	// TODO : implement
}
/////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::get()
// Purpose:    Implementation of Candidate::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//getters
int Candidate::getComLevel(void)
{
	return commutabilityLevel;
}

int Candidate::getWorLevel(void)
{
	return worryingLevel;
}

std::string Candidate::getName(void)
{
	return name;
}

std::string Candidate::getState(void)
{
	return state;
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::set()
// Purpose:    Implementation of Candidate::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//setters
void Candidate::setComLevel(int c)
{
	commutabilityLevel = c;
}

void Candidate::setWorLevel(int w)
{
	worryingLevel = w;
}

void Candidate::setWork(bool w)
{
	work = w;
}

void Candidate::setName(std::string n)
{
	name = n;
}

void Candidate::setState(std::string st)
{
	state = st;
}

//predicate
bool Candidate::existenceOfWork(void)
{
	return work;
}