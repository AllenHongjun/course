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
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.PictureBox pictureBox1;
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
			this.components = new System.ComponentModel.Container();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.SuspendLayout();
			// 
			// timer1
			// 
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// pictureBox1
			// 
			this.pictureBox1.Location = new System.Drawing.Point(56, 32);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(200, 120);
			this.pictureBox1.TabIndex = 0;
			this.pictureBox1.TabStop = false;
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(304, 185);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.pictureBox1});
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
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

		private System.IO.DirectoryInfo dir;
		private System.IO.FileInfo [] files;
		private Image [] images;
		private int cur;
		private void Form1_Load(object sender, System.EventArgs e)
		{
			dir = new System.IO.DirectoryInfo( @"c:\winnt" );
			files = dir.GetFiles( "*.bmp" );
			images = new Image[ files.Length ];
			cur = 0;
			this.timer1.Interval = 1000;
			this.timer1.Start();
		}

		private void timer1_Tick(object sender, System.EventArgs e)
		{
			if( images[cur] == null )
			{
				try
				{
					images[cur] = Bitmap.FromFile( files[cur].FullName );
				}
				catch{}
			}
			if( images[cur] != null )
			{
				this.pictureBox1.Location = new Point( 
					( this.Width - images[cur].Width )/2,
					( this.Height - images[cur].Height )/2 );
				this.pictureBox1.Width = this.images[cur].Width;
				this.pictureBox1.Height = this.images[cur].Height;
				this.pictureBox1.Image = images[cur];
			}
			cur ++;
			if( cur >= files.Length ) cur = 0;
		}
	}
}
