using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            newTeacher = new Teacher(this);
            newTeacher.MdiParent = this;
            newTeacher.Show();
        }

        private bool IsOpen()
        {
            foreach (Form f in Application.OpenForms)
            {
                if (f.Name == "Teacher")
                {
                    return true;
                }
            }
            return false;
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "txt files (*.txt)|*.txt";
            if (saveFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK 
                && saveFileDialog1.FileName.Length > 0 && IsOpen())
            {
                string[] Info = {newTeacher.getText1(), newTeacher.getText2(), newTeacher.getText3(), 
                                    newTeacher.getText4(), newTeacher.getText5()};
                File.WriteAllLines(saveFileDialog1.FileName, Info);
                MessageBox.Show("File is saved!");
            }
            else
            {
                MessageBox.Show("form is`n open!");
            }

        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }
    }
}
