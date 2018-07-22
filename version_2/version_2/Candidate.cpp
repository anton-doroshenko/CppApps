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
#include "Technical_manager.h"

Candidate::Candidate() :
	commutabilityLevel(1),
	worryingLevel(2),
	work(false),
	resume()
{
	std::cout << "Candidate was created (default)" << std::endl;
}

Candidate::Candidate(int cLevel, int wLevel, bool work):
	commutabilityLevel(cLevel),
	worryingLevel(wLevel),
	work(work),
	resume()
{
	//resume = new Resume;
	std::cout << "Candidate was created (inicialisation)" << std::endl;
}

Candidate::Candidate(Candidate &sCandidate):
	commutabilityLevel(sCandidate.commutabilityLevel),
	worryingLevel(sCandidate.worryingLevel),
	work(sCandidate.work),
	resume()
{
	//resume = new Resume;
	std::cout << "Candidate was created (copy)" << std::endl;
}

Candidate::Candidate(std::string str):
	resume(),
	commutabilityLevel(atoi(str.substr(0, 2).c_str())),
	worryingLevel(atoi(str.substr(2, 2).c_str())),
	work(atoi(str.substr(4, 1).c_str()))
{
	//commutabilityLevel = atoi(str.substr(0, 2).c_str());
	//worryingLevel = atoi(str.substr(2, 2).c_str());
	//work = atoi(str.substr(4, 1).c_str());
	std::cout << "Candidate was ceated (transform)" << std::endl;
}

Candidate::~Candidate()
{
	//delete resume;
	std::cout << "Candidate was destroyed" << std::endl;
	std::cout << std::endl;
	//std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////
// Name:       Candidate::prepareResume()
// Purpose:    Implementation of Candidate::prepareResume()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::prepareResume(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::takeTest()
// Purpose:    Implementation of Candidate::takeTest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::takeTest(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::passInterview()
// Purpose:    Implementation of Candidate::passInterview()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::passInterview(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::get()
// Purpose:    Implementation of Candidate::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::getWork(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::get()
// Purpose:    Implementation of Candidate::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::get(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Candidate::set()
// Purpose:    Implementation of Candidate::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Candidate::set(void)
{
	// TODO : implement
}