/***********************************************************************
* Module:  It_company.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:55:11 PM
* Purpose: Declaration of the class It_company
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#if !defined(__UML_Class_Diagram_1_It_company_h)
#define __UML_Class_Diagram_1_It_company_h

class Technical_manager;
class Hr_manager;

class It_company
{
public:
	
	It_company();
	It_company(std::string name, std::vector<std::string> vacancies);
	It_company(It_company &sIt_company);
	It_company(std::string str);
	~It_company();
	void get(void);
	void set(void);

	/*Technical_manager technical_manager;
	Hr_manager hr_manager;*/
	/*Technical_manager technical_manager[100];
	Hr_manager hr_manager[100];*/
	std::vector<Technical_manager> technical_manager;
	std::vector<Hr_manager> hr_manager;
protected:
private:
	std::string name;
	std::vector<std::string> vacancyList;


};

#endif