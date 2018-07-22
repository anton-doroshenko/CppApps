/***********************************************************************
* Module:  Candidate.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:50:33 PM
* Purpose: Declaration of the class Candidate
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Candidate_h)
#define __UML_Class_Diagram_1_Candidate_h

class Resume;

class Candidate
{
public:
	Candidate();
	void prepareResume(void);
	void takeTest(void);
	void passInterview(void);
	void get(void);
	void set(void);

	Resume** resume;

protected:
private:
	int commutabilityLevel;
	int worryingLevel;


};

#endif