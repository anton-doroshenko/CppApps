/***********************************************************************
 * Module:  Test.cs
 * Author:  Anton
 * Purpose: Definition of the Class Test
 ***********************************************************************/

using System;
using System.Collections.Generic;

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
   public string getType()
    {
        return type;
    }
	public List<string> getQuestions()
   {
       return questions;
   }
   
    public void setType(string t)
   {
       type = t;
   }
	public void setResult(bool r)
    {
        result = r;
    }
	public void setQuestions(List<string> q)
    {
        questions = q;
    }

   private string type;
   private bool result;
   List<string> questions;
}