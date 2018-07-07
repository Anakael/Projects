using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;



namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        


        DataGridViewCellStyle dg = new DataGridViewCellStyle();
            
        public FileInfo fi;

        private ListBox exeNameBox = new ListBox();
        ListBox exeNumTask = new ListBox();
        private ListBox exeFileExe = new ListBox();

        private ListBox testTaskDirBox = new ListBox();      
        private ListBox testTaskFileBox = new ListBox();

        

        private ListBox outputOriginDirBox = new ListBox();
        private ListBox outputOriginFileBox = new ListBox();

        

        DirectoryInfo inputInfo;
        DirectoryInfo outputInfo;

        private void loadInput_Click(object sender, EventArgs e)
        {

            DialogResult dr = folderBrowserDialog1.ShowDialog();

            testTaskDirBox.Items.Clear();


            if (dr == DialogResult.OK)
            {
                listBox1.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                testTaskDirBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
            }
            dataGridView1.Columns.Add("NamePup", "Ф.И Участника");
            for (int i = 0; i < testTaskDirBox.Items.Count; i++)
            {
                dataGridView1.Columns.Add("Column" + i.ToString(), "Задача" + " " +(i+1).ToString());
            }
        }

        private void loadExe_Click(object sender, EventArgs e)
        {

            DialogResult dr = folderBrowserDialog1.ShowDialog();


            exeNameBox.Items.Clear();

            if (dr == DialogResult.OK)
            {
                listBox2.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                exeNameBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
            }

            for (int i = 0; i < exeNameBox.Items.Count; i++)
            {
             
                fi = new FileInfo(exeNameBox.Items[i].ToString());
                dataGridView1.Rows.Add();
                dataGridView1[0, i].Value = fi.Name;

            }
            

        }

        private void loadOutput_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();



            


            if (dr == DialogResult.OK)
            {
                outputInfo = new DirectoryInfo(folderBrowserDialog1.SelectedPath);
                listBox3.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                
            }

        }

        private void loadOutputOrigin_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();



            outputOriginDirBox.Items.Clear();

            if (dr == DialogResult.OK)
            {
                listBox4.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                outputOriginDirBox.Items.AddRange(Directory.GetDirectories(folderBrowserDialog1.SelectedPath));
            }
        }

        private void StartTest_Click(object sender, EventArgs e)
        {
            

            dataGridView1.Show();
            StreamReader streamIn;
            StreamReader streamOut;
            ProcessStartInfo psi;
            System.Diagnostics.Process pr = new Process();
            int n = 0;


            for (int i = 0; i < exeNameBox.Items.Count; i++)
            {
               
                            exeFileExe.Items.AddRange(Directory.GetFiles(exeNameBox.Items[i].ToString()));
                
                for(int k =1; k <= testTaskDirBox.Items.Count;k++)                
                  {
                      foreach (string path in exeFileExe.Items)
                      {


                          fi = new FileInfo(path);
                          if (fi.Name == k.ToString() + ".exe")
                          {
                             testTaskFileBox.Items.AddRange(Directory.GetFiles(testTaskDirBox.Items[k-1].ToString()));
                             outputOriginFileBox.Items.AddRange(Directory.GetFiles(outputOriginDirBox.Items[k-1].ToString()));
                              //цикл на прокрутку
                              for (int l = 0; l < testTaskFileBox.Items.Count; l++)
                              {
                                  foreach (FileInfo f in inputInfo.GetFiles())
                                     f.Delete();

                                  foreach (FileInfo f in outputInfo.GetFiles())
                                      f.Delete();

                                  File.Copy(testTaskFileBox.Items[l].ToString(), inputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                  File.Copy(outputOriginFileBox.Items[l].ToString(), outputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                  /*
                                 копирование, переименование файла
                                */

                                  psi = new ProcessStartInfo(path);
                                  pr.StartInfo = psi;
                                  pr.Start();
                            
                                  //pr.Close();
                                  streamIn = new StreamReader(inputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                  streamOut = new StreamReader( outputInfo.ToString() + @"\" + k.ToString() + "." + "txt");

                                  //сравнение  с рил отутпут
                                  if (streamIn.ReadToEnd() == streamOut.ReadToEnd() )
                                  {
                                      n++;
                                  }
                                  streamIn.Close();
                                  streamOut.Close();
                              }

                           } /*   else if (Другое разрешение)    */
                      }
                      if (n == testTaskFileBox.Items.Count)
                      {
                          dg.BackColor = Color.Green;
                          dataGridView1[k, i].Style = dg;
                          dataGridView1[k, i].Value = "+";
                      }
                      else
                      {
                          dg.BackColor = Color.Red;
                          dataGridView1[k, i].Style = dg;
                          dataGridView1[k, i].Value = "-";
                      }
                      n = 0;
                    psi = new ProcessStartInfo();
                  }
               }
                }







  



        private void loadInputSchool_Click(object sender, EventArgs e)
        {
            DialogResult dr = folderBrowserDialog1.ShowDialog();



           
            

            if (dr == DialogResult.OK)
            {
                listBox5.Items.Add(folderBrowserDialog1.SelectedPath.ToString());
                inputInfo = new DirectoryInfo(folderBrowserDialog1.SelectedPath);
                outputOriginDirBox.Items.AddRange(Directory.GetFiles(folderBrowserDialog1.SelectedPath));
            }
        }

    }
}
