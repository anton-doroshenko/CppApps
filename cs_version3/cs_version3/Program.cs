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
            itcompany.NameComp = "name";
            Candidate candidate;
            candidate = new Candidate();
            itcompany.setStatic();
            itcompany.hr_manager[0].candidate.Add(candidate);
            itcompany.companyWorking();
            Console.WriteLine("End modeling");
            Console.ReadKey();
        }
    }
}
