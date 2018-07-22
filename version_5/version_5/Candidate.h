/***********************************************************************
* Module:  Candidate.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:50:33 PM
* Purpose: Declaration of the class Candidate
***********************************************************************/
#include <iostream>
#include "Resume.h"
#if !defined(__UML_Class_Diagram_1_Candidate_h)
#define __UML_Class_Diagram_1_Candidate_h

class Resume;

class Candidate
{
public:
	//constructors
	Candidate() : commutabilityLevel(1), worryingLevel(2), work(false), name("Anderson"), state(""), resume() {}
	Candidate(int cLevel, int wLevel, bool work) : commutabilityLevel(cLevel), worryingLevel(wLevel), work(work), name("Anderson"), state(""), resume() {}
	Candidate(Candidate &sCandidate) : commutabilityLevel(sCandidate.commutabilityLevel), worryingLevel(sCandidate.worryingLevel), work(sCandidate.work), name(sCandidate.name), state(sCandidate.state), resume() {}
	//Candidate(std::string str) : resume(), commutabilityLevel(atoi(str.substr(0, 2).c_str())), worryingLevel(atoi(str.substr(2, 2).c_str())), work(atoi(str.substr(4, 1).c_str())) {}

	//destructor
	~Candidate() {}

	//////////////////////////////
	void prepareResume(void);
	std::vector<std::string> takeTest(std::vector<std::string> quetions);
	void passInterview(void);
	void getWork(int time, std::vector<std::string> quetions, std::vector<std::string> *answ);
	//////////////////////////////

	//getters
	int getComLevel(void) const
	{
		return commutabilityLevel;
	}
	int getWorLevel(void) const
	{
		return worryingLevel;
	}
	std::string getName(void) const
	{
		return name;
	}
	std::string getState(void) const
	{
		return state;
	}

	//setters
	void setComLevel(int c)
	{
		commutabilityLevel = c;
	}

	void setWorLevel(int w)
	{
		worryingLevel = w;
	}

	void setWork(bool w)
	{
		work = w;
	}

	void setState(std::string st)
	{
		state = st;
	}

	//predicate
	bool existenceOfWork(void)
	{
		return work;
	}

	//operators
	friend std::ostream &operator<< (std::ostream &stream, Candidate candidate);

	bool operator !()const
	{
		return !work;
	}

	Resume resume;
protected:
private:
	int commutabilityLevel;
	int worryingLevel;
	bool work;
	const std::string name;
	std::string state;//TODO: make private with getters

	//utilities
	std::string answerQuestion(std::string dificult);

};

#endif