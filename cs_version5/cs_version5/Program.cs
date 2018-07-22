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
            Candidate candidate2;
            candidate2 = new Candidate();
            itcompany.setStatic();
            Console.WriteLine(itcompany.hr_manager[0] + "Petrov");
            Console.WriteLine(itcompany.hr_manager[0] - 2);
            if (candidate > candidate2)
            {
                Console.WriteLine("candidate > candidate2");
            }
            else if (candidate2 < candidate)
            {
                Console.WriteLine("candidate2 < candidate");
            }
            else
            {
                Console.WriteLine("candidate2 = candidate");
            }
            if (itcompany == itcompany)
            {
                Console.WriteLine("Current value of workers in this companies are equal");
            }

            else if (itcompany != itcompany)
            {
                Console.WriteLine("Current value of workers in this companies are different");
            }
            try
            {
                if (itcompany.hr_manager[0].candidate.Count > 5)
                {
                    throw new Error(2);
                }
                itcompany.hr_manager[0].candidate.Add(candidate);
            }
            catch(Error e)
            {
                e.err();
            }

            itcompany.companyWorking();
            Console.WriteLine("End modeling");
            Console.ReadKey();
        }
    }
}
