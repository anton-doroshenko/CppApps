/***********************************************************************
 * Module:  It_company.cs
 * Author:  Anton
 * Purpose: Definition of the Class It_company
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class It_company
{
    public List<Hr_manager> hr_manager = new List<Hr_manager>(1);
    public List<Technical_manager> technical_manager = new List<Technical_manager>(1);
    public It_company()
    {
        hr_manager = new List<Hr_manager>(1);
        technical_manager = new List<Technical_manager>(1);
        hr_manager.Add(new Hr_manager());
        technical_manager.Add(new Technical_manager());
        vacancyList = new List<string>(1);
        name = "Name";
        curValueOfWorkers = 2;
        Console.WriteLine("IT-company was created (default)");
    }
	public It_company(string nam, List<string> vacancies)
    {
        hr_manager = new List<Hr_manager>(1);
        technical_manager = new List<Technical_manager>(1);
        hr_manager.Add(new Hr_manager());
        technical_manager.Add(new Technical_manager());
        name = nam;
        vacancyList = vacancies;
        curValueOfWorkers = 2;
        Console.WriteLine("IT-company was created (inicialisation)");
    }
	public It_company(It_company sIt_company)
    {
        hr_manager = sIt_company.hr_manager;
        technical_manager = sIt_company.technical_manager;
        name = sIt_company.name;
        vacancyList = sIt_company.vacancyList;
        curValueOfWorkers = 2;
        Console.WriteLine("IT-company was created (copy)");
    }

    static It_company()
    {
        maxValueOfWorkers = 4;
        Console.WriteLine("Static constructor");
    }
  public void setName(string n)
    {
        name = n;
    }
	public void setVacList(List<string> vl)
  {
      for (int i = 0; i < vl.Count; i++)
      {
          vacancyList.Add(vl[i]);
      }
  }
	public void setMaxValueOfWorkers(int max)
    {
        maxValueOfWorkers = max;
    }
	public void setCurValueOfWorkers(int cur)
    {
        curValueOfWorkers = cur;
    }
   
   public void setStatic()
   {
       It_company it_company2 = new It_company("qwerty");
      // TODO: implement
   }
    public List<string> getVacList()
    {
        return vacancyList;
    }
    public int getMaxValueOfWorkers()
    {
        return maxValueOfWorkers;
    }
    public int getCurValueOfWorkers()
    {
        return curValueOfWorkers;
    }

    public string NameComp
    {
        get { return name; }
        set{name = value;}
    }

    public void companyWorking()
    {
        List<List<string>> allAnswers = new List<List<string>>(1);

        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                preparingVacanciesAndTests();
            }
            if (i == 1)
            {
                choosingCandidates();

            }
            if (i == 0 || i == 2 || i == 4)
            {
                candidateWorking(i, allAnswers);

            }
            if (i == 3)
            {
                testing(allAnswers);

            }
            if (i == 4)
            {
                interview();
            }
        }
    }
   private It_company(string nam)
   {
       hr_manager = new List<Hr_manager>(1);
       technical_manager = new List<Technical_manager>(1);
       hr_manager.Add(new Hr_manager());
       technical_manager.Add(new Technical_manager());
       name = nam;
       vacancyList = new List<string>(1);
       Console.WriteLine("IT-company was created (private)");
   }

   private List<string> vacancyList;
   private string name;
   private static int maxValueOfWorkers;
   private int curValueOfWorkers;
    private Technical_manager getTechManForWork()
    {
        for (int i = 0; i < technical_manager.Count; i++)
	{
		if (technical_manager[i].getState() == "free")
		{
			technical_manager[i].setState("busy");
			return technical_manager[i];
		}
	}
	return technical_manager[0];
    }
	private void preparingVacanciesAndTests()
    {
        Console.WriteLine( "...HR-manager create vacancy list...\n" );
	    vacancyList = hr_manager[0].prepareVacancyList(getMaxValueOfWorkers(), getCurValueOfWorkers());
	    for (int l = 0; l < technical_manager.Count; l++)
	    {
		    Console.WriteLine( "...Technical manager prepare tests...\n" );
		    technical_manager[l].prepareTest(vacancyList);
	    }
    }
	private void choosingCandidates()
    {
        for (int m = 0; m < hr_manager.Count; m++)
	{
		Console.WriteLine("...HR-manager choose candidates...\n" );
		hr_manager[m].chooseCandidates(vacancyList);
	}
    }
	private void candidateWorking(int time, List<List<string>> allAnswers)
    {
        for (int j = 0; j < hr_manager.Count; j++)
	    {
		    for (int k = 0; k < hr_manager[j].candidate.Count; k++)
		    {
			    List<string> answ = new List<string>(1);
			    List<string> questions = new List<string>(1);
			    if (this.hr_manager[k].candidate[j].getState() == "review")
			    {
				    questions = getTechManForWork().getTestForCandidate(hr_manager[j].candidate[k].resume.getCompetence()).getQuestions();
			    }
			    hr_manager[j].candidate[k].getWork(time + 1, questions, answ);
			    if (!(answ.Count == 0))
			    {
				    allAnswers.Add(answ);
			    }
		    }
	    }

    }
	private void testing(List<List<string>> allAnswers)
    {
        for (int q = 0; q < allAnswers.Count; q++)
	    {
		    Console.WriteLine("...Technical manager check test...\n");
		    hr_manager[0].candidate[0].setState(getTechManForWork().checkTest(allAnswers[q]));
	    }
	    allAnswers.Clear();
    }
	private void interview()
    {
        for (int n = 0; n < hr_manager.Count; n++)
	    {
		    for (int p = 0; p < hr_manager[n].candidate.Count; p++)
		    {
			    if (hr_manager[n].candidate[p].getState() == "interview")
			    {
				    Console.WriteLine( "...Technical manager holding interview...\n" );
				    hr_manager[n].candidate[p].setState(getTechManForWork().holdingInterview(hr_manager[n].candidate[p].getComLevel(), hr_manager[n].candidate[p].getWorLevel(), hr_manager[n].candidate[p].getName()));
			    }
		    }
	    }

    }

}