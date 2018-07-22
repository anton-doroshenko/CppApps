/***********************************************************************
 * Module:  Technical_manager.cs
 * Author:  Anton
 * Purpose: Definition of the Class Technical_manager
 ***********************************************************************/

using System;

public class Technical_manager
{
   public void prepareTest()
   {
      // TODO: implement
   }
   
   public void checkTest()
   {
      // TODO: implement
   }
   
   public void holdingInterview()
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

   public System.Collections.ArrayList interview;
   
   /// <pdGenerated>default getter</pdGenerated>
   public System.Collections.ArrayList GetInterview()
   {
      if (interview == null)
         interview = new System.Collections.ArrayList();
      return interview;
   }
   
   /// <pdGenerated>default setter</pdGenerated>
   public void SetInterview(System.Collections.ArrayList newInterview)
   {
      RemoveAllInterview();
      foreach (Interview oInterview in newInterview)
         AddInterview(oInterview);
   }
   
   /// <pdGenerated>default Add</pdGenerated>
   public void AddInterview(Interview newInterview)
   {
      if (newInterview == null)
         return;
      if (this.interview == null)
         this.interview = new System.Collections.ArrayList();
      if (!this.interview.Contains(newInterview))
         this.interview.Add(newInterview);
   }
   
   /// <pdGenerated>default Remove</pdGenerated>
   public void RemoveInterview(Interview oldInterview)
   {
      if (oldInterview == null)
         return;
      if (this.interview != null)
         if (this.interview.Contains(oldInterview))
            this.interview.Remove(oldInterview);
   }
   
   /// <pdGenerated>default removeAll</pdGenerated>
   public void RemoveAllInterview()
   {
      if (interview != null)
         interview.Clear();
   }
   public System.Collections.ArrayList test;
   
   /// <pdGenerated>default getter</pdGenerated>
   public System.Collections.ArrayList GetTest()
   {
      if (test == null)
         test = new System.Collections.ArrayList();
      return test;
   }
   
   /// <pdGenerated>default setter</pdGenerated>
   public void SetTest(System.Collections.ArrayList newTest)
   {
      RemoveAllTest();
      foreach (Test oTest in newTest)
         AddTest(oTest);
   }
   
   /// <pdGenerated>default Add</pdGenerated>
   public void AddTest(Test newTest)
   {
      if (newTest == null)
         return;
      if (this.test == null)
         this.test = new System.Collections.ArrayList();
      if (!this.test.Contains(newTest))
         this.test.Add(newTest);
   }
   
   /// <pdGenerated>default Remove</pdGenerated>
   public void RemoveTest(Test oldTest)
   {
      if (oldTest == null)
         return;
      if (this.test != null)
         if (this.test.Contains(oldTest))
            this.test.Remove(oldTest);
   }
   
   /// <pdGenerated>default removeAll</pdGenerated>
   public void RemoveAllTest()
   {
      if (test != null)
         test.Clear();
   }

   private string name;
   private int requirementLevel;
   private int commutabilityLevel;

}