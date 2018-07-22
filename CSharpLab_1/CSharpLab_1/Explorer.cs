using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpLab_1
{
    /// <summary>
    /// Клас, що відслідковує зміни на матеріально-технічній базі
    /// </summary>
    class Explorer
    {
        /// <summary>
        /// Кількість змін
        /// </summary>
        private int changes;
        /// <summary>
        /// Конструктор за замовчуванням
        /// </summary>
        public Explorer()
        {
            changes = 0;
        }
        /// <summary>
        /// гетер
        /// </summary>
        /// <returns>Кількість змін</returns>
        public int GetChanges()
        {
            return changes;
        }
        /// <summary>
        /// Обробка події покупки
        /// </summary>
        public void ChangeBought()
        {
            changes++;
            Console.WriteLine("Changing (Bought)");
        }
        /// <summary>
        /// Обробка події поломки
        /// </summary>
        public void ChangeBrouken()
        {
            this.changes++;
            Console.WriteLine("Changing (Brouken)");
        }
        /// <summary>
        /// Обробка події списання
        /// </summary>
        public void ChangeAmortize()
        {
            this.changes++;
            Console.WriteLine("Changing (Amortize)");
        }
    }
}
