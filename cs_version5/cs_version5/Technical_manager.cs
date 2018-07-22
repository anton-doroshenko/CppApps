/***********************************************************************
 * Module:  Technical_manager.cs
 * Author:  Anton
 * Purpose: Definition of the Class Technical_manager
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class Technical_manager : Worker
{
    public Technical_manager()
    {
        test = new List<Test>(1);
        interview = new List<Interview>(1);
        test.Add(new Test());
        interview.Add(new Interview());
        //name = "";
        requirementLevel = 1;
        commutabilityLevel = 1;
        Console.WriteLine("Technical_manager was created (default)");
    }
	public Technical_manager(string nam, int rLevel, int cLevel) : base(nam)
    {
        test.Add(new Test());
        interview.Add(new Interview());
        //name = nam;
        requirementLevel = rLevel;
        commutabilityLevel = cLevel;
        Console.WriteLine("Technical_manager was created (inicialisation)");
    }
	public Technical_manager(Technical_manager sTechnical_manager)
    {
        test = sTechnical_manager.test;
        interview = sTechnical_manager.interview;
        //name = sTechnical_manager.name;
        requirementLevel = sTechnical_manager.requirementLevel;
        commutabilityLevel = sTechnical_manager.commutabilityLevel;
        Console.WriteLine("Technical_manager was created (copy)");
    }
   
   public string getName()
   {
       return name;
   }
   public int getReqLevel()
   {
       return requirementLevel;
   }
   public int getComLevel()
   {
       return commutabilityLevel;
   }
   public string getState()
   {
       return state;
   }
   
    public void setState(string s)
    {
	    state = s;
    }

    public void prepareTest(List<string> list)
    {
        int numOfQuations = 0;
        for (int i = 0; i < list.Count; i++)
        {
            if (test.Count == 0 || i > 0)
            {
                test.Add(new Test());
            }
            test[test.Count - 1].setType(list[i]);
            Console.WriteLine("Enter number of quastions");
            numOfQuations = int.Parse(Console.ReadLine());
            List<string> lis = new List<string>(1);
            for (int j = 0; j < numOfQuations; j++)
            {
                string str;
                Console.WriteLine("Enter dificulty of quastion");
                str = Console.ReadLine();
                lis.Add(str);
            }
            test[test.Count - 1].setQuestions(lis);
        }
    }

	public string checkTest(List<string> listOfAnswers)
    {
        int amountOfcorrectAnsw = 0;
	    for (int i = 0; i < listOfAnswers.Count; i++)
	    {
		    amountOfcorrectAnsw = listOfAnswers[i] == "done" ? amountOfcorrectAnsw + 1 : amountOfcorrectAnsw;
	    }
	    if ((float)amountOfcorrectAnsw / (float)listOfAnswers.Count >= 0.66)
	    {
		    return "DoneTest";
	    }
	    else
	    {
		    return "FailTest";
	    }
    }

	public string holdingInterview(int cLevel, int wLevel, string name)
    {
        if (interview.Count == 0 || !(interview[interview.Count - 1].getWhoPass().Length == 0))
	    {
		    interview.Add(new Interview());
	    }
	    bool res = false;
	    res = (cLevel * commutabilityLevel) / (wLevel * requirementLevel) != 0 ? true : false;
	    interview[interview.Count - 1].setResult(res);
	    interview[interview.Count - 1].setWhoPass(name);
	    if (res == true)
	    {
		    return "getWork";
	    }
	    else
	    {
		    return "Fail";
	    }
    }

	public Test getTestForCandidate(string competence)
    {
        for (int i = 0; i < test.Count; i++)
	    {
		    if (test[i].getType() == competence)
		    {
			    return test[i];
		    }
	    }
        return test[0];
    }

   public List <Interview> interview;
   
   public List<Test> test;
  

   private string name;
   private int requirementLevel;
   private int commutabilityLevel;
   private string state;

}