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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            task_3 tsk3 = new task_3();
            tsk3.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Task_1 tsk1 = new Task_1();
            tsk1.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Task_2 tsk2 = new Task_2();
            tsk2.Show();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            MessageBox.Show("Author: Anton Doroshenko");
        }
    }
}
