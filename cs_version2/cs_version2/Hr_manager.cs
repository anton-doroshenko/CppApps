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
   public void prepareVacancyList()
   {
      // TODO: implement
   }
   
   public void chooseCandidates()
   {
      // TODO: implement
   }
   
   public void get()
   {
      // TODO: implement
   }
   
   public void set()
   {
      // TODO: implement
   }

   public List<Candidate> candidate;
   
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

   private string name;

}