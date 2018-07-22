using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpLab2
{
    /// <summary>
    /// Клас цілочисельного масиву
    /// </summary>
    class IntArray
    {
        /// <summary>
        /// Конструктор за замовчуванням
        /// </summary>
        public IntArray()
        {
            this.arr = new int[0];
        }
        /// <summary>
        /// Конструктор ініціалізації
        /// </summary>
        /// <param name="size">Розмір масиву</param>
        public IntArray(int size)
        {
            this.arr = new int[size];
        }
        /// <summary>
        /// масив чисел
        /// </summary>
        private int[] arr;
        /// <summary>
        /// Індексатор
        /// </summary>
        /// <param name="index">індекс елемента</param>
        /// <returns>Значення елмента за вказаним індексом</returns>
        public int this[int index]
        {
            get
            {
                int res = int.MinValue;
                try
                {
                    res = arr[index];
                }
                catch(IndexOutOfRangeException e)
                {
                    Console.WriteLine(e.Message);
                    //throw new ArgumentOutOfRangeException("index parameter is out of range.", e);
                    Console.WriteLine("Error: array hasn`t {0} element", index);
                }
                return res;
            }
            set
            {
                if (index > -1 && index < arr.Length)
                {
                    arr[index] = value;
                }
            }
        }
        /// <summary>
        /// Сума всіх елементів масиву
        /// </summary>
        public int Sum
        {
            get
            {
                int res = 0;
                for (int i = 0; i < arr.Length; i++)
                {
                    res += arr[i];
                }
                return res;
            }
        }
        /// <summary>
        /// довжина
        /// </summary>
        /// <returns>довжину масиву</returns>
        public int NewLength()
        {
            return this.arr.Length;
        }
        /// <summary>
        /// середнє арифметичне
        /// </summary>
        public float mid
        {
            get
            {
                if (arr.Length > 0)
                {
                    return (float)this.Sum / arr.Length;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}
