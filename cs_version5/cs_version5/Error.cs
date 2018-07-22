using System;
using System.Collections.Generic;

public class Error : Exception
{
    public Error(int t)
    {
        type = t;
        //str = s;
    }
    public int type;
    public string str;

    //public void input(string str)
    //{
    //    bool flag = false;

    //    while (true)
    //    {
    //        for (int i = 0; i < str.Length; i++)
    //        {
    //            //flag = ((*str)[i] < 48 || (*str)[i] > 57) ? true : false;
    //            if (str[i] < 48 || str[i] > 57)
    //            {
    //                flag = true;
    //                break;
    //            }
    //            else
    //            {
    //                flag = false;
    //            }
    //        }
    //        if (flag)
    //        {
    //            Console.WriteLine("Incorrect input, please try again\n");
    //            str = Console.ReadLine();
    //        }
    //        else
    //        {
    //            break;
    //        }
    //    }
    //}

    public void valOfCandidates()
    {
        Console.WriteLine("HR - manager can`t comunicate with more than 5 Candidates...");
    }

    public void valOfWorkers()
    {
        Console.WriteLine("Curent value of workers can`t be bigger than max value of workers");
    }


    public void err()
    {
        switch (type)
        {
            //case 1: input(str); break;
            case 2: valOfCandidates(); break;
            case 3: valOfWorkers(); break;
        }
    }
}
