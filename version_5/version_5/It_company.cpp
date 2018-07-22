/***********************************************************************
* Module:  It_company.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 6:55:11 PM
* Purpose: Implementation of the class It_company
***********************************************************************/
#include <vector>
#include <string>
#include <map>

#include "Technical_manager.h"
#include "Hr_manager.h"
#include "It_company.h"
#include "Candidate.h"
#include "Test.h"

const int It_company::maxValueOfWorkers = 3;

//It_company::It_company() :
//	technical_manager(1),
//	hr_manager(1),
//	name("NAME"),
//	vacancyList(1, "vacancy")
//{
//	std::cout << "IT-company was created (default)" << std::endl;
//}
//It_company::It_company(std::string name, std::vector<std::string> vacancies):
//	technical_manager(1),
//	hr_manager(1),
//	name(name),
//	vacancyList(vacancies)
//{
//	//std::cout << "IT-company was created (inicialisation)" << std::endl;
//}

//It_company::It_company(It_company &sIt_company):
//	technical_manager(1),
//	hr_manager(1),
//	name(sIt_company.name),
//	vacancyList(sIt_company.vacancyList)
//{
//	//std::cout << "IT-company was created (copy)" << std::endl;
//}

//It_company::It_company(std::string str) :
//	technical_manager(1),
//	hr_manager(1),
//	name(str.substr(0, 6)),
//	vacancyList(1, str.substr(6))
//{
//	//name = str.substr(0, 6);
//	/*for (int i = 0; i < str.substr(6).size() / 7; i++)
//	{
//	int ind = 6 + 7 * i;
//	vacancyList.push_back(str.substr((ind), 7));
//	}*/
//	//std::cout << "IT-company was created (transform)" << std::endl;
//}

//It_company::~It_company()
//{
//	//std::cout << "IT-company was destroyed" << std::endl;
//	//std::cout << std::endl;
//}
////////////////////////////////////////////////////////////////////////
// Name:       It_company::get()
// Purpose:    Implementation of It_company::get()
// Return:     void
////////////////////////////////////////////////////////////////////////
//
//std::string It_company::getName(void)
//{
//	return name;
//}

//std::vector<std::string> It_company::getVacList(void)
//{
//	return vacancyList;
//	/*for (int i = 0; i < vacancyList.size(); i++)
//	{
//		std::cout << vacancyList[i] << std::endl;
//	}*/
//}
////////////////////////////////////////////////////////////////////////
// Name:       It_company::set()
// Purpose:    Implementation of It_company::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

//void It_company::setName(std::string n)
//{
//	name = n;
//}

void It_company::setVacList(std::vector<std::string> vl)
{
	for (int i = 0; i < vl.size(); i++)
	{
		vacancyList.push_back(vl[i]);
	}
}

//iterator
void It_company::companyWorking()
{
	std::vector<std::vector<std::string>> allAnswers;

	std::multimap<int, int> candIndex;

	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			preparingVacanciesAndTests();
			/*vacancyList = hr_manager[0].prepareVacancyList(3, 2);
			for (int l = 0; l < technical_manager.size(); l++)
			{
			technical_manager[l].prepareTest(vacancyList);
			}*/
		}
		if (i == 1)
		{
			choosingCandidates();
			/*for (int m = 0; m < hr_manager.size(); m++)
			{
			hr_manager[m].chooseCandidates(vacancyList);
			}*/
		}
		if (i == 0 || i == 2 || i == 4)
		{
			candidateWorking(i, allAnswers, candIndex);
			//for (int j = 0; j < hr_manager.size(); j++)
			//{
			//	for (int k = 0; k < hr_manager[j].candidate.size(); k++)
			//	{
			//		/*answ = */
			//		std::vector<std::string> answ;
			//		std::vector<std::string> questions;
			//		if (this->hr_manager[k].candidate[j]->state == "review")
			//		{
			//			questions = getTechManForWork()->getTestForCandidate(hr_manager[j].candidate[k]->resume.getCompetence())->questions;
			//		}
			//		hr_manager[j].candidate[k]->getWork(i + 1, /*getTechManForWork()->getTestForCandidate(hr_manager[j].candidate[k]->resume.getCompetence()).*/questions, &answ);
			//		if (!answ.empty())
			//		{
			//			candIndex.insert(std::pair<int, int>(j, k));
			//			allAnswers.push_back(answ);
			//		}
			//	}
			//}
		}
		if (i == 3)
		{
			testing(allAnswers, candIndex);
			/*for (int q = 0; q < allAnswers.size(); q++)
			{
			hr_manager[candIndex.begin()->first].candidate[candIndex.begin()->second]->state = getTechManForWork()->checkTest(allAnswers[q]);
			candIndex.erase(candIndex.begin());
			}
			allAnswers.clear();*/
		}
		if (i == 4)
		{
			interview();
			/*for (int n = 0; n < hr_manager.size(); n++)
			{
			for (int p = 0; p < hr_manager[n].candidate.size(); p++)
			{
			if (hr_manager[n].candidate[p]->state == "interview")
			{
			hr_manager[n].candidate[p]->state = getTechManForWork()->holdingInterview(hr_manager[n].candidate[p]->getComLevel(), hr_manager[n].candidate[p]->getWorLevel(), hr_manager[n].candidate[p]->name);
			}
			}
			}*/
		}
	}
	std::cout << "///////////////" << std::endl;
	std::cout << "/// Results ///" << std::endl;
	std::cout << "///////////////" << std::endl;
	if (hr_manager[0].candidate[0]->getState() == "")
	{
		std::cout << "For this candidate there is not vacancies in company" << std::endl;
	}
	if (hr_manager[0].candidate[0]->getState() == "FailTest")
	{
		std::cout << "Candidate can`t take test" << std::endl;
	}
	if (hr_manager[0].candidate[0]->getState() == "Fail")
	{
		std::cout << "Candidate can`t pass interview" << std::endl;
	}
	if (hr_manager[0].candidate[0]->getState() == "GetWork")
	{
		std::cout << "Candidate get work!" << std::endl;
	}
}

