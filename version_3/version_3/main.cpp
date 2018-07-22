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

//void displayGeters(It_company &itcompany, Candidate &candidate)
//{
//	std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
//	std::cout << std::endl;
//	std::cout << "Company name: " << itcompany.getName() << std::endl;
//	std::cout << "Workers: " << std::endl;
//	std::cout << "- Technical managers" << std::endl;
//	for (int i = 0; i < itcompany.technical_manager.size(); i++)
//	{
//		std::cout << " " << i + 1 << ". " << itcompany.technical_manager[i].getName() << std::endl;
//		std::cout << "    Requirement level: " << itcompany.technical_manager[i].getReqLevel() << std::endl;
//		std::cout << "    Commutability level: " << itcompany.technical_manager[i].getComLevel() << std::endl;
//		std::cout << "    Tests made by " << itcompany.technical_manager[i].getName() << ":" << std::endl;
//		for (int l = 0; l < itcompany.technical_manager[i].test.size(); l++)
//		{
//			std::cout << "     " << l + 1 << ". " << "Type: " << itcompany.technical_manager[i].test[l]->getType() << std::endl;
//			std::cout << "     " << ". " << "Result: ";
//			itcompany.technical_manager[i].test[l]->successOfPassing() ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
//		}
//		std::cout << "    Interviews made by " << itcompany.technical_manager[i].getName() << ":" << std::endl;
//		
//		for (int k = 0; k < itcompany.technical_manager[i].interview.size(); k++)
//		{
//			std::cout << "     " << k + 1 << ". " << "Result: ";
//			itcompany.technical_manager[i].interview[k]->successOfPassing() ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
//		}
//	}
//	std::cout << std::endl;
//	std::cout << "- HR-managers" << std::endl;
//	for (int j = 0; j < itcompany.hr_manager.size(); j++)
//	{
//		std::cout << " " << j + 1 << ". " << itcompany.hr_manager[j].getName() << std::endl;
//	}
//	std::cout << "Vacancies:" << std::endl;
//	for (int i = 0; i < itcompany.getVacList().size(); i++)
//	{
//		std::cout << itcompany.getVacList()[i] << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "Candidate: " << std::endl;
//	std::cout << "    Worrying level: " << candidate.getWorLevel() << std::endl;
//	std::cout << "    Commutability level: " << candidate.getComLevel() << std::endl;
//	std::cout << "Candidate`s resume:" << std::endl;
//	std::cout << "Aim: " << candidate.resume.getAim() << std::endl << "Competence: " << candidate.resume.getCompetence() << std::endl
//		<< "Education: " << candidate.resume.getEducation() << std::endl << "Experience: " << candidate.resume.getExperience() << std::endl
//		<< "Email: " << candidate.resume.getEmail() << std::endl << "Address: " << candidate.resume.getAddress() << std::endl
//		<< "Name: " << candidate.resume.getName() << std::endl << "Birthday: " << candidate.resume.getBirthday() << std::endl;
//	std::cout << "Courses:" << std::endl;
//	for (int i = 0; i < candidate.resume.getCourses().size(); i++)
//	{
//		std::cout << candidate.resume.getCourses()[i] << std::endl;
//	}
//	std::cout << "Languages:" << std::endl;
//	for (int i = 0; i < candidate.resume.getLanguages().size(); i++)
//	{
//		std::cout << candidate.resume.getLanguages()[i] << std::endl;
//	}
//	std::cout << "Phone numbers:" << std::endl;
//	for (int i = 0; i < candidate.resume.getPhones().size(); i++)
//	{
//		std::cout << candidate.resume.getPhones()[i] << std::endl;
//	}
//	std::cout << std::endl;
//}
//
//void displaySeters(It_company &itcompany, Candidate &candidate)
//{
//	std::cout << "Seters for IT-company" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << std::endl;
//	std::string name;
//	std::vector<std::string> vacList;
//	std::cout << "Set name: ";
//	std::cin >> name;
//	itcompany.setName(name);
//	std::string vac;
//	std::cout << "Set list of vacancies:" << std::endl;
//	while (true)
//	{
//		char answer = 'y';
//		std::cout << "Add vacancy to the list: ";
//		std::cin >> vac;
//		vacList.push_back(vac);
//		std::cout << "Do you want to continue adding vacancies? (y/n)" << std::endl;
//		std::cin >> answer;
//		if (answer == 'n')
//		{
//			break;
//		}
//	}
//	itcompany.setVacList(vacList);
//	std::cout << "Seters for Technical manager" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set name: ";
//	std::string nam;
//	std::cin >> nam;
//	itcompany.technical_manager[0].setName(nam);
//	std::cout << "Set level of requirement: ";
//	int rlev;
//	std::cin >> rlev;
//	itcompany.technical_manager[0].setReqLevel(rlev);
//	std::cout << "Set level of commutability: ";
//	int clev;
//	std::cin >> clev;
//	itcompany.technical_manager[0].setComLevel(clev);
//	std::cout << "Seters for HR-manager" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set name: ";
//	std::cin >> name;
//	itcompany.hr_manager[0].setName(name);
//	std::cout << "Seters for Test" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set type: ";
//	std::string type;
//	std::cin >> type;
//	itcompany.technical_manager[0].test[0]->setType(type);
//	std::cout << "Set result: ";
//	bool res;
//	std::cin >> res;
//	itcompany.technical_manager[0].test[0]->setResult(res);
//	/*std::cout << "Is this test successifuly passed? - ";
//	itcompany.technical_manager[0].test[0]->successOfPassing ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;*/
//	std::cout << "Seters for Interview" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set result: ";
//	std::cin >> res;
//	itcompany.technical_manager[0].interview[0]->setResult(res);
//	std::cout << "Seters for Candidate" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set level of commutability: ";
//	std::cin >> clev;
//	candidate.setComLevel(clev);
//	std::cout << "Set level of worry: ";
//	int wlev;
//	std::cin >> wlev;
//	candidate.setWorLevel(wlev);
//	std::cout << "Set work: ";
//	bool w;
//	std::cin >> w;
//	candidate.setWork(w);
//	std::cout << "Seters for Resume" << std::endl;
//	std::cout << "/////////////////////////////////////" << std::endl;
//	std::cout << "Set aim: ";
//	std::string aim;
//	std::cin >> aim;
//	candidate.resume.setAim(aim);
//	std::cout << "Set Competence: ";
//	std::string comp;
//	std::cin >> comp;
//	candidate.resume.setCompetence(comp);
//	std::cout << "Set Courses: ";
//	std::vector<std::string> c;
//	while (true)
//	{
//		char answer = 'y';
//		std::cout << "Add course: ";
//		std::string cour;
//		std::cin >> cour;
//		c.push_back(cour);
//		std::cout << "Do you want to continue adding courses? (y/n)" << std::endl;
//		std::cin >> answer;
//		if (answer == 'n')
//		{
//			break;
//		}
//	}
//	candidate.resume.setCourses(c);
//	std::cout << "Set Education: ";
//	std::string e;
//	std::cin >> e;
//	candidate.resume.setEducation(e);
//	std::cout << "Set Languages: ";
//	std::vector<std::string> l;
//	while (true)
//	{
//		char answer = 'y';
//		std::cout << "Add clanguage: ";
//		std::string lang;
//		std::cin >> lang;
//		l.push_back(lang);
//		std::cout << "Do you want to continue adding languages? (y/n)" << std::endl;
//		std::cin >> answer;
//		if (answer == 'n')
//		{
//			break;
//		}
//	}
//	candidate.resume.setLanguages(l);
//	std::cout << "Set Experience: ";
//	int exp;
//	std::cin >> exp;
//	candidate.resume.setExperience(exp);
//	std::cout << "Set Email: ";
//	std::string mail;
//	std::cin >> mail;
//	candidate.resume.setEmail(mail);
//	std::cout << "Set Phones: ";
//	std::vector<int> p;
//	while (true)
//	{
//		char answer = 'y';
//		std::cout << "Add phone: ";
//		int num;
//		std::cin >> num;
//		p.push_back(num);
//		std::cout << "Do you want to continue adding phones? (y/n)" << std::endl;
//		std::cin >> answer;
//		if (answer == 'n')
//		{
//			break;
//		}
//	}
//	candidate.resume.setPhones(p);
//	std::cout << "Set Address: ";
//	std::string ad;
//	std::cin >> ad;
//	candidate.resume.setAddress(ad);
//	std::cout << "Set name: ";
//	std::string n;
//	std::cin >> n;
//	candidate.resume.setName(n);
//	std::cout << "Set birthday: ";
//	std::string b;
//	std::cin >> b;
//	candidate.resume.setBirthday(b);
//}

int main()
{
	system("color F0");
	std::cout << "/////////////////////////////////////" << std::endl;
	std::cout << "/// Anton Doroshenko, grupe IS-52///" << std::endl;
	std::cout << "/// employment in the IT-company ///" << std::endl;
	std::cout << "/// __________VERTION_3_________ ///" << std::endl;
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
		It_company itcompany("Micro", vac, 3, 2); 
		std::cout << std::endl;
		Candidate candidate;
		std::cout << std::endl;
		std::cout << "Company '" << itcompany.getName() << "' " << "recruting specialists\n" << std::endl;
		std::cout << candidate.getName() << " Search for job\n" << std::endl;
		itcompany.hr_manager[0].candidate.push_back(&candidate);
		itcompany.companyWorking();
		delTestInterview(itcompany);
		std::cout << std::endl;
	}
	std::cout << "...End modeling..." << std::endl;
	system("pause");
}