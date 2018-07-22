/***********************************************************************
 * Module:  Resume.cs
 * Author:  Anton
 * Purpose: Definition of the Class Resume
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class Resume
{
    public Resume()
    {
        aim = "none";
        competence = "none";
        courses = new List<string>(1);
        courses.Add("");
        education = "none";
        languages = new List<string>(1);
        languages.Add("");
        experience = 1;
        email = "none";
        phoneNumbers = new List<int>(1);
        phoneNumbers.Add(1);
        address = "none";
        name = "none";
        birthday = "none";
        Console.WriteLine("Resume was created (default)");
    }
    public Resume(string a, string comp,
		List<string> course, string educ,
		List<string> lang, int exp, string em,
		List<int> phone, string addr,
		string n, string birth)
    {
        aim = a;
        competence = comp;
        courses = course;
        education = educ;
        languages = lang;
        experience = exp;
        email = em;
        phoneNumbers = phone;
        address = addr;
        name = n;
        birthday = birth;
        Console.WriteLine("Resume was created (inicialisation)");
    }
    public Resume(Resume sResume)
    {
        aim = sResume.aim;
        competence = sResume.competence;
        courses = sResume.courses;
        education = sResume.education;
        languages = sResume.languages;
        experience = sResume.experience;
        email = sResume.email;
        phoneNumbers = sResume.phoneNumbers;
        address = sResume.address;
        name = sResume.name;
        birthday = sResume.birthday;
        Console.WriteLine("Resume was created (copy)");
    }
   public void setAim(string a)
    {
        aim = a;
    }
	public void setCompetence(string c)
   {
       competence = c;
   }
	public void setCourses(List<string> c)
    {
        for (int i = 0; i < c.Count; i++)
        {
            courses.Add(c[i]);
        }
    }
	public void setEducation(string e)
    {
        education = e;
    }
	public void setLanguages(List<string> l)
    {
        for (int i = 0; i < l.Count; i++)
        {
            languages.Add(l[i]);
        }
    }
	public void setExperience(int exp)
    {
        experience = exp;
    }
	public void setEmail(string mail)
    {
        email = mail;
    }
	public void setPhones(List<int> p)
    {
        for (int i = 0; i < p.Count; i++)
        {
            phoneNumbers.Add(p[i]);
        }
    }
	public void setAddress(string ad)
    {
        address = ad;
    }
	public void setName(string n)
    {
        name = n;
    }
	public void setBirthday(string b)
    {
        birthday = b;
    }
   
   public string getAim()
   {
       return aim;
   }
	public string getCompetence()
    {
        return competence;
    }
	public List<string> getCourses()
    {
        return courses;
    }
	public string getEducation()
    {
        return education;
    }
	public List<string> getLanguages()
    {
        return languages;
    }
	public int getExperience()
    {
        return experience;
    }
	public string getEmail()
    {
        return email;
    }
	public List<int> getPhones()
    {
        return phoneNumbers;
    }
	public string getAddress()
    {
        return address;
    }
	public string getName()
    {
        return name;
    }
	public string getBirthday()
    {
        return birthday;
    }

   private string aim;
   private string competence;
   private List<string> courses;
   private string education;
   private List<string> languages;
   private int experience;
   private string email;
   private List<int> phoneNumbers;
   private string address;
   private string name;
   private string birthday;

}