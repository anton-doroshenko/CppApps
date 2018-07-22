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
   
   /// <pdGenerated>default getter</pdGenerated>
   //public System.Collections.ArrayList GetCandidate()
   //{
   //   if (candidate == null)
   //      candidate = new System.Collections.ArrayList();
   //   return candidate;
   //}
   
   ///// <pdGenerated>default setter</pdGenerated>
   //public void SetCandidate(System.Collections.ArrayList newCandidate)
   //{
   //   RemoveAllCandidate();
   //   foreach (Candidate oCandidate in newCandidate)
   //      AddCandidate(oCandidate);
   //}
   
   ///// <pdGenerated>default Add</pdGenerated>
   //public void AddCandidate(Candidate newCandidate)
   //{
   //   if (newCandidate == null)
   //      return;
   //   if (this.candidate == null)
   //      this.candidate = new System.Collections.ArrayList();
   //   if (!this.candidate.Contains(newCandidate))
   //      this.candidate.Add(newCandidate);
   //}
   
   ///// <pdGenerated>default Remove</pdGenerated>
   //public void RemoveCandidate(Candidate oldCandidate)
   //{
   //   if (oldCandidate == null)
   //      return;
   //   if (this.candidate != null)
   //      if (this.candidate.Contains(oldCandidate))
   //         this.candidate.Remove(oldCandidate);
   //}
   
   ///// <pdGenerated>default removeAll</pdGenerated>
   //public void RemoveAllCandidate()
   //{
   //   if (candidate != null)
   //      candidate.Clear();
   //}

   //private string name;

}