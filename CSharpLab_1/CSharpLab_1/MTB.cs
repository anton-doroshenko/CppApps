using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpLab_1
{
    /// <summary>
    /// Клас матеріально-технічної бази
    /// </summary>
    class MTB
    {
        /// <summary>
        /// Кількість обладнання
        /// </summary>
        private int amount;
        /// <summary>
        /// Конструктор ініціалізації
        /// </summary>
        /// <param name="amount">Кількість обладнання</param>
        public MTB(int amount)
        {
            this.amount = amount;
            Console.WriteLine("Mtb has been created. Starting amount of furniture is {0} \n", amount);
        }
        /// <summary>
        /// Делегат
        /// </summary>
        public delegate void OnChange();
        /// <summary>
        /// Подія закупівлі
        /// </summary>
        public event OnChange Bought;
        /// <summary>
        /// Подія поломки
        /// </summary>
        public event OnChange Brouken;
        /// <summary>
        /// Подія списання
        /// </summary>
        public event OnChange Amortize;
        /// <summary>
        /// Гетер
        /// </summary>
        /// <returns>Кількість обладнання</returns>
        public int GetAmount()
        {
            return amount;
        }
        /// <summary>
        /// Обробник подій
        /// </summary>
        public void EventStart()
        {
            if(Bought != null)
            {
                Bought();
                this.amount++;
            }
            if(Brouken != null)
            {
                Brouken();
                amount--;
            }
            if(Amortize != null)
            {
                Amortize();
                amount--;
            }
        }
    }
}
