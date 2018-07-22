/***********************************************************************
 * Module:  Hr_manager.cs
 * Author:  Anton
 * Purpose: Definition of the Class Hr_manager
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class Hr_manager : Worker
{
    public Hr_manager() : base() 
    {
        //name = "n";
        name = "dddd";
        Console.WriteLine("HR-manager was created (default)");
    }
	public Hr_manager(string n) : base(n)
    {
        //name = n;
        Console.WriteLine("HR-manager was created (inicialisation)");
    }
	public Hr_manager(Hr_manager sHr_manager)
    {
        //name = sHr_manager.name;
        Console.WriteLine("HR-manager was created (copy)");
    }
   public List<string> prepareVacancyList(int max, int cur)
    {
       List<string> list = new List<string>(1);
	for (int i = 0; i < (max - cur); i++)
	{
		string vac;
		vac = Console.ReadLine();
		list.Add(vac);
	}
	return list;
    }

	public void chooseCandidates(List<string> list)
   {
       for (int i = 0; i < candidate.Count; i++)
       {
           for (int j = 0; j < list.Count; j++)
           {
               if (candidate[i].resume.getCompetence() == list[j])
               {
                   candidate[i].setState("review");
                   break;
               }
           }
       }
   }

   public List<Candidate> candidate = new List<Candidate>(1);
    private string name;
    public  static string operator + (Hr_manager left, string n)
	{
        return left.name + n;
	}
    public static string operator -(Hr_manager left, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (left.name.Length > 0)
            {
                left.name.Remove(left.name.Length - 1);
            }
        }
        return left.name;
    }
}