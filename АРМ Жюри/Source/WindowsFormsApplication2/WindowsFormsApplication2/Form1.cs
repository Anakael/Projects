using System;
using System.Linq;
using System.Collections.Generic;
using System.ComponentModel;
//using Excel =  Microsoft.Office.Interop.Excel;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.Text;

namespace WindowsFormsApplication2
{
    
    public partial class MainForm : Form
    {
        
        public MainForm()
        {
            InitializeComponent();
        }




        FileInfo fi;
        List<string> lstr = new List<string>();
 

        private void StartTest_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView2.Rows.Count-1; i++)
            {
                dataGridView2[3, i].Value = 0;
            }
            float TimeLimit = 0;
            
            float mainnerf = 0;
            float KF=0;
            string pupilAnswer = string.Empty;
            string realAnswer = string.Empty;
            LogReach.Clear();
            float prizeTime = 0;           
            string[,] answerForTask = new string[myform.exeNameBox.Items.Count, myform.testTaskDirBox.Items.Count];
            foreach (Control con in myform.Controls)

                if (con.Name == "timeLimit")
                    TimeLimit = float.Parse(con.Text);
            bool flag = false;
            double sum = 0;
            float maxBallforPupil = 0;
            float maxBallforTask = 0;
            if (myform.CustomSystem.Checked)
            {
                foreach (Control con in myform.Controls)
                {
                    if (con.Name == "MaxBall")
                    {
                        maxBallforPupil = float.Parse(con.Text);
                        maxBallforTask = float.Parse(con.Text)/myform.testTaskDirBox.Items.Count;
                    }
                    if (con.Name == "KFF")
                         KF = float.Parse(con.Text);
                    

                }
            }
            if (myform.bonusTime.Checked)
                foreach (Control con in myform.Controls)
                    if (con.Name == "prizeTime")
                        prizeTime = float.Parse(con.Text);



            if (myform.checkBox2.Checked)
                foreach (Control con in myform.Controls)
            if (con.Name == "textBox1")
                mainnerf = float.Parse(con.Text);

