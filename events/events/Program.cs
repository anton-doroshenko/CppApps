using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace events
{
    class Program
    {
        static void Main(string[] args)
        {
            MyClass1 obj1 = new MyClass1();
            MyClass2 obj2 = new MyClass2();

            obj1.EventName += obj2.Method;

            obj1.MainMethod();
        }
    }

    public class MyClass1
    {
        public delegate void DelName();
        public event DelName EventName;
        public void MainMethod()
        {
            if(true)
            {
                EventName();
            }
            //....
        }
    }

    public class MyClass2
    {
        public void Method()
        {
            Console.WriteLine("Some shit");
            Console.ReadKey();
        }
    }
}
