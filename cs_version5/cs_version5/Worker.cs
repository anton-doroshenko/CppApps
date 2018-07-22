using System;
using System.Collections.Generic;


public class Worker
{
    public Worker()
    {
        name = "Name";
    }
    public Worker(string n)
    {
        name = n;
    }
    public Worker(Worker sWorker)
    {
        name = sWorker.name;
    }

    public string getName()
    {
        return name;
    }

    private string name;
}
