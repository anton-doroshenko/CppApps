using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (maskedTextBox2.Text == "")
            {
                MessageBox.Show("You must fill in the field!");
            }
            else
            {
                string str = string.Empty;
                List<string> items = new List<string>();
                using (System.IO.StreamReader reader = System.IO.File.OpenText(@"inicialize.txt"))
                {
                    while(true)
                    {
                        str = reader.ReadLine();
                        if (str == null) break;
                        items.Add(str);
                    }
                }
                items[6] = maskedTextBox2.Text;

                using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"inicialize.txt"))
                {
                    foreach(string s in items)
                    {
                        file.WriteLine(s);
                    }
                }
                MessageBox.Show(maskedTextBox2.Text);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "" || textBox2.Text == "" || maskedTextBox1.Text == "+1")
            {
                MessageBox.Show("You must fill in all the fields!");
            }
            else
            {
                string str = string.Empty;
                List<string> items = new List<string>();
                MessageBox.Show(maskedTextBox2.Text);
                using (System.IO.StreamReader reader = System.IO.File.OpenText(@"inicialize.txt"))
                {
                    while (true)
                    {
                        str = reader.ReadLine();
                        if (str == null) break;
                        items.Add(str);
                    }
                }
                items[3] = textBox1.Text;
                items[4] = textBox2.Text;
                items[5] = maskedTextBox1.Text;

                using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"inicialize.txt"))
                {
                    foreach (string s in items)
                    {
                        file.WriteLine(s);
                    }
                }
                MessageBox.Show("Changes are saved!");
            }
        }
    }
}
