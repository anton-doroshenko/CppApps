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
	//inline constructors and destructors
	It_company() : technical_manager(1), hr_manager(1), name("NAME"), vacancyList(1, "vacancy"), curValueOfWorkers(2) {}
	It_company(std::string name, std::vector<std::string> vacancies, int curValueOfWorkers) : technical_manager(1), hr_manager(1), name(name), vacancyList(vacancies), curValueOfWorkers(curValueOfWorkers) {}
	It_company(It_company &sIt_company) : technical_manager(1), hr_manager(1), name(sIt_company.name), vacancyList(sIt_company.vacancyList), curValueOfWorkers(sIt_company.curValueOfWorkers){}
	//It_company(std::string str) : technical_manager(1), hr_manager(1), name(str.substr(0, 6)), vacancyList(1, str.substr(6)) {}
	~It_company() {}

	//const inline getters
	std::string getName(void) const
	{
		return name;
	}
	std::vector<std::string> getVacList(void) const
	{
		return vacancyList;
		/*for (int i = 0; i < vacancyList.size(); i++)
		{
		std::cout << vacancyList[i] << std::endl;
		}*/
	}
	int getCurValueOfWorkers(void) const
	{
		return curValueOfWorkers;
	}
	//static function
	static const int getMaxValueOfWorkers(void)
	{
		return maxValueOfWorkers;
	}

	//setters
	void setVacList(std::vector<std::string> vl);
	void setCurValueOfWorkers(int cur)
	{
		curValueOfWorkers = cur;
	}

	//iterator
	void companyWorking();
	/*Technical_manager technical_manager;
	Hr_manager hr_manager;*/
	/*Technical_manager technical_manager[100];
	Hr_manager hr_manager[100];*/
	std::vector<Technical_manager> technical_manager;
	std::vector<Hr_manager> hr_manager;
protected:
private:
	const std::string name;
	std::vector<std::string> vacancyList;
	static const int maxValueOfWorkers; //static var
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