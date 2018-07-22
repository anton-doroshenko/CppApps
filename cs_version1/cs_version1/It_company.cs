/***********************************************************************
 * Module:  It_company.cs
 * Author:  Anton
 * Purpose: Definition of the Class It_company
 ***********************************************************************/

using System;
using System.Collections.Generic;

public class It_company
{
   public void get()
   {
      // TODO: implement
   }
   
   public void set()
   {
      // TODO: implement
   }

   public System.Collections.ArrayList technical_manager;
   
   /// <pdGenerated>default getter</pdGenerated>
   public System.Collections.ArrayList GetTechnical_manager()
   {
      if (technical_manager == null)
         technical_manager = new System.Collections.ArrayList();
      return technical_manager;
   }
   
   /// <pdGenerated>default setter</pdGenerated>
   public void SetTechnical_manager(System.Collections.ArrayList newTechnical_manager)
   {
      RemoveAllTechnical_manager();
      foreach (Technical_manager oTechnical_manager in newTechnical_manager)
         AddTechnical_manager(oTechnical_manager);
   }
   
   /// <pdGenerated>default Add</pdGenerated>
   public void AddTechnical_manager(Technical_manager newTechnical_manager)
   {
      if (newTechnical_manager == null)
         return;
      if (this.technical_manager == null)
         this.technical_manager = new System.Collections.ArrayList();
      if (!this.technical_manager.Contains(newTechnical_manager))
         this.technical_manager.Add(newTechnical_manager);
   }
   
   /// <pdGenerated>default Remove</pdGenerated>
   public void RemoveTechnical_manager(Technical_manager oldTechnical_manager)
   {
      if (oldTechnical_manager == null)
         return;
      if (this.technical_manager != null)
         if (this.technical_manager.Contains(oldTechnical_manager))
            this.technical_manager.Remove(oldTechnical_manager);
   }
   
   /// <pdGenerated>default removeAll</pdGenerated>
   public void RemoveAllTechnical_manager()
   {
      if (technical_manager != null)
         technical_manager.Clear();
   }
   public System.Collections.ArrayList hr_manager;
   
   /// <pdGenerated>default getter</pdGenerated>
   public System.Collections.ArrayList GetHr_manager()
   {
      if (hr_manager == null)
         hr_manager = new System.Collections.ArrayList();
      return hr_manager;
   }
   
   /// <pdGenerated>default setter</pdGenerated>
   public void SetHr_manager(System.Collections.ArrayList newHr_manager)
   {
      RemoveAllHr_manager();
      foreach (Hr_manager oHr_manager in newHr_manager)
         AddHr_manager(oHr_manager);
   }
   
   /// <pdGenerated>default Add</pdGenerated>
   public void AddHr_manager(Hr_manager newHr_manager)
   {
      if (newHr_manager == null)
         return;
      if (this.hr_manager == null)
         this.hr_manager = new System.Collections.ArrayList();
      if (!this.hr_manager.Contains(newHr_manager))
         this.hr_manager.Add(newHr_manager);
   }
   
   /// <pdGenerated>default Remove</pdGenerated>
   public void RemoveHr_manager(Hr_manager oldHr_manager)
   {
      if (oldHr_manager == null)
         return;
      if (this.hr_manager != null)
         if (this.hr_manager.Contains(oldHr_manager))
            this.hr_manager.Remove(oldHr_manager);
   }
   
   /// <pdGenerated>default removeAll</pdGenerated>
   public void RemoveAllHr_manager()
   {
      if (hr_manager != null)
         hr_manager.Clear();
   }

   private List<string> vacancyList;
   private string name;

}