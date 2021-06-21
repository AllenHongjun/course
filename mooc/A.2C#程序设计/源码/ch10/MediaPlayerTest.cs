using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Drawing.Drawing2D;

namespace TestWin
{
	/// <summary>
	/// Form1 的摘要说明。
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.ComponentModel.IContainer components;

		public Form1()
		{
			//
			// Windows 窗体设计器支持所必需的
			//
			InitializeComponent();

			//
			// TODO: 在 InitializeComponent 调用后添加任何构造函数代码
			//
		}

		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
			this.button1 = new System.Windows.Forms.Button();
			this.axMediaPlayer1 = new AxMediaPlayer.AxMediaPlayer();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			((System.ComponentModel.ISupportInitialize)(this.axMediaPlayer1)).BeginInit();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(144, 272);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(88, 24);
			this.button1.TabIndex = 5;
			this.button1.Text = "Open...";
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// axMediaPlayer1
			// 
			this.axMediaPlayer1.Location = new System.Drawing.Point(56, 8);
			this.axMediaPlayer1.Name = "axMediaPlayer1";
			this.axMediaPlayer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axMediaPlayer1.OcxState")));
			this.axMediaPlayer1.Size = new System.Drawing.Size(286, 225);
			this.axMediaPlayer1.TabIndex = 6;
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(376, 301);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.axMediaPlayer1,
																		  this.button1});
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.axMediaPlayer1)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// 应用程序的主入口点。
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private AxMediaPlayer.AxMediaPlayer axMediaPlayer1;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.Button button1;


		private void button1_Click(object sender, System.EventArgs e)
		{
			this.openFileDialog1.Filter = "media file|*.avi;*.mpg";
			DialogResult result = this.openFileDialog1.ShowDialog();
			if( result != DialogResult.OK ) return;
			string file = this.openFileDialog1.FileName;
			this.axMediaPlayer1.FileName = file;
			this.axMediaPlayer1.Play();
		}
	
	}
}
