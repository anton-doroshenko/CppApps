using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Teacher : Form
    {
        public Teacher(MainForm ParrentForm)
        {
            InitializeComponent();
        }
        public string getText1()
        {
            return textBox1.Text;
        }
        public string getText2()
        {
            return textBox2.Text;
        }
        public string getText3()
        {
            return textBox3.Text;
        }
        public string getText4()
        {
            return textBox4.Text;
        }
        public string getText5()
        {
            return textBox5.Text;
        }
    }
}
