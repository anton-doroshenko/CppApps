/***********************************************************************
 * Module:  Test.cs
 * Author:  Anton
 * Purpose: Definition of the Class Test
 ***********************************************************************/

using System;

public class Test
{
    public Test()
    {
        type = "type";
        result = false;
        Console.WriteLine("Test was created (dafault)");
    }
    public Test(string typ, bool res)
    {
        type = typ;
        result = res;
        Console.WriteLine("Test was created (inicialisation)");
    }
    public Test(Test sTest)
    {
        type = sTest.type;
        result = sTest.result;
        Console.WriteLine("Test was created (copy)");
    }
   public void get()
   {
      // TODO: implement
   }
   
   public void set()
   {
      // TODO: implement
   }

   private string type;
   private bool result;

}