//utilities
Technical_manager* It_company::getTechManForWork()
{
	for (int i = 0; i < technical_manager.size(); i++)
	{
		if (technical_manager[i].getState() == "free")
		{
			technical_manager[i].setState("busy");
			return &technical_manager[i];
		}
	}
	return &technical_manager[0];//TODO: make random
}

void It_company::preparingVacanciesAndTests()
{
	std::cout << "...HR-manager create vacancy list...\n" << std::endl;
	vacancyList = hr_manager[0].prepareVacancyList(getMaxValueOfWorkers(), getCurValueOfWorkers());
	for (int l = 0; l < technical_manager.size(); l++)
	{
		std::cout << "...Technical manager prepare tests...\n" << std::endl;
		technical_manager[l].prepareTest(vacancyList);
	}
}

void It_company::choosingCandidates()
{
	for (int m = 0; m < hr_manager.size(); m++)
	{
		std::cout << "...HR-manager choose candidates...\n" << std::endl;
		hr_manager[m].chooseCandidates(vacancyList);
	}
}

void It_company::candidateWorking(int time, std::vector<std::vector<std::string>>& allAnswers, std::multimap<int, int>& candIndex)
{
	for (int j = 0; j < hr_manager.size(); j++)
	{
		for (int k = 0; k < hr_manager[j].candidate.size(); k++)
		{
			/*answ = */
			std::vector<std::string> answ;
			std::vector<std::string> questions;
			if (this->hr_manager[k].candidate[j]->getState() == "review")
			{
				questions = getTechManForWork()->getTestForCandidate(hr_manager[j].candidate[k]->resume.getCompetence())->getQuestions();
			}
			hr_manager[j].candidate[k]->getWork(time + 1, /*getTechManForWork()->getTestForCandidate(hr_manager[j].candidate[k]->resume.getCompetence()).*/questions, &answ);
			if (!answ.empty())
			{
				candIndex.insert(std::pair<int, int>(j, k));
				allAnswers.push_back(answ);
			}
		}
	}
}

void It_company::testing(std::vector<std::vector<std::string>>& allAnswers, std::multimap<int, int>& candIndex)
{
	for (int q = 0; q < allAnswers.size(); q++)
	{
		std::cout << "...Technical manager check test...\n" << std::endl;
		hr_manager[candIndex.begin()->first].candidate[candIndex.begin()->second]->setState(getTechManForWork()->checkTest(allAnswers[q]));
		candIndex.erase(candIndex.begin());
	}
	allAnswers.clear();
}

void It_company::interview()
{
	for (int n = 0; n < hr_manager.size(); n++)
	{
		for (int p = 0; p < hr_manager[n].candidate.size(); p++)
		{
			if (hr_manager[n].candidate[p]->getState() == "interview")
			{
				std::cout << "...Technical manager holding interview...\n" << std::endl;
				hr_manager[n].candidate[p]->setState(getTechManForWork()->holdingInterview(hr_manager[n].candidate[p]->getComLevel(), hr_manager[n].candidate[p]->getWorLevel(), hr_manager[n].candidate[p]->getName()));
			}
		}
	}
}

std::ostream &operator<< (std::ostream &stream, It_company itcompany)
{
	stream << " ---------- \n" << "|IT-COMPANY|\n ---------- \n" << "name: " << itcompany.name << "\nVACANCIES:\n";
	for (int i = 0; i < itcompany.vacancyList.size(); i++)
	{
		stream << " " << i + 1 << ". " << itcompany.vacancyList[i] << "\n";
	}
	return stream;
}

It_company& It_company::operator++ ()
{
	this->curValueOfWorkers = this->curValueOfWorkers + 1;
	return *this;
}