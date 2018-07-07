using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        DataGridView dgv;
        DataGridView dgv2;
        ComboBox SourceName;
        //ComboBox SourceTask;
        Form tf;
        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
        }
        private void Form2_Load(object sender, EventArgs e)
        {
            tf = Application.OpenForms["MainForm"].FindForm();
            foreach (Control con in tf.Controls)
            {
                if (con.Name == "dataGridView1")
                    dgv = (DataGridView)con;
                if (con.Name == "dataGridView2")
                    dgv2 = (DataGridView)con;
                if (con.Name == "SourceName")
                    SourceName = (ComboBox)con;
                
            }
        }
        public System.Windows.Forms.ListBox exeNameBox = new System.Windows.Forms.ListBox();
        public System.Windows.Forms.ListBox exeNumTask = new System.Windows.Forms.ListBox();
        public System.Windows.Forms.ListBox exeFileExe = new System.Windows.Forms.ListBox();

        public System.Windows.Forms.ListBox testTaskDirBox = new System.Windows.Forms.ListBox();
        public System.Windows.Forms.ListBox testTaskFileBox = new System.Windows.Forms.ListBox();



        public System.Windows.Forms.ListBox outputOriginDirBox = new System.Windows.Forms.ListBox();
        public System.Windows.Forms.ListBox outputOriginFileBox = new System.Windows.Forms.ListBox();



        public DirectoryInfo inputInfo;
        public DirectoryInfo outputInfo;
        private void loadInput_Click(object sender, EventArgs e)
        {

            DialogResult dr = folderBrowserDialog1.ShowDialog();


            if (dr == DialogResult.OK)
            {
                testTaskDirBox.Items.Clear();
                listBox1.Items.Clear();
                listBox1.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                testTaskDirBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
                if ( dgv.ColumnCount == 1)
                {

                    for (int i = 0; i < testTaskDirBox.Items.Count; i++)
                    {
                        dgv.Columns.Add("Column" + i.ToString(), "Задача" + " " + (i + 1).ToString());
                    }
                   
                  
                  
                }
            }
        }

        private void loadOutputOrigin_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();


            if (dr == DialogResult.OK)
            {
                listBox2.Items.Clear();

                outputOriginDirBox.Items.Clear();
                listBox2.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                outputOriginDirBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
            }
        }

        private void loadExe_Click(object sender, EventArgs e)
        {

            DialogResult dr = folderBrowserDialog1.ShowDialog();


            if (dr == DialogResult.OK)
            {

                listBox3.Items.Clear();
                
                exeNameBox.Items.Clear();
                listBox3.Items.Add(folderBrowserDialog1.SelectedPath.ToString());

                exeNameBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
                if (dgv.RowCount == 1)
                {
                    for (int i = 0; i < exeNameBox.Items.Count; i++)
                    {
                        FileInfo fi = new FileInfo(exeNameBox.Items[i].ToString());
                        dgv.Rows.Add();
                        dgv2.Rows.Add();
                        dgv[0, i].Value = fi.Name;
                        dgv2[0, i].Value = fi.Name;
                        SourceName.Items.Add(fi.Name);
                    }
                }
            }
        }

        private void loadInputSchool_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();
            if (dr == DialogResult.OK)
            {
                listBox4.Items.Clear();
                listBox4.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                inputInfo = new DirectoryInfo(folderBrowserDialog1.SelectedPath);

            }
        }

        private void loadOutput_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();
            if (dr == DialogResult.OK)
            {
                listBox5.Items.Clear();
                outputInfo = new DirectoryInfo(folderBrowserDialog1.SelectedPath);
                listBox5.Items.Add(folderBrowserDialog1.SelectedPath.ToString());

            }
        }

        private void prizeTime_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Char.IsNumber(e.KeyChar)) || (e.KeyChar == (char)ConsoleKey.Backspace) || (e.KeyChar == ','))
                return;
            e.Handled = true;
        }

        private void MaxBall_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Char.IsNumber(e.KeyChar)) || (e.KeyChar == (char)ConsoleKey.Backspace) || (e.KeyChar == ','))
                return;
            e.Handled = true;
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Char.IsNumber(e.KeyChar)) || (e.KeyChar == (char)ConsoleKey.Backspace) || (e.KeyChar == 'j'))
                return;
            e.Handled = true;
        }

        private void KFF_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Char.IsNumber(e.KeyChar)) || (e.KeyChar == (char)ConsoleKey.Backspace) || (e.KeyChar == 'j'))
                return;
            e.Handled = true;
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Char.IsNumber(e.KeyChar)) || (e.KeyChar == (char)ConsoleKey.Backspace) || (e.KeyChar == 'j'))
                return;
            e.Handled = true;
        }

      
    }
}
