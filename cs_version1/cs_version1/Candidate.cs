/***********************************************************************
 * Module:  Candidate.cs
 * Author:  Anton
 * Purpose: Definition of the Class Candidate
 ***********************************************************************/

using System;

public class Candidate
{
   public void prepareResume()
   {
      // TODO: implement
   }
   
   public void takeTest()
   {
      // TODO: implement
   }
   
   public void passInterview()
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
   
   public void getWork()
   {
      // TODO: implement
   }

   public System.Collections.ArrayList resume;
   
   /// <pdGenerated>default getter</pdGenerated>
   public System.Collections.ArrayList GetResume()
   {
      if (resume == null)
         resume = new System.Collections.ArrayList();
      return resume;
   }
   
   /// <pdGenerated>default setter</pdGenerated>
   public void SetResume(System.Collections.ArrayList newResume)
   {
      RemoveAllResume();
      foreach (Resume oResume in newResume)
         AddResume(oResume);
   }
   
   /// <pdGenerated>default Add</pdGenerated>
   public void AddResume(Resume newResume)
   {
      if (newResume == null)
         return;
      if (this.resume == null)
         this.resume = new System.Collections.ArrayList();
      if (!this.resume.Contains(newResume))
         this.resume.Add(newResume);
   }
   
   /// <pdGenerated>default Remove</pdGenerated>
   public void RemoveResume(Resume oldResume)
   {
      if (oldResume == null)
         return;
      if (this.resume != null)
         if (this.resume.Contains(oldResume))
            this.resume.Remove(oldResume);
   }
   
   /// <pdGenerated>default removeAll</pdGenerated>
   public void RemoveAllResume()
   {
      if (resume != null)
         resume.Clear();
   }

   private int commutabilityLevel;
   private int worryingLevel;
   private bool work;

}