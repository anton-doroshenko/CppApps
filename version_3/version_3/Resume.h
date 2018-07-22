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
	~Resume();

	//setters
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

	//getters
	std::string getAim(void);
	std::string getCompetence(void);
	std::vector<std::string> getCourses(void);
	std::string getEducation(void);
	std::vector<std::string> getLanguages(void);
	int getExperience(void);
	std::string getEmail(void);
	std::vector<int> getPhones(void);
	std::string getAddress(void);
	std::string getName(void);
	std::string getBirthday(void);

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