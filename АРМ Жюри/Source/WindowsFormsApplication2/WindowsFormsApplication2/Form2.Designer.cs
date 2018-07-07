namespace WindowsFormsApplication2
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.MaxBall = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.CustomSystem = new System.Windows.Forms.RadioButton();
            this.StudentSystem = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.listBox5 = new System.Windows.Forms.ListBox();
            this.loadInputSchool = new System.Windows.Forms.Button();
            this.loadOutputOrigin = new System.Windows.Forms.Button();
            this.listBox4 = new System.Windows.Forms.ListBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.listBox3 = new System.Windows.Forms.ListBox();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.loadOutput = new System.Windows.Forms.Button();
            this.loadExe = new System.Windows.Forms.Button();
            this.loadInput = new System.Windows.Forms.Button();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.label7 = new System.Windows.Forms.Label();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.bonusTime = new System.Windows.Forms.CheckBox();
            this.prizeTime = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.label9 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.on_OffComp = new System.Windows.Forms.CheckBox();
            this.KF = new System.Windows.Forms.Label();
            this.KFF = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.timeLimit = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // MaxBall
            // 
            this.MaxBall.Location = new System.Drawing.Point(85, 331);
            this.MaxBall.Name = "MaxBall";
            this.MaxBall.Size = new System.Drawing.Size(27, 20);
            this.MaxBall.TabIndex = 25;
            this.MaxBall.Text = "100";
            this.MaxBall.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.MaxBall_KeyPress);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(32, 315);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(156, 13);
            this.label6.TabIndex = 24;
            this.label6.Text = "Максимальный балл ученика";
            // 
            // CustomSystem
            // 
            this.CustomSystem.AutoSize = true;
            this.CustomSystem.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CustomSystem.Location = new System.Drawing.Point(10, 291);
            this.CustomSystem.Name = "CustomSystem";
            this.CustomSystem.Size = new System.Drawing.Size(117, 21);
            this.CustomSystem.TabIndex = 23;
            this.CustomSystem.Text = "Расширенная";
            this.CustomSystem.UseVisualStyleBackColor = true;
            // 
            // StudentSystem
            // 
            this.StudentSystem.AutoSize = true;
            this.StudentSystem.Checked = true;
            this.StudentSystem.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.StudentSystem.Location = new System.Drawing.Point(10, 264);
            this.StudentSystem.Name = "StudentSystem";
            this.StudentSystem.Size = new System.Drawing.Size(224, 21);
            this.StudentSystem.TabIndex = 22;
            this.StudentSystem.TabStop = true;
            this.StudentSystem.Text = "Однобальная (по умолчанию)";
            this.StudentSystem.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Location = new System.Drawing.Point(585, 419);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 26;
            this.button1.Text = "Ok";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(47, 129);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(105, 17);
            this.label5.TabIndex = 41;
            this.label5.Text = "Входной поток";
            // 
            // listBox5
            // 
            this.listBox5.FormattingEnabled = true;
            this.listBox5.Location = new System.Drawing.Point(10, 189);
            this.listBox5.Name = "listBox5";
            this.listBox5.Size = new System.Drawing.Size(180, 17);
            this.listBox5.TabIndex = 40;
            // 
            // loadInputSchool
            // 
            this.loadInputSchool.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadInputSchool.Location = new System.Drawing.Point(196, 147);
            this.loadInputSchool.Name = "loadInputSchool";
            this.loadInputSchool.Size = new System.Drawing.Size(58, 19);
            this.loadInputSchool.TabIndex = 39;
            this.loadInputSchool.Text = "...";
            this.loadInputSchool.UseVisualStyleBackColor = true;
            this.loadInputSchool.Click += new System.EventHandler(this.loadInputSchool_Click);
            // 
            // loadOutputOrigin
            // 
            this.loadOutputOrigin.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadOutputOrigin.Location = new System.Drawing.Point(196, 67);
            this.loadOutputOrigin.Name = "loadOutputOrigin";
            this.loadOutputOrigin.Size = new System.Drawing.Size(58, 19);
            this.loadOutputOrigin.TabIndex = 38;
            this.loadOutputOrigin.Text = "...";
            this.loadOutputOrigin.UseVisualStyleBackColor = true;
            this.loadOutputOrigin.Click += new System.EventHandler(this.loadOutputOrigin_Click);
            // 
            // listBox4
            // 
            this.listBox4.FormattingEnabled = true;
            this.listBox4.Location = new System.Drawing.Point(10, 149);
            this.listBox4.Name = "listBox4";
            this.listBox4.Size = new System.Drawing.Size(180, 17);
            this.listBox4.TabIndex = 37;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(47, 49);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(197, 17);
            this.label4.TabIndex = 36;
            this.label4.Text = "Ответы к тестовым наборам";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(47, 169);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(115, 17);
            this.label3.TabIndex = 35;
            this.label3.Text = "Выходной поток";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(47, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(133, 17);
            this.label2.TabIndex = 34;
            this.label2.Text = "Решения учеников";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(47, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(126, 17);
            this.label1.TabIndex = 33;
            this.label1.Text = "Тестовые наборы";
            // 
            // listBox3
            // 
            this.listBox3.FormattingEnabled = true;
            this.listBox3.Location = new System.Drawing.Point(10, 109);
            this.listBox3.Name = "listBox3";
            this.listBox3.Size = new System.Drawing.Size(180, 17);
            this.listBox3.TabIndex = 32;
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.Location = new System.Drawing.Point(10, 69);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(180, 17);
            this.listBox2.TabIndex = 31;
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(10, 29);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(180, 17);
            this.listBox1.TabIndex = 30;
            // 
            // loadOutput
            // 
            this.loadOutput.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadOutput.Location = new System.Drawing.Point(196, 187);
            this.loadOutput.Name = "loadOutput";
            this.loadOutput.Size = new System.Drawing.Size(58, 19);
            this.loadOutput.TabIndex = 29;
            this.loadOutput.Text = "...";
            this.loadOutput.UseVisualStyleBackColor = true;
            this.loadOutput.Click += new System.EventHandler(this.loadOutput_Click);
            // 
            // loadExe
            // 
            this.loadExe.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadExe.Location = new System.Drawing.Point(196, 107);
            this.loadExe.Name = "loadExe";
            this.loadExe.Size = new System.Drawing.Size(58, 19);
            this.loadExe.TabIndex = 28;
            this.loadExe.Text = "...";
            this.loadExe.UseVisualStyleBackColor = true;
            this.loadExe.Click += new System.EventHandler(this.loadExe_Click);
            // 
            // loadInput
            // 
            this.loadInput.Cursor = System.Windows.Forms.Cursors.Default;
            this.loadInput.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadInput.Location = new System.Drawing.Point(196, 27);
            this.loadInput.Name = "loadInput";
            this.loadInput.Size = new System.Drawing.Size(58, 19);
            this.loadInput.TabIndex = 27;
            this.loadInput.Text = "...";
            this.loadInput.UseVisualStyleBackColor = true;
            this.loadInput.Click += new System.EventHandler(this.loadInput_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(341, 53);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(161, 17);
            this.label7.TabIndex = 42;
            this.label7.Text = "Окончание олимпиады";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Checked = false;
            this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dateTimePicker1.Location = new System.Drawing.Point(309, 73);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(65, 20);
            this.dateTimePicker1.TabIndex = 43;
            // 
            // bonusTime
            // 
            this.bonusTime.AutoSize = true;
            this.bonusTime.Checked = true;
            this.bonusTime.CheckState = System.Windows.Forms.CheckState.Checked;
            this.bonusTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bonusTime.Location = new System.Drawing.Point(291, 29);
            this.bonusTime.Name = "bonusTime";
            this.bonusTime.Size = new System.Drawing.Size(277, 21);
            this.bonusTime.TabIndex = 44;
            this.bonusTime.Text = "Вкл/Выкл бонус за оставшееся время";
            this.bonusTime.UseVisualStyleBackColor = true;
            // 
            // prizeTime
            // 
            this.prizeTime.Location = new System.Drawing.Point(331, 112);
            this.prizeTime.Name = "prizeTime";
            this.prizeTime.Size = new System.Drawing.Size(27, 20);
            this.prizeTime.TabIndex = 45;
            this.prizeTime.Text = "0,9";
            this.prizeTime.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.prizeTime_KeyPress);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(306, 96);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(264, 13);
            this.label8.TabIndex = 46;
            this.label8.Text = "Кол-во доп. баллов за каждую оставшуюся минуту";
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBox2.Location = new System.Drawing.Point(291, 138);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(286, 21);
            this.checkBox2.TabIndex = 47;
            this.checkBox2.Text = "Снижать за отсутствие исходных кодов";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(36, 241);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(132, 20);
            this.label9.TabIndex = 48;
            this.label9.Text = "Система оценки";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(331, 176);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(27, 20);
            this.textBox1.TabIndex = 49;
            this.textBox1.Text = "5";
            this.textBox1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox1_KeyPress);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(306, 160);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(246, 13);
            this.label10.TabIndex = 50;
            this.label10.Text = "Кол-во вычитаемых баллов [за каждую задачу]";
            // 
            // on_OffComp
            // 
            this.on_OffComp.AutoSize = true;
            this.on_OffComp.Checked = true;
            this.on_OffComp.CheckState = System.Windows.Forms.CheckState.Checked;
            this.on_OffComp.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.on_OffComp.Location = new System.Drawing.Point(291, 202);
            this.on_OffComp.Name = "on_OffComp";
            this.on_OffComp.Size = new System.Drawing.Size(182, 21);
            this.on_OffComp.TabIndex = 51;
            this.on_OffComp.Text = "Вкл/Выкл компенсацию";
            this.on_OffComp.UseVisualStyleBackColor = true;
            // 
            // KF
            // 
            this.KF.AutoSize = true;
            this.KF.Location = new System.Drawing.Point(306, 225);
            this.KF.Name = "KF";
            this.KF.Size = new System.Drawing.Size(153, 13);
            this.KF.TabIndex = 52;
            this.KF.Text = "Коэффициент срабатывания";
            // 
            // KFF
            // 
            this.KFF.Location = new System.Drawing.Point(331, 241);
            this.KFF.Name = "KFF";
            this.KFF.Size = new System.Drawing.Size(27, 20);
            this.KFF.TabIndex = 53;
            this.KFF.Text = "0,8";
            this.KFF.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.KFF_KeyPress);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(12, 219);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(62, 15);
            this.label11.TabIndex = 54;
            this.label11.Text = "TimeLimit";
            // 
            // timeLimit
            // 
            this.timeLimit.Location = new System.Drawing.Point(80, 219);
            this.timeLimit.Name = "timeLimit";
            this.timeLimit.Size = new System.Drawing.Size(14, 20);
            this.timeLimit.TabIndex = 55;
            this.timeLimit.Text = "3";
            this.timeLimit.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(672, 454);
            this.Controls.Add(this.timeLimit);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.KFF);
            this.Controls.Add(this.KF);
            this.Controls.Add(this.on_OffComp);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.checkBox2);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.prizeTime);
            this.Controls.Add(this.bonusTime);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.listBox5);
            this.Controls.Add(this.loadInputSchool);
            this.Controls.Add(this.loadOutputOrigin);
            this.Controls.Add(this.listBox4);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox3);
            this.Controls.Add(this.listBox2);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.loadOutput);
            this.Controls.Add(this.loadExe);
            this.Controls.Add(this.loadInput);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.MaxBall);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.CustomSystem);
            this.Controls.Add(this.StudentSystem);
            this.Name = "Form2";
            this.Text = "Параметры";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal System.Windows.Forms.TextBox MaxBall;
        public System.Windows.Forms.Label label6;
        public System.Windows.Forms.RadioButton CustomSystem;
        public System.Windows.Forms.RadioButton StudentSystem;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ListBox listBox5;
        private System.Windows.Forms.Button loadInputSchool;
        private System.Windows.Forms.Button loadOutputOrigin;
        private System.Windows.Forms.ListBox listBox4;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListBox listBox3;
        private System.Windows.Forms.ListBox listBox2;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button loadOutput;
        private System.Windows.Forms.Button loadExe;
        private System.Windows.Forms.Button loadInput;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
        private System.Windows.Forms.TextBox prizeTime;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBox1;
        public System.Windows.Forms.CheckBox checkBox2;
        public System.Windows.Forms.Label label10;
        public System.Windows.Forms.Label label7;
        public System.Windows.Forms.DateTimePicker dateTimePicker1;
        public System.Windows.Forms.CheckBox bonusTime;
        public System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label KF;
        private System.Windows.Forms.TextBox KFF;
        public System.Windows.Forms.CheckBox on_OffComp;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox timeLimit;

    }
}