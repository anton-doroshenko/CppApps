using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CSharpLab2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Lab 2\nauthor: Anton Doroshenko IS-52\n" 
                                   + "==============================");
            //введення назви файлу з інформацією
            Console.Write("\nEnter data file name: ");
            string filename = Console.ReadLine();
            //зчитування даних з файлу
            FileStream file1 = new FileStream(filename, FileMode.Open);
            StreamReader reader = new StreamReader(file1); 
            string[] data = reader.ReadLine().ToString().Split(' ');
            //створення цілочисельного масиву
            IntArray arr1 = new IntArray(data.Length);
            //перевірка обробки помилки виходу за межі масиву
            Console.WriteLine("\nInput number of index that bigger than {0} (index out of range exeption)", arr1.NewLength());
            Console.WriteLine(arr1[int.Parse(Console.ReadLine())]);
            //ініціалізація масиву
            for (int i = 0; i < arr1.NewLength(); i++)
            {
                //arr1[i] = int.Parse(Console.ReadLine());
                arr1[i] = int.Parse(data[i]);
            }
            //виведення масиву
            Console.Write("\nYour array: ");
            for (int i = 0; i < arr1.NewLength(); i++)
            {
                Console.Write(arr1[i] + " ");
            }
            Console.WriteLine();
            Console.Write("\nSum of elements of your array: ");
            Console.WriteLine(arr1.Sum);
            Console.Write("\nMiddle arithmetic of elements of your array: ");
            Console.WriteLine(arr1.mid);
            Console.ReadKey();
        }
    }
}
