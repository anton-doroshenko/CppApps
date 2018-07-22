/***********************************************************************
* Module:  It_company.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:55:11 PM
* Purpose: Declaration of the class It_company
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <map>

#if !defined(__UML_Class_Diagram_1_It_company_h)
#define __UML_Class_Diagram_1_It_company_h

class Technical_manager;
class Hr_manager;

class It_company
{
public:
	
	It_company();
	It_company(std::string name, std::vector<std::string> vacancies, int maxValueOfWorkers, int curValueOfWorkers);
	It_company(It_company &sIt_company);
	It_company(std::string str);
	~It_company();
	//getters
	std::string getName(void);
	std::vector<std::string> getVacList(void);
	int getMaxValueOfWorkers(void);
	int getCurValueOfWorkers(void);
	//setters
	void setName(std::string n);
	void setVacList(std::vector<std::string> vl);
	void setMaxValueOfWorkers(int max);
	void setCurValueOfWorkers(int cur);
	//iterator
	void companyWorking();
	
	std::vector<Technical_manager> technical_manager;
	std::vector<Hr_manager> hr_manager;
protected:
private:
	std::string name;
	std::vector<std::string> vacancyList;
	int maxValueOfWorkers;
	int curValueOfWorkers;

	//methods-utilities
	Technical_manager* getTechManForWork(void);
	void preparingVacanciesAndTests();
	void choosingCandidates();
	void candidateWorking(int time, std::vector<std::vector<std::string>>& allAnswers, std::multimap<int, int>& candIndex);
	void testing(std::vector<std::vector<std::string>>& allAnswers, std::multimap<int, int>& candIndex);
	void interview();
};

#endif