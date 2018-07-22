using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs_version2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start modeling");
            It_company itcompany;
            itcompany = new It_company();
            Candidate candidate;
            candidate = new Candidate();
            itcompany.set();
            Console.WriteLine("End modeling");
            Console.ReadKey();
        }
    }
}
