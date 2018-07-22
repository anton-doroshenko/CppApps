#include <iostream>
#include <vector>
#include <string>

#include "Technical_manager.h"
#include "Hr_manager.h"
#include "It_company.h"
#include "Candidate.h"
#include "Interview.h"
#include "Test.h"
#include "Resume.h"

std::vector<std::string> vacancies(10);

void delTestInterview(It_company &sitcompany)
{
	for (int i = 0; i < sitcompany.technical_manager.size(); i++)
	{
		for (int j = 0; j < sitcompany.technical_manager[i].test.size(); j++)
		{
			delete sitcompany.technical_manager[i].test[j];
		}
		for (int k = 0; k < sitcompany.technical_manager[i].interview.size(); k++)
		{
			delete sitcompany.technical_manager[i].interview[k];
		}
	}
}

void delTestInterview(Technical_manager &technical_manager)
{
		for (int j = 0; j < technical_manager.test.size(); j++)
		{
			delete technical_manager.test[j];
		}
		for (int k = 0; k < technical_manager.interview.size(); k++)
		{
			delete technical_manager.interview[k];
		}
}

int main()
{
	system("color F0");
	std::cout << "/////////////////////////////////////" << std::endl;
	std::cout << "/// Anton Doroshenko, grupe IS-52///" << std::endl;
	std::cout << "/// employment in the IT-company ///" << std::endl;
	std::cout << "/// __________VERTION_2_________ ///" << std::endl;
	std::cout << "/////////////////////////////////////" << std::endl;
	system("pause");
	system("cls");
	std::cout << "...Start modeling..." << std::endl;
	std::cout << std::endl;
	{
		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << "/// Main objects that are created ///" << std::endl;
		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << std::endl;
		It_company itcompany("name__vacancy"); 
		std::cout << std::endl;
		Candidate candidate;
		std::cout << std::endl;
		delTestInterview(itcompany);
		std::cout << std::endl;
	}
	std::cout << "////////////////////////////////////////////////" << std::endl;
	std::cout << "Demonstration of work of different constructors:" << std::endl;
	std::cout << "////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Creating IT-company:" << std::endl;
		std::cout << std::endl;
		It_company itcompany1;
		std::cout << std::endl;
		It_company itcompany2("Name", vacancies);
		std::cout << std::endl;
		It_company itcompany3(itcompany2);
		std::cout << std::endl;
		It_company itcompany4("name__vacancy");
		std::cout << std::endl;
		delTestInterview(itcompany1);
		delTestInterview(itcompany2);
		delTestInterview(itcompany3);
		delTestInterview(itcompany4); 
	}
	{
		std::cout << std::endl;
		std::cout << "Creating Candidate:" << std::endl;
		std::cout << std::endl;
		Candidate candidate1;
		std::cout << std::endl;
		Candidate candidate2(1, 2, false);
		std::cout << std::endl;
		Candidate candidate3(candidate1);
		std::cout << std::endl;
		Candidate candidate4("02030");
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "Creating HR-manager:" << std::endl;
		std::cout << std::endl;
		Hr_manager hrmanager1;
		std::cout << std::endl;
		Hr_manager hrmanager2("name2");
		std::cout << std::endl;
		Hr_manager hrmanager3(hrmanager1);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "Creating Technical manager:" << std::endl;
		std::cout << std::endl;
		Technical_manager technical_manager1;
		std::cout << std::endl;
		Technical_manager technical_manager2("name", 1, 2);
		std::cout << std::endl;
		Technical_manager technical_manager3(technical_manager1);
		std::cout << std::endl;
		Technical_manager technical_manager4("Name40403");
		std::cout << std::endl;
		delTestInterview(technical_manager1);
		delTestInterview(technical_manager2);
		delTestInterview(technical_manager3);
		delTestInterview(technical_manager4);
	}
	{
		std::cout << std::endl;
		std::cout << "Creating Test:" << std::endl;
		std::cout << std::endl;
		Test test1;
		std::cout << std::endl;
		Test test2("type", false);
		std::cout << std::endl;
		Test test3(test1);
		std::cout << std::endl;
		Test test4("type1");
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "Creating Interview:" << std::endl;
		std::cout << std::endl;
		Interview interview1;
		std::cout << std::endl;
		Interview interview2(false);
		std::cout << std::endl;
		Interview interview3(interview1);
		std::cout << std::endl;
		Interview interview4("0");
		std::cout << std::endl;
	}
	{
		std::vector<std::string> lang(3);
		std::vector<int> phones(2);
		std::vector<std::string> courses(1);
		std::cout << std::endl;
		std::cout << "Creating Resume:" << std::endl;
		std::cout << std::endl;
		Resume resume1;
		std::cout << std::endl;
		Resume resume2("none", "none", courses, "none", lang, 1, "none", phones, "none", "none", "none");
		std::cout << std::endl;
		Resume resume3(resume1);
		std::cout << std::endl;
		Resume resume4("aimCompetenceCourse1_educationEng_02antonDoroshenko1@gmail.com620829_addressNameBirthday");
		std::cout << std::endl;

	}
	std::cout << std::endl;
	std::cout << "...End modeling..." << std::endl;
	system("pause");
}