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
   public void set()
   {
      // TODO: implement
   }
   
   public void get()
   {
      // TODO: implement
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