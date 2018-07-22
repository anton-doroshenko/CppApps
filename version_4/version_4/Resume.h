/***********************************************************************
* Module:  Resume.h
* Author:  Anton
* Modified: Monday, November 7, 2016 6:25:26 PM
* Purpose: Declaration of the class Resume
***********************************************************************/
#include <iostream>
#if !defined(__UML_Class_Diagram_1_Resume_h)
#define __UML_Class_Diagram_1_Resume_h

class Resume
{
public:
	//Constructors
	Resume();
	Resume(std::string aim, std::string comp,
		std::vector<std::string> courses, std::string educ,
		std::vector<std::string> lang, int exp, std::string email,
		std::vector<int> phone, std::string address,
		std::string name, std::string birth);
	Resume(Resume &sResume);
	Resume(std::string str);

	//destructor
	~Resume() {}

	//Acsesors
	void setAim(std::string a);
	void setCompetence(std::string c);
	void setCourses(std::vector<std::string> c);
	void setEducation(std::string e);
	void setLanguages(std::vector<std::string> l);
	void setExperience(int exp);
	void setEmail(std::string mail);
	void setPhones(std::vector<int> p);
	void setAddress(std::string ad);
	void setName(std::string n);
	void setBirthday(std::string b);

	std::string Resume::getAim(void) const
	{
		return aim;
	}
	std::string Resume::getCompetence(void) const
	{
		return competence;
	}
	std::vector<std::string> Resume::getCourses(void) const
	{
		return courses;
		/*for (int i = 0; i < courses.size(); i++)
		{
		std::cout << courses[i] << std::endl;
		}*/
	}
	std::string Resume::getEducation(void) const
	{
		return education;
	}
	std::vector<std::string> Resume::getLanguages(void) const
	{
		return languages;
		/*for (int i = 0; i < languages.size(); i++)
		{
		std::cout << languages[i] << std::endl;
		}*/
	}
	int Resume::getExperience(void) const
	{
		return experience;
	}
	std::string Resume::getEmail(void) const
	{
		return email;
	}
	std::vector<int> Resume::getPhones(void) const
	{
		return phoneNumbers;
		/*for (int i = 0; i < phoneNumbers.size(); i++)
		{
		std::cout << phoneNumbers[i] << std::endl;
		}*/
	}
	std::string Resume::getAddress(void) const
	{
		return address;
	}
	std::string Resume::getName(void) const
	{
		return name;
	}
	std::string Resume::getBirthday(void) const
	{
		return birthday;
	}

protected:
private:
	std::string aim;
	std::string competence;
	std::vector<std::string> courses;
	std::string education;
	std::vector<std::string> languages;
	int experience;
	std::string email;
	std::vector<int> phoneNumbers;
	std::string address;
	std::string name;
	std::string birthday;


};

#endif