            float tmpnerf = 0;
            bool donerf = true;
            DateTime dt = new DateTime();
            dataGridView1.Show();
            StreamReader streamIn;
            StreamReader streamOut;
            ProcessStartInfo psi;
            System.Diagnostics.Process pr = new Process();
            int n = 0;
            bool[,] flagSS = new bool[myform.exeNameBox.Items.Count,myform.testTaskDirBox.Items.Count];
            for (int i = 0; i < flagSS.GetLength(0); i++)
                for (int j = 0; j < flagSS.GetLength(1); j++)
                    flagSS[i, j] = false;
                for (int i = 0; i < myform.exeNameBox.Items.Count; i++)
                {



                    myform.exeFileExe.Items.Clear();
                    myform.exeFileExe.Items.AddRange(Directory.GetFiles(myform.exeNameBox.Items[i].ToString()));


                    fi = new FileInfo(myform.exeNameBox.Items[i].ToString());
                    LogReach.SelectionFont = new Font("Microsoft Sans Serif", 11, FontStyle.Bold);
                    LogReach.AppendText("\t " + fi.Name + "\n");


                    for (int k = 1; k <= myform.testTaskDirBox.Items.Count; k++)
                    {


                        LogReach.SelectionFont = new Font("Microsoft Sans Serif", float.Parse("8,25"), FontStyle.Italic);
                        LogReach.SelectionColor = default(Color);
                        LogReach.AppendText("Задача " + k + ":\n");
                        LogReach.AppendText("\n");


                        foreach (string path in myform.exeFileExe.Items)
                        {
                            fi = new FileInfo(path);
                            if (fi.Name == k.ToString() + ".exe")
                            {

                                foreach (string put in myform.exeFileExe.Items)
                                {
                                    fi = new FileInfo(put);
                                    if ((fi.Name == k.ToString() + ".c") || (fi.Name == k.ToString() + ".h")
                                    || (fi.Name == k.ToString() + ".cpp") || (fi.Name == k.ToString() + ".hpp")
                                    || (fi.Name == k.ToString() + ".cs") || (fi.Name == k.ToString() + ".pas"))
                                    {
                                        donerf = false;
                                        break;
                                    }

                                }

                                myform.testTaskFileBox.Items.Clear();
                                myform.outputOriginFileBox.Items.Clear();
                                myform.testTaskFileBox.Items.AddRange(Directory.GetFiles(myform.testTaskDirBox.Items[k - 1].ToString()));
                                myform.outputOriginFileBox.Items.AddRange(Directory.GetFiles(myform.outputOriginDirBox.Items[k - 1].ToString()));
                                //цикл на прокрутку
                                for (int l = 0; l < myform.testTaskFileBox.Items.Count; l++)
                                {
                                    foreach (FileInfo f in myform.inputInfo.GetFiles())
                                        f.Delete();

                                    foreach (FileInfo f in myform.outputInfo.GetFiles())
                                        f.Delete();

                                    File.Copy(myform.testTaskFileBox.Items[l].ToString(), myform.inputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                    File.Copy(myform.outputOriginFileBox.Items[l].ToString(), myform.outputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                    /*
                                   копирование, переименование файла
                                  */

                                    psi = new ProcessStartInfo(path);
                                    pr.StartInfo = psi;
                                    dt = DateTime.Now;
                                    pr.Start();

                                    while ((DateTime.Now.Ticks - dt.Ticks) / TimeSpan.TicksPerSecond < TimeLimit)
                                    {
                                        if (pr.HasExited)
                                        {
                                            flag = true;
                                            break;
                                        }

                                    }
                                    if (!flag)
                                        pr.Kill();
                                    else
                                    {
                                        flag = false;
                                        //pr.Close();
                                        streamIn = new StreamReader(myform.inputInfo.ToString() + @"\" + k.ToString() + "." + "txt");

                                        if (File.Exists(myform.outputInfo.ToString() + @"\" + k.ToString() + "." + "txt"))
                                            streamOut = new StreamReader(myform.outputInfo.ToString() + @"\" + k.ToString() + "." + "txt");
                                        else continue;

                                        pupilAnswer = streamIn.ReadToEnd();
                                        if (myform.on_OffComp.Checked)
                                            answerForTask[i,k-1] += pupilAnswer;
                                        realAnswer = streamOut.ReadToEnd();
                                        LogReach.AppendText("Тест " + (l + 1) + ":\n");


                                        //сравнение  с рил отутпут
                                        if (pupilAnswer == realAnswer)
                                        {
                                            LogReach.AppendText(realAnswer + "\n");
                                            LogReach.SelectionColor = Color.Green;
                                            LogReach.AppendText(pupilAnswer + "\n");
                                            // LogReach.SelectionColor = Color.Green;

                                            LogReach.AppendText("\n");
                                            LogReach.SelectionColor = default(Color);
                                            n++;
                                        }
                                        else
                                        {
                                            LogReach.AppendText(realAnswer + "\n");
                                            LogReach.SelectionFont = new Font("Microsoft Sans Serif", float.Parse("8,25"), FontStyle.Bold);
                                            LogReach.SelectionColor = Color.Red;
                                            LogReach.AppendText(pupilAnswer + "\n");
                                            //LogReach.ForeColor = Color.Red;

                                            LogReach.AppendText("\n");
                                            LogReach.SelectionColor = default(Color);
                                        }

                                        streamIn.Close();
                                        streamOut.Close();

                                    }

                                }

                            }
                            /*   else if (Другое разрешение)    */
                        }
                        if (myform.StudentSystem.Checked)
                        {
                            if ((n > 0) && (n != myform.testTaskFileBox.Items.Count))
                                flagSS[i, k - 1] = true;
                            if (n == myform.testTaskFileBox.Items.Count)
                            {
                                dataGridView1[k, i].Value = "1";
                                dataGridView1[k, i].Style.BackColor = Color.Green;
                            }
                            else
                            {
                                dataGridView1[k, i].Value = "0";
                                dataGridView1[k, i].Style.BackColor = Color.Red;
                            }
                        }
                        else
                        {

                            dataGridView1[k, i].Value = Math.Round(maxBallforTask / myform.testTaskFileBox.Items.Count * n, 2);
                            if (float.Parse(dataGridView1[k, i].Value.ToString()) == maxBallforTask)
                                dataGridView1[k, i].Style.BackColor = Color.Green;
                            else if (double.Parse(dataGridView1[k, i].Value.ToString()) <= 0)
                            {
                                dataGridView1[k, i].Value = 0;
                                dataGridView1[k, i].Style.BackColor = Color.Red;
                            }

                        }
                        n = 0;
                        psi = new ProcessStartInfo();
                        if (donerf)
                            tmpnerf += mainnerf;
                        donerf = true;
                    }
                    dataGridView2[3, i].Value = float.Parse(dataGridView2[3, i].Value.ToString()) - tmpnerf;
                    tmpnerf = 0;
                }
            
            for (int i = 0; i <=dataGridView1.RowCount -2 ; i++)
            {
                for (int j = 1; j <= dataGridView1.ColumnCount -1; j++)
                {
                    sum += float.Parse(dataGridView1[j, i].Value.ToString());
                   
                }
                dataGridView2[2, i].Value = sum;
                sum = 0;
            }

            

            if(myform.on_OffComp.Checked)
            {
                string[] tmpAnswerForTask = new string[myform.exeNameBox.Items.Count];
                string tmp = string.Empty;
                float comp = KF * myform.exeNameBox.Items.Count;
                for (int i = 0; i < myform.testTaskDirBox.Items.Count; i++)
                {
                    int max = 1;
                    for (int j = 0; j < myform.exeNameBox.Items.Count; j++)
                    {
                        tmp = answerForTask[i, j];
                        tmpAnswerForTask[j] = tmp;
                    }

                    Array.Sort(tmpAnswerForTask);

                    for (int k = 0; k < tmpAnswerForTask.Count() - 1; k++)
                    {
                        if (tmpAnswerForTask[k] == tmpAnswerForTask[k + 1])
                        {
                            n++;
                            if (n > max)
                                max = n;
                        }
                        else
                            n = 1;

                    }

                    if (max >= comp)
                    {
                        if (myform.CustomSystem.Checked)
                        {
                            for (int k = 0; k < myform.exeNameBox.Items.Count; k++)
                                if (float.Parse(dataGridView1[i + 1, k].Value.ToString()) > 0)
                                    dataGridView2[3, k].Value = float.Parse(dataGridView2[3, k].Value.ToString()) + (maxBallforTask - float.Parse(dataGridView1[i + 1, k].Value.ToString()));
                        }
                        else
                        {
                            for (int k = 0; k < myform.exeNameBox.Items.Count; k++)
                                if (flagSS[k, i])
                                    dataGridView2[3, k].Value = float.Parse(dataGridView2[3, k].Value.ToString()) + 1;
                        }

                    }
                }
               
            }


            double ball = 0;
            DateTime tmpDT = new DateTime();

            if (myform.bonusTime.Checked)
            {
                for (int i = 0; i < dataGridView2.RowCount-1; i++)
                {
                    if (double.Parse(dataGridView2[2, i].Value.ToString()) == maxBallforPupil)  //Need changed!!
                    {
                        for (int j = 0; j <myform.exeNameBox.Items.Count; j++)
                        
                        {
                            fi = new FileInfo(myform.exeNameBox.Items[j].ToString());
                            if (fi.Name == dataGridView1[0,i].Value.ToString())
                            {
                                tmpDT = Directory.GetLastWriteTime(myform.exeNameBox.Items[j].ToString());
                                ball = float.Parse(dataGridView2[3, i].Value.ToString()) + Math.Round((myform.dateTimePicker1.Value.Ticks - tmpDT.Ticks) / TimeSpan.TicksPerMinute * prizeTime,2);
                                dataGridView2[3, i].Value = ball;
                            }
                        }                       
                    }
                    
                }
                              
            }


            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            
                dataGridView2[4, i].Value = float.Parse(dataGridView2[2, i].Value.ToString()) + float.Parse(dataGridView2[3, i].Value.ToString()); 


                dataGridView2.Sort(dataGridView2.Columns[4], ListSortDirection.Descending);    
                dataGridView2[1, 0].Value = 1;

                for (int i = 1; i < dataGridView1.RowCount - 1; i++)                                       
                {
                    if (float.Parse(dataGridView2[4, i].Value.ToString()) 
                        == float.Parse(dataGridView2[4, i-1].Value.ToString()))

                        dataGridView2[1, i].Value =
                            dataGridView2[1, i - 1].Value;
                    else
                        
                        dataGridView2[1, i].Value =
                            (float.Parse(dataGridView2[1,i-1].Value.ToString()) + 1);
                }
            }



 

        private void Form1_Load(object sender, EventArgs e)
        {

          myform    = new Form2();

        }
        Form2 myform;

        private void button1_Click_2(object sender, EventArgs e)
        {
            myform.Show();
        }

        private void очиститьToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            SourceLog.Clear();
            LogReach.Clear();
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            dataGridView1.Columns.Add("FIO", "Ф.И.О Участника");
            SourceName.Items.Clear();
            SourceTask.Items.Clear();
            SourceName.Text = string.Empty;
            SourceTask.Text = string.Empty;

            dataGridView2.Rows.Clear();
            dataGridView2.Columns.Clear();
            dataGridView2.Columns.Add("FIO", "Ф.И.О Участника");
            dataGridView2.Columns.Add("Pos", "Занятое место");
            dataGridView2.Columns.Add("Sum", "Задачи");
            dataGridView2.Columns.Add("Dob", "Добавочные баллы");
            dataGridView2.Columns.Add("itog", "Итоговая сумма");
        }

 

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        /*private void экспортВExcelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Excel.Application excelApplication = new Excel.Application();
            Excel.Workbook ObjWorkBook;
            Excel.Worksheet ObjWorkSheet;
            
            //Книга.
            ObjWorkBook = excelApplication.Workbooks.Add();
            //Таблица.
            ObjWorkSheet = (Excel.Worksheet)ObjWorkBook.Sheets[1];

            excelApplication.Visible = true;
            excelApplication.UserControl = true;

            for (int i = 0; i < dataGridView2.ColumnCount; i++)
            {
                ObjWorkSheet.Cells[1, i + 1] = dataGridView2.Columns[i].HeaderText;
            }

            for (int i = 0; i < dataGridView2.RowCount; i++)
            {
                ObjWorkSheet.Cells[i + 2, 1] = dataGridView2[0, i].Value;
            }
            for (int i = 1; i <= dataGridView2.ColumnCount - 1; i++)
            {

                for (int j = 0; j < dataGridView2.RowCount; j++)
                {
                    ObjWorkSheet.Cells[j + 2, i + 1] = dataGridView2[i, j].Value;
                }
            }
        }*/

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutBox1 about = new AboutBox1();
            about.Show();

        }

        private void SourceName_SelectedIndexChanged(object sender, EventArgs e)
        {

            SourceTask.Items.Clear();
            ListBox sour = new ListBox();
            lstr.Clear();
            sour.Items.AddRange(Directory.GetFiles(myform.exeNameBox.Items[SourceName.SelectedIndex].ToString()));
            for (int i = 1; i <= myform.testTaskDirBox.Items.Count; i++)
            {
                foreach (string path in sour.Items)
                {
                fi = new FileInfo(path);
                if ((fi.Name == i.ToString() + ".c") || (fi.Name == i.ToString() + ".h")
                    || (fi.Name == i.ToString() + ".cpp") || (fi.Name == i.ToString() + ".hpp") 
                    || (fi.Name == i.ToString() + ".cs") || (fi.Name == i.ToString() + ".pas"))
                    {
                        SourceTask.Items.Add("Задача " + i.ToString());
                        lstr.Add(path);
                    }
                }
            }
        }

        private void SourceTask_SelectedIndexChanged(object sender, EventArgs e)
        {
            SourceLog.Clear();
            StreamReader sr = new StreamReader(lstr[SourceTask.SelectedIndex].ToString(),Encoding.Default);
            SourceLog.LoadFile(sr.BaseStream, RichTextBoxStreamType.PlainText);
        }


    














  



        

    }
}
