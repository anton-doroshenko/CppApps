/***********************************************************************
 * Module:  Candidate.cs
 * Author:  Anton
 * Purpose: Definition of the Class Candidate
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class Candidate
{
    public Candidate()
    {
        Resume resume = new Resume();
        commutabilityLevel = 1;
        worryingLevel = 2;
        work = false;
        Console.WriteLine("Candidate was created (default)");
    }
	public Candidate(int cLevel, int wLevel, bool work)
    {
        Resume resume = new Resume();
        commutabilityLevel = cLevel;
        worryingLevel = wLevel;
        work = work;
        Console.WriteLine("Candidate was created (inicialisation)");
    }
    public Candidate(Candidate sCandidate)
    {
        resume = sCandidate.resume;
        commutabilityLevel = sCandidate.commutabilityLevel;
        worryingLevel = sCandidate.worryingLevel;
        work = sCandidate.work;
        Console.WriteLine("Candidate was created (copy)");
    }
   
   public int getComLevel()
   {
       return commutabilityLevel;
   }
	public int getWorLevel()
   {
       return worryingLevel;
   }
	public string getState()
    {
        return state;
    }
   
   public void setComLevel(int c)
    {
        commutabilityLevel = c;
    }
	public void setWorLevel(int w)
   {
       worryingLevel = w;

   }
	public void setWork(bool w)
    {
        work = w;

    }
	public void setState(string st)
    {
        state = st;

    }
   
   public void prepareResume()
   {
       /*Console.WriteLine("Set aim: ";
	string aim;
	std::cin >> aim;
	resume.setAim(aim);*/
	Console.WriteLine("Set Competence: ");
	string comp;
	comp = Console.ReadLine();
	resume.setCompetence(comp);
	/*Console.WriteLine("Set Courses: ";
	List<string> c;
	while (true)
	{
		char answer = 'y';
		Console.WriteLine("Add course: ";
		string cour;
		Console.ReadLine(cour;
		c.Add(cour);
		Console.WriteLine("Do you want to continue adding courses? (y/n)" << std::endl;
		Console.ReadLine(answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setCourses(c);*/
	Console.WriteLine("Set Education: ");
	string e;
	e = Console.ReadLine();
	resume.setEducation(e);
	Console.WriteLine("Set Languages: ");
	/*List<string> l;
	while (true)
	{
		char answer = 'y';
		Console.WriteLine("Add clanguage: ";
		string lang;
		Console.ReadLine(lang;
		l.Add(lang);
		Console.WriteLine("Do you want to continue adding languages? (y/n)" << std::endl;
		Console.ReadLine(answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setLanguages(l);*/
	Console.WriteLine("Set Experience: ");
	int exp;
	exp = int.Parse(Console.ReadLine());
	resume.setExperience(exp);
	/*Console.WriteLine("Set Email: ";
	string mail;
	std::cin >> mail;
	resume.setEmail(mail);
	Console.WriteLine("Set Phones: ";
	List<int> p;
	while (true)
	{
		char answer = 'y';
		Console.WriteLine("Add phone: ";
		int num;
		std::cin >> num;
		p.Add(num);
		Console.WriteLine("Do you want to continue adding phones? (y/n)" << std::endl;
		std::cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}
	resume.setPhones(p);*/
	/*Console.WriteLine("Set Address: ";
	string ad;
	std::cin >> ad;
	resume.setAddress(ad);
	resume.setName(name);
	Console.WriteLine("Set birthday: ";
	string b;
	std::cin >> b;
	resume.setBirthday(b);*/
	// TODO : implement
   }
   public List<string> takeTest(List<string> listOfQuations)
    {
        List<string> listOfAnswers = new List<string>(1);
	    state = "testing";
	    for (int i = 0; i < listOfQuations.Count; i++)
	    {
		    //Console.WriteLine( << std::endl;
		    listOfAnswers.Add(answerQuestion(listOfQuations[i]));
	    }
	    return listOfAnswers;
    }
	public void passInterview()
    {
        state = "interview";
    }

    public string getName()
    {
        return name;
    }
	public void getWork(int time, List<string> quetions, List<string> answ)
    {
        if (time == 1)
	    {
		    Console.WriteLine("...Candidate create resume...\n");
		    prepareResume();
	    }
	    if (time == 3)
	    {
		    Console.WriteLine("...Candidate take test...\n");
		    answ = takeTest(quetions);
	    }
	    if (time == 5 && state == "DoneTest")
	    {
		    Console.WriteLine("...Candidate pass interview...\n");
		    passInterview();
	    }
    }

   public Resume resume = new Resume();

    private string answerQuestion(string dificult)
{
    int result = resume.getExperience() / (1 * worryingLevel);
    return result != 0 ? "done" : "fail";//TODO: make better
}
   private int commutabilityLevel;
   private int worryingLevel;
   private bool work;
   private string state;
   private string name;

}