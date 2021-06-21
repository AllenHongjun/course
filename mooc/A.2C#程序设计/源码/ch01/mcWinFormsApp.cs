namespace mcWinFormsApp 
{ 
	using System; 
	using System.Drawing; 
	using System.Collections; 
	using System.ComponentModel; 
	using System.Windows.Forms; 
	using System.Data; 
	/// <summary> 
	/// Summary description for Form1. 
	/// </summary> 
	public class Form1 : System.Windows.Forms.Form 
	{ 
		/// <summary> 
		/// Required designer variable. 
		/// </summary> 
		private System.ComponentModel.Container components; 
		private Button button1;
		private TextBox textBox1;
		public Form1() 
		{ 
			// 
			// Required for Windows Form Designer support 
			// 
			InitializeComponent(); 
			// 
			// TODO: Add any constructor code after InitializeComponent call 
			// 
		} 
		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor. 
		/// </summary> 
		private void InitializeComponent() 
		{ 
			this.components = new System.ComponentModel.Container (); 
			//@this.TrayHeight = 0; 
			//@this.TrayLargeIcon = false; 
			//@this.TrayAutoArrange = true; 
			this.Text = "Form1"; 
			this.AutoScaleBaseSize = new System.Drawing.Size (5, 13); 
			this.Click += new System.EventHandler (this.Form1_Click);
			this.components = new System.ComponentModel.Container (); 
			this.button1 = new Button (); 
			this.textBox1 = new TextBox (); 
			button1.Location = new System.Drawing.Point (16, 24); 
			button1.Size = new System.Drawing.Size (88, 32); 
			button1.TabIndex = 0; 
			button1.Text = "Browse"; 
			button1.Click += new System.EventHandler (this.button1_Click); 
			textBox1.Location = new System.Drawing.Point (128, 32); 
			textBox1.Text = "textBox1"; 
			textBox1.TabIndex = 1; 
			textBox1.Size = new System.Drawing.Size (144, 20); 
			this.Text = "Form1"; 
			this.AutoScaleBaseSize = new System.Drawing.Size (5, 13); 
			this.Click += new System.EventHandler (this.Form1_Click); 
			this.Controls.Add (this.textBox1); 
			this.Controls.Add (this.button1);  
		} 
		protected void Form1_Click (object sender, System.EventArgs e) 
		{ 
		} 
		/// <summary> 
		/// The Main entry point for the application. 
		/// </summary> 
		public static void Main(string[] args) 
		{ 
			Application.Run(new Form1()); 
		}
		protected void button1_Click (object sender, System.EventArgs e) 
		{ 
			OpenFileDialog fdlg = new OpenFileDialog(); 
			fdlg.Title = "C# Corner Open File Dialog" ; 
			fdlg.InitialDirectory = @"c:\" ; 
			fdlg.Filter = "All files (*.*)|*.*|All files (*.*)|*.*" ; 
			fdlg.FilterIndex = 2 ; 
			fdlg.RestoreDirectory = true ; 
			if(fdlg.ShowDialog() == DialogResult.OK) 
			{ 
				textBox1.Text = fdlg.FileName ; 
			} 
		}  
	} 
} 
