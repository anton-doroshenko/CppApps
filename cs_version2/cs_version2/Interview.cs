/***********************************************************************
 * Module:  Interview.cs
 * Author:  Anton
 * Purpose: Definition of the Class Interview
 ***********************************************************************/

using System;

public class Interview
{
    public Interview()
    {
        result = false;
        Console.WriteLine("Interview was created (default)");
    }
    Interview(bool res)
    {
        result = res;
        Console.WriteLine("Interview was created (inicialisation)");
    }
	Interview(Interview sInterview)
    {
        result = sInterview.result;
        Console.WriteLine("Interview was created (copy)");
    }
   public void get()
   {
      // TODO: implement
   }

   private bool result;

}