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

int main()
{
	system("color F0");
	std::cout << "/////////////////////////////////////" << std::endl;
	std::cout << "/// Anton Doroshenko, grupe IS-52///" << std::endl;
	std::cout << "/// employment in the IT-company ///" << std::endl;
	std::cout << "/// __________VERTION_6_________ ///" << std::endl;
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
		std::vector<std::string> vac;
		It_company itcompany("Micro", vac, 2);
		{
			Worker* w = new Worker;
			Hr_manager* h = new Hr_manager;
			w->showPosition();
			w = h;
			w->showPosition();
		}
		std::cout << std::endl;
		Candidate candidate;
		std::cout << std::endl;
		std::cout << "Company '" << itcompany.getName() << "' " << "recruting specialists\n" << std::endl;
		std::cout << candidate.getName() << " Search for job\n" << std::endl;
		//itcompany.hr_manager[0].candidate.push_back(&candidate);
		itcompany.hr_manager[0] + candidate;
		itcompany.companyWorking();
		delTestInterview(itcompany);
		std::cout << std::endl;
	}
	std::cout << "...End modeling..." << std::endl;
	system("pause");
}