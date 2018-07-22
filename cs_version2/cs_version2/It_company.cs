/***********************************************************************
 * Module:  It_company.cs
 * Author:  Anton
 * Purpose: Definition of the Class It_company
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class It_company
{
    public List<Hr_manager> hr_manager;
    public List<Technical_manager> technical_manager;
    public It_company()
    {
        hr_manager = new List<Hr_manager>(1);
        technical_manager = new List<Technical_manager>(1);
        hr_manager.Add(new Hr_manager());
        technical_manager.Add(new Technical_manager());
        vacancyList = new List<string>(1);
        name = "Name";
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
        Console.WriteLine("IT-company was created (inicialisation)");
    }
	public It_company(It_company sIt_company)
    {
        hr_manager = sIt_company.hr_manager;
        technical_manager = sIt_company.technical_manager;
        name = sIt_company.name;
        vacancyList = sIt_company.vacancyList;
        Console.WriteLine("IT-company was created (copy)");
    }

    static It_company()
    {
        maxValueOfWorkers = 4;
        Console.WriteLine("Static constructor");
    }
   public void get()
   {
      // TODO: implement
   }
   
   public void set()
   {
       It_company it_company2 = new It_company("qwerty");
      // TODO: implement
   }

   
   
   /// <pdGenerated>default getter</pdGenerated>
   //public System.Collections.ArrayList GetTechnical_manager()
   //{
   //   if (technical_manager == null)
   //      technical_manager = new System.Collections.ArrayList();
   //   return technical_manager;
   //}
   
   ///// <pdGenerated>default setter</pdGenerated>
   //public void SetTechnical_manager(System.Collections.ArrayList newTechnical_manager)
   //{
   //   RemoveAllTechnical_manager();
   //   foreach (Technical_manager oTechnical_manager in newTechnical_manager)
   //      AddTechnical_manager(oTechnical_manager);
   //}
   
   ///// <pdGenerated>default Add</pdGenerated>
   //public void AddTechnical_manager(Technical_manager newTechnical_manager)
   //{
   //   if (newTechnical_manager == null)
   //      return;
   //   if (this.technical_manager == null)
   //      this.technical_manager = new System.Collections.ArrayList();
   //   if (!this.technical_manager.Contains(newTechnical_manager))
   //      this.technical_manager.Add(newTechnical_manager);
   //}
   
   ///// <pdGenerated>default Remove</pdGenerated>
   //public void RemoveTechnical_manager(Technical_manager oldTechnical_manager)
   //{
   //   if (oldTechnical_manager == null)
   //      return;
   //   if (this.technical_manager != null)
   //      if (this.technical_manager.Contains(oldTechnical_manager))
   //         this.technical_manager.Remove(oldTechnical_manager);
   //}
   
   ///// <pdGenerated>default removeAll</pdGenerated>
   //public void RemoveAllTechnical_manager()
   //{
   //   if (technical_manager != null)
   //      technical_manager.Clear();
   //}
   
   
   /// <pdGenerated>default getter</pdGenerated>
   //public System.Collections.ArrayList GetHr_manager()
   //{
   //   if (hr_manager == null)
   //      hr_manager = new System.Collections.ArrayList();
   //   return hr_manager;
   //}
   
   ///// <pdGenerated>default setter</pdGenerated>
   //public void SetHr_manager(System.Collections.ArrayList newHr_manager)
   //{
   //   RemoveAllHr_manager();
   //   foreach (Hr_manager oHr_manager in newHr_manager)
   //      AddHr_manager(oHr_manager);
   //}
   
   ///// <pdGenerated>default Add</pdGenerated>
   //public void AddHr_manager(Hr_manager newHr_manager)
   //{
   //   if (newHr_manager == null)
   //      return;
   //   if (this.hr_manager == null)
   //      this.hr_manager = new System.Collections.ArrayList();
   //   if (!this.hr_manager.Contains(newHr_manager))
   //      this.hr_manager.Add(newHr_manager);
   //}
   
   ///// <pdGenerated>default Remove</pdGenerated>
   //public void RemoveHr_manager(Hr_manager oldHr_manager)
   //{
   //   if (oldHr_manager == null)
   //      return;
   //   if (this.hr_manager != null)
   //      if (this.hr_manager.Contains(oldHr_manager))
   //         this.hr_manager.Remove(oldHr_manager);
   //}
   
   ///// <pdGenerated>default removeAll</pdGenerated>
   //public void RemoveAllHr_manager()
   //{
   //   if (hr_manager != null)
   //      hr_manager.Clear();
   //}

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

}