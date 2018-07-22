/***********************************************************************
* Module:  Resume.cpp
* Author:  Anton
* Modified: Monday, November 7, 2016 6:25:26 PM
* Purpose: Implementation of the class Resume
***********************************************************************/
#include <vector>
#include <string>
#include "Resume.h"
#include "Technical_manager.h"


Resume::Resume():
	aim("none"),
	competence("none"),
	courses(1, "course1"),
	education("none"),
	languages(1, "English"),
	experience(1),
	email("none"),
	phoneNumbers(1, 666),
	address("none"),
	name("none"),
	birthday("none")
{
	//std::cout << "Resume was created (default)" << std::endl;
}

Resume::Resume(std::string aim, std::string comp,
	std::vector<std::string> courses, std::string educ, 
	std::vector<std::string> lang, int exp, std::string email, 
	std::vector<int> phone, std::string address,
	std::string name,std::string birth) :
	aim(aim),
	competence(comp),
	courses(courses),
	education(educ),
	languages(lang),
	experience(exp),
	email(email),
	phoneNumbers(phone),
	address(address),
	name(name),
	birthday(birth)
{
	//std::cout << "Resume was created (inicialisation)" << std::endl;
}

Resume::Resume(Resume &sResume):
	aim(sResume.aim),
	competence(sResume.competence),
	courses(sResume.courses),
	education(sResume.education),
	languages(sResume.languages),
	experience(sResume.experience),
	email(sResume.email),
	phoneNumbers(sResume.phoneNumbers),
	address(sResume.address),
	name(sResume.name),
	birthday(sResume.birthday)
{
	//std::cout << "Resume was created (copy)" << std::endl;
}

Resume::Resume(std::string str) :
	aim(str.substr(0, 3)),
	competence(str.substr(3, 10)),
	courses(1, str.substr(13, 7)),
	education(str.substr(21, 9)),
	languages(1, str.substr(30, 3)),
	experience(atoi(str.substr(34, 2).c_str())),
	email(str.substr(36, 26)),
	phoneNumbers(1, atoi(str.substr(62, 6).c_str())),
	address(str.substr(69, 7)),
	name(str.substr(76, 4)),
	birthday(str.substr(80, 8))
{
	/*aim = str.substr(0, 3);
	competence = str.substr(3, 10);
	int ind = 0;
	for (int i = 0; i < str.substr(13).size() / 7; i++)
	{
	ind = 13 + 7 * i;
	if (str[ind] == '_')
	{
	break;
	}
	courses.push_back(str.substr((ind), 7));
	}
	education = str.substr(ind + 1, 9);
	ind += 10;
	int index = ind;
	for (int j = 0; j < str.substr(index).size() / 3; j++)
	{
	ind = index + 3 * j;
	if (str[ind] == '_')
	{
	break;
	}
	languages.push_back(str.substr((ind), 3));
	}
	experience = atoi(str.substr(ind + 1, 2).c_str());
	email = str.substr(ind + 3, 26);
	ind += 29;
	index = ind;
	for (int k = 0; k < str.substr(index).size() / 6; k++)
	{
	ind = index + 6 * k;
	if (str[ind] == '_')
	{
	break;
	}
	phoneNumbers.push_back(atoi(str.substr((ind), 6).c_str()));
	}
	address = str.substr(ind + 1, 7);
	name = str.substr(ind + 8, 4);
	birthday = str.substr(ind + 12, 8);*/
	//std::cout << "Resume was created (transform)" << std::endl;
}

//Resume::~Resume()
//{
//	//std::cout << "Resume was destroyed" << std::endl;
//	//std::cout << std::endl;
//}
////////////////////////////////////////////////////////////////////////
// Name:       Resume::set()
// Purpose:    Implementation of Resume::set()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Resume::setAim(std::string a)
{
	aim = a;
}

void Resume::setCompetence(std::string c)
{
	competence = c;
}

void Resume::setCourses(std::vector<std::string> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		courses.push_back(c[i]);
	}
}

void Resume::setEducation(std::string e)
{
	education = e;
}

void Resume::setLanguages(std::vector<std::string> l)
{
	for (int i = 0; i < l.size(); i++)
	{
		languages.push_back(l[i]);
	}
}

void Resume::setExperience(int exp)
{
	experience = exp;
}

void Resume::setEmail(std::string mail)
{
	email = mail;
}

void Resume::setPhones(std::vector<int> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		phoneNumbers.push_back(p[i]);
	}
}

void Resume::setAddress(std::string ad)
{
	address = ad;
}

void Resume::setName(std::string n)
{
	name = n;
}

void Resume::setBirthday(std::string b)
{
	birthday = b;
}

////////////////////////////////////////////////////////////////////////
// Name:       Resume::get()
// Purpose:    Implementation of Resume::get()
// Return:     void
////////////////////////////////////////////////////////////////////////

//std::string Resume::getAim(void)
//{
//	return aim;
//}

//std::string Resume::getCompetence(void)
//{
//	return competence;
//}

//std::vector<std::string> Resume::getCourses(void)
//{
//	return courses;
//	/*for (int i = 0; i < courses.size(); i++)
//	{
//		std::cout << courses[i] << std::endl;
//	}*/
//}

//std::string Resume::getEducation(void)
//{
//	return education;
//}

//std::vector<std::string> Resume::getLanguages(void)
//{
//	return languages;
//	/*for (int i = 0; i < languages.size(); i++)
//	{
//		std::cout << languages[i] << std::endl;
//	}*/
//}

//int Resume::getExperience(void)
//{
//	return experience;
//}

//std::string Resume::getEmail(void)
//{
//	return email;
//}

//std::vector<int> Resume::getPhones(void)
//{
//	return phoneNumbers;
//	/*for (int i = 0; i < phoneNumbers.size(); i++)
//	{
//		std::cout << phoneNumbers[i] << std::endl;
//	}*/
//}

//std::string Resume::getAddress(void)
//{
//	return address;
//}

//std::string Resume::getName(void)
//{
//	return name;
//}

//std::string Resume::getBirthday(void)
//{
//	return birthday;
//}