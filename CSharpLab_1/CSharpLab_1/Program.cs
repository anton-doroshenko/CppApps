//7.Розробити програму, яка відслідковує зміни в кількості обладнання на кафедрі АСОІУ.
//Для цього створити клас, об’єкт якого використовуватиметься при оновленні матеріально-технічної бази 
//(МТБ). В цьому класі передбачити події, які виникатимуть при змінах кількості обладнання внаслідок 
//закупівель, списання, поломок тощо, та делегат, який посилатиметься на функції, що здійснюють облік 
//закупівель, списання та виходу з ладу обладнання. Створити клас, який відслідковує зміни в МТБ,
//в якому включити метод, що викликатиметься кожного разу, як відбуватимуться такі зміни. 

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CSharpLab_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Lab 1\nauthor: Anton Doroshenko IS-52\n"
                       + "==============================");

            //введення назви файлу з інформацією
            Console.Write("\nEnter data file name: ");
            string filename = Console.ReadLine();
            //зчитування даних з файлу
            FileStream file1 = new FileStream(filename, FileMode.Open);
            StreamReader reader = new StreamReader(file1);
            string[] data = reader.ReadLine().ToString().Split(' ');
            //Створення матеріально-технічної бази та відслідковувача
            MTB mtb = new MTB(int.Parse(data[0]));
            Explorer explorer = new Explorer();
            //Відбуваються події
            for (int i = 0; i < int.Parse(data[1]); i++)
            {
                mtb.Amortize += explorer.ChangeAmortize;
            }

            for (int j = 0; j < int.Parse(data[2]); j++)
            {
                mtb.Bought += explorer.ChangeBought;
            }

            for (int k = 0; k < int.Parse(data[3]); k++)
            {
                mtb.Brouken += explorer.ChangeBrouken;
            }

            mtb.EventStart();
            //Виведення результатів
            Console.WriteLine("\nAmount of changes: {0}", explorer.GetChanges());
            Console.WriteLine("Amount of furniture after changing: {0}", mtb.GetAmount());
            Console.ReadKey();
        }
    }
}
