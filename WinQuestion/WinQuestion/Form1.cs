using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinQuestion
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            spData.Text = Convert.ToString(System.DateTime.Today.ToLongDateString());
        }

        private void btnyes_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Mbi і не сумнівалися, що Ви так думаєте!");
        }

        private void btnno_Click(object sender, EventArgs e)
        {

        }

        private void btnno_MouseMove(object sender, MouseEventArgs e)
        {
            btnno.Top -= e.Y;
            btnno.Left += e.X;
            if (btnno.Top < -10 || btnno.Top > 100) btnno.Top = 60;
            if (btnno.Left < -80 || btnno.Left > 250) btnno.Left = 120;

        }

        private void toolStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch (e.ClickedItem.Tag.ToString())
            {
                case "NewDoc":
                    MessageBox.Show("Mbi і не сумнівалися, що Ви так думаєте!");
                    break;
                case "Cascade": this.LayoutMdi(System.Windows.Forms.MdiLayout.Cascade);
                    
                    break;
                case "Title": this.LayoutMdi(System.Windows.Forms.MdiLayout.TileHorizontal);
                    this.spWin.Text = "Windows is horizontal";
                    break;
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            this.spWin.Text = "Windows is cascade";
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            this.spWin.Text = "Windows is horizontal";
        }
    }
}
