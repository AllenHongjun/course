using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace TestWin
{
	/// <summary>
	/// Form1 的摘要说明。
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Button button4;
		private System.Windows.Forms.Button button5;
		private System.Windows.Forms.Button button6;
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		private System.ComponentModel.Container components = null;

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
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.button4 = new System.Windows.Forms.Button();
			this.button5 = new System.Windows.Forms.Button();
			this.button6 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Dock = System.Windows.Forms.DockStyle.Top;
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(292, 23);
			this.button1.TabIndex = 0;
			this.button1.Text = "button1";
			// 
			// button2
			// 
			this.button2.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.button2.Location = new System.Drawing.Point(0, 250);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(292, 23);
			this.button2.TabIndex = 1;
			this.button2.Text = "button2";
			// 
			// button3
			// 
			this.button3.Dock = System.Windows.Forms.DockStyle.Left;
			this.button3.Location = new System.Drawing.Point(0, 23);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(75, 227);
			this.button3.TabIndex = 2;
			this.button3.Text = "button3";
			// 
			// button4
			// 
			this.button4.Dock = System.Windows.Forms.DockStyle.Right;
			this.button4.Location = new System.Drawing.Point(217, 23);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(75, 227);
			this.button4.TabIndex = 3;
			this.button4.Text = "button4";
			// 
			// button5
			// 
			this.button5.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.button5.Location = new System.Drawing.Point(75, 227);
			this.button5.Name = "button5";
			this.button5.Size = new System.Drawing.Size(142, 23);
			this.button5.TabIndex = 4;
			this.button5.Text = "button5";
			// 
			// button6
			// 
			this.button6.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.button6.Location = new System.Drawing.Point(75, 204);
			this.button6.Name = "button6";
			this.button6.Size = new System.Drawing.Size(142, 23);
			this.button6.TabIndex = 5;
			this.button6.Text = "button6";
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(292, 273);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.button6,
																		  this.button5,
																		  this.button4,
																		  this.button3,
																		  this.button2,
																		  this.button1});
			this.Name = "Form1";
			this.Text = "Form1";
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
	}
}
