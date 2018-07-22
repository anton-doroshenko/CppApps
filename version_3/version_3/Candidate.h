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
	Candidate();
	Candidate(int cLevel, int wLevel, bool work, std::string name, std::string state);
	Candidate(Candidate &sCandidate);
	Candidate(std::string str);

	//destructor
	~Candidate();

	//////////////////////////////
	void prepareResume(void);
	std::vector<std::string> takeTest(std::vector<std::string> quetions);
	void passInterview(void); 
	void getWork(int time, std::vector<std::string> quetions, std::vector<std::string> *answ);
	//////////////////////////////

	//getters
	int getComLevel(void);
	int getWorLevel(void);
	std::string getName(void);
	std::string getState(void);

	//setters
	void setComLevel(int c);
	void setWorLevel(int w);
	void setWork(bool w);
	void setName(std::string n);
	void setState(std::string st);
	
	//predicate
	bool existenceOfWork(void);

	Resume resume;

protected:
private:
	int commutabilityLevel;
	int worryingLevel;
	bool work;
	std::string name;
	std::string state;

	//utilities
	std::string answerQuestion(std::string dificult);

};

#endif