namespace Create_animal_or_misc_script
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		///  Clean up any resources being used.
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
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.animal_header_label = new System.Windows.Forms.Label();
			this.misc_header_label = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.comboBox1 = new System.Windows.Forms.ComboBox();
			this.SuspendLayout();
			// 
			// animal_header_label
			// 
			this.animal_header_label.AutoSize = true;
			this.animal_header_label.Font = new System.Drawing.Font("Segoe UI Black", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
			this.animal_header_label.Location = new System.Drawing.Point(150, 18);
			this.animal_header_label.Name = "animal_header_label";
			this.animal_header_label.Size = new System.Drawing.Size(86, 30);
			this.animal_header_label.TabIndex = 0;
			this.animal_header_label.Text = "Animal";
			// 
			// misc_header_label
			// 
			this.misc_header_label.AutoSize = true;
			this.misc_header_label.Font = new System.Drawing.Font("Segoe UI Black", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
			this.misc_header_label.Location = new System.Drawing.Point(524, 18);
			this.misc_header_label.Name = "misc_header_label";
			this.misc_header_label.Size = new System.Drawing.Size(60, 30);
			this.misc_header_label.TabIndex = 1;
			this.misc_header_label.Text = "Misc";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(477, 76);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(33, 15);
			this.label1.TabIndex = 3;
			this.label1.Text = "Type";
			// 
			// comboBox1
			// 
			this.comboBox1.FormattingEnabled = true;
			this.comboBox1.Items.AddRange(new object[] {
            "Food",
            "Wash",
            "Walk",
            "Pet",
            "Sleep"});
			this.comboBox1.Location = new System.Drawing.Point(533, 76);
			this.comboBox1.Name = "comboBox1";
			this.comboBox1.Size = new System.Drawing.Size(144, 23);
			this.comboBox1.TabIndex = 4;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.comboBox1);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.misc_header_label);
			this.Controls.Add(this.animal_header_label);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private Label animal_header_label;
		private Label misc_header_label;
		private Label label1;
		private ComboBox comboBox1;
	}
}