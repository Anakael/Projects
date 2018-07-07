namespace WindowsFormsApplication2
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.loadInput = new System.Windows.Forms.Button();
            this.loadExe = new System.Windows.Forms.Button();
            this.loadOutput = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.listBox3 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.label4 = new System.Windows.Forms.Label();
            this.listBox4 = new System.Windows.Forms.ListBox();
            this.loadOutputOrigin = new System.Windows.Forms.Button();
            this.StartTest = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.loadInputSchool = new System.Windows.Forms.Button();
            this.listBox5 = new System.Windows.Forms.ListBox();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // loadInput
            // 
            this.loadInput.Cursor = System.Windows.Forms.Cursors.Default;
            this.loadInput.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadInput.Location = new System.Drawing.Point(293, 19);
            this.loadInput.Name = "loadInput";
            this.loadInput.Size = new System.Drawing.Size(58, 19);
            this.loadInput.TabIndex = 0;
            this.loadInput.Text = "...";
            this.loadInput.UseVisualStyleBackColor = true;
            this.loadInput.Click += new System.EventHandler(this.loadInput_Click);
            // 
            // loadExe
            // 
            this.loadExe.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadExe.Location = new System.Drawing.Point(293, 42);
            this.loadExe.Name = "loadExe";
            this.loadExe.Size = new System.Drawing.Size(58, 19);
            this.loadExe.TabIndex = 1;
            this.loadExe.Text = "...";
            this.loadExe.UseVisualStyleBackColor = true;
            this.loadExe.Click += new System.EventHandler(this.loadExe_Click);
            // 
            // loadOutput
            // 
            this.loadOutput.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadOutput.Location = new System.Drawing.Point(293, 66);
            this.loadOutput.Name = "loadOutput";
            this.loadOutput.Size = new System.Drawing.Size(58, 19);
            this.loadOutput.TabIndex = 2;
            this.loadOutput.Text = "...";
            this.loadOutput.UseVisualStyleBackColor = true;
            this.loadOutput.Click += new System.EventHandler(this.loadOutput_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(107, 22);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(180, 17);
            this.listBox1.TabIndex = 3;
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.Location = new System.Drawing.Point(107, 45);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(180, 17);
            this.listBox2.TabIndex = 4;
            // 
            // listBox3
            // 
            this.listBox3.FormattingEnabled = true;
            this.listBox3.Location = new System.Drawing.Point(107, 68);
            this.listBox3.Name = "listBox3";
            this.listBox3.Size = new System.Drawing.Size(180, 17);
            this.listBox3.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(17, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 17);
            this.label1.TabIndex = 6;
            this.label1.Text = "Test\'s Tasks";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(75, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 17);
            this.label2.TabIndex = 7;
            this.label2.Text = "exe";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(54, 67);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(51, 17);
            this.label3.TabIndex = 8;
            this.label3.Text = "Output";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(21, 91);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(84, 17);
            this.label4.TabIndex = 9;
            this.label4.Text = "Real Output";
            // 
            // listBox4
            // 
            this.listBox4.FormattingEnabled = true;
            this.listBox4.Location = new System.Drawing.Point(107, 91);
            this.listBox4.Name = "listBox4";
            this.listBox4.Size = new System.Drawing.Size(180, 17);
            this.listBox4.TabIndex = 10;
            // 
            // loadOutputOrigin
            // 
            this.loadOutputOrigin.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadOutputOrigin.Location = new System.Drawing.Point(293, 89);
            this.loadOutputOrigin.Name = "loadOutputOrigin";
            this.loadOutputOrigin.Size = new System.Drawing.Size(58, 19);
            this.loadOutputOrigin.TabIndex = 11;
            this.loadOutputOrigin.Text = "...";
            this.loadOutputOrigin.UseVisualStyleBackColor = true;
            this.loadOutputOrigin.Click += new System.EventHandler(this.loadOutputOrigin_Click);
            // 
            // StartTest
            // 
            this.StartTest.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.StartTest.Location = new System.Drawing.Point(357, 19);
            this.StartTest.Name = "StartTest";
            this.StartTest.Size = new System.Drawing.Size(113, 113);
            this.StartTest.TabIndex = 12;
            this.StartTest.Text = "Start Test";
            this.StartTest.UseVisualStyleBackColor = true;
            this.StartTest.Click += new System.EventHandler(this.StartTest_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Enabled = false;
            this.dataGridView1.Location = new System.Drawing.Point(20, 157);
            this.dataGridView1.MultiSelect = false;
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(463, 273);
            this.dataGridView1.TabIndex = 13;
            this.dataGridView1.Visible = false;
            // 
            // loadInputSchool
            // 
            this.loadInputSchool.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.loadInputSchool.Location = new System.Drawing.Point(293, 113);
            this.loadInputSchool.Name = "loadInputSchool";
            this.loadInputSchool.Size = new System.Drawing.Size(58, 19);
            this.loadInputSchool.TabIndex = 14;
            this.loadInputSchool.Text = "...";
            this.loadInputSchool.UseVisualStyleBackColor = true;
            this.loadInputSchool.Click += new System.EventHandler(this.loadInputSchool_Click);
            // 
            // listBox5
            // 
            this.listBox5.FormattingEnabled = true;
            this.listBox5.Location = new System.Drawing.Point(107, 115);
            this.listBox5.Name = "listBox5";
            this.listBox5.Size = new System.Drawing.Size(180, 17);
            this.listBox5.TabIndex = 15;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(66, 115);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(39, 17);
            this.label5.TabIndex = 16;
            this.label5.Text = "Input";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 453);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.listBox5);
            this.Controls.Add(this.loadInputSchool);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.StartTest);
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
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button loadInput;
        private System.Windows.Forms.Button loadExe;
        private System.Windows.Forms.Button loadOutput;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.ListBox listBox2;
        private System.Windows.Forms.ListBox listBox3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox listBox4;
        private System.Windows.Forms.Button loadOutputOrigin;
        private System.Windows.Forms.Button StartTest;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button loadInputSchool;
        private System.Windows.Forms.ListBox listBox5;
        private System.Windows.Forms.Label label5;
    }
}

