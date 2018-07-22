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
	Candidate();
	Candidate(int cLevel, int wLevel, bool work);
	Candidate(Candidate &sCandidate);
	Candidate(std::string str);
	~Candidate();
	void prepareResume(void);
	void takeTest(void);
	void passInterview(void);
	void getWork(void);
	void get(void);
	void set(void);

protected:
private:
	Resume resume;
	int commutabilityLevel;
	int worryingLevel;
	bool work;

};

#endif