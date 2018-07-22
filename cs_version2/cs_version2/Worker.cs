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

    private string name;
}
