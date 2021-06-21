using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Drawing.Drawing2D;
using System.Threading;

using System.Data.OleDb;
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
			this.dataGrid1 = new System.Windows.Forms.DataGrid();
			this.listBox1 = new System.Windows.Forms.ListBox();
			this.button1 = new System.Windows.Forms.Button();
			this.comboBox1 = new System.Windows.Forms.ComboBox();
			((System.ComponentModel.ISupportInitialize)(this.dataGrid1)).BeginInit();
			this.SuspendLayout();
			// 
			// dataGrid1
			// 
			this.dataGrid1.Anchor = ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right);
			this.dataGrid1.DataMember = "";
			this.dataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText;
			this.dataGrid1.Location = new System.Drawing.Point(136, 16);
			this.dataGrid1.Name = "dataGrid1";
			this.dataGrid1.Size = new System.Drawing.Size(224, 232);
			this.dataGrid1.TabIndex = 3;
			// 
			// listBox1
			// 
			this.listBox1.ItemHeight = 12;
			this.listBox1.Location = new System.Drawing.Point(8, 24);
			this.listBox1.Name = "listBox1";
			this.listBox1.Size = new System.Drawing.Size(104, 184);
			this.listBox1.TabIndex = 4;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(144, 272);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(88, 24);
			this.button1.TabIndex = 5;
			this.button1.Text = "button1";
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// comboBox1
			// 
			this.comboBox1.Location = new System.Drawing.Point(8, 224);
			this.comboBox1.Name = "comboBox1";
			this.comboBox1.Size = new System.Drawing.Size(112, 20);
			this.comboBox1.TabIndex = 6;
			this.comboBox1.Text = "comboBox1";
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(376, 301);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.comboBox1,
																		  this.button1,
																		  this.listBox1,
																		  this.dataGrid1});
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.dataGrid1)).EndInit();
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
		private System.Windows.Forms.DataGrid dataGrid1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.ComboBox comboBox1;
		private System.Windows.Forms.ListBox listBox1;


		private void button1_Click(object sender, System.EventArgs e)
		{
			ListBoxBinding();
			ComboBoxFilling();
			DataGridBinding();
		}


		class User
		{
			public string LongName;
			public string ShortName;
			public User( string l, string s )
			{
				LongName = l;
				ShortName = s;
			}
			public override string ToString()
			{
				return LongName + "," +ShortName;
			}
		}
		void ListBoxBinding()
		{
			ArrayList ary = new ArrayList();
			ary.Add( new User( "Tom Soya", "TS" ) );
			ary.Add( new User( "Gorge Bush", "GB" ) );
			ary.Add( new User( "Washinton", "WS" ) );

			this.listBox1.DataSource = ary ;
		}


		void ComboBoxFilling()
		{
			string strSql = "SELECT * FROM [Publishers]";
			string strConn =
				@"Provider=Microsoft.Jet.OLEDB.4.0;" +
				@"Data Source=D:\CsExample\ch10\BIBLIO.MDB";

			OleDbConnection MyConn = new OleDbConnection(strConn);
			OleDbCommand MyCommand = new OleDbCommand(strSql, MyConn);
			MyConn.Open();
			OleDbDataReader MyReader = MyCommand.ExecuteReader();

			this.comboBox1.Items.Clear();
			while( MyReader.Read() )
			{

				this.comboBox1.Items.Add( MyReader["Company Name"] );
			}
			
			MyReader.Close();
			MyConn.Close();
		}

		void DataGridBinding()
		{
			string strSql = "SELECT * FROM [Publishers]";
			string strConn =
				@"Provider=Microsoft.Jet.OLEDB.4.0;" +
				@"Data Source=D:\CsExample\ch10\BIBLIO.MDB";
			OleDbConnection conn = new OleDbConnection( strConn );
			OleDbDataAdapter daAdapter = new OleDbDataAdapter(strSql, conn);
			OleDbCommandBuilder cmdbld = new OleDbCommandBuilder( daAdapter );
			DataSet dsMyData = new DataSet();
			daAdapter.Fill(dsMyData);

			this.dataGrid1.DataSource = dsMyData.Tables[0];
		}

	}


}
