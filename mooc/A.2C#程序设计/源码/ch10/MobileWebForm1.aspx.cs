using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.Mobile;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.MobileControls;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace MobileWebApplication1
{
	/// <summary>
	/// Summary description for MobileWebForm1.
	/// </summary>
	public class MobileWebForm1 : System.Web.UI.MobileControls.MobilePage
	{
		protected System.Web.UI.MobileControls.Form Form2;
		protected System.Web.UI.MobileControls.Form Form3;
		protected System.Web.UI.MobileControls.TextBox TextBox1;
		protected System.Web.UI.MobileControls.Label Label1;
		protected System.Web.UI.MobileControls.Link Link1;
		protected System.Web.UI.MobileControls.Label Label2;
		protected System.Web.UI.MobileControls.Label label3;
		protected System.Web.UI.MobileControls.Form Form1;
		protected System.Web.UI.MobileControls.Command Command2;
		protected System.Web.UI.MobileControls.Command Command1;
		protected System.Web.UI.MobileControls.SelectionList SelectionList1;

		private void Page_Load(object sender, System.EventArgs e)
		{
			if( ! this.IsPostBack )
			{
				this.SelectionList1.DataSource = currency;
				this.SelectionList1.DataBind();
			}
		}

		#region Web Form Designer generated code
		override protected void OnInit(EventArgs e)
		{
			InitializeComponent();
			base.OnInit(e);
		}

		private void InitializeComponent()
		{    
			this.Command1.Click += new System.EventHandler(this.Command1_Click);
			this.Command2.Click += new System.EventHandler(this.Command2_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		string [] currency = {"美元", "欧元", "日元", "卢布", "越南盾"};
		double [] ratio = {8.1,   8.5,    0.02,   0.1,    0.2};

		private void Command1_Click(object sender, System.EventArgs e)
		{
			this.ActiveForm = this.Form2;
		}

		private void Command2_Click(object sender, System.EventArgs e)
		{
			int selectedkind = this.SelectionList1.SelectedIndex;
			string str = this.TextBox1.Text;
			double n = 0;

			try
			{
				n = double.Parse( str );
			}
			catch{}

			if( selectedkind <0 || n==0 )
			{
				this.label3.Text = "请输入数据";
			}
			else
			{
				this.label3.Text = n + currency[selectedkind] +
					" = "+ ( n * ratio[selectedkind] ) +"元";
			}
			this.ActiveForm = this.Form3;
		}

	}
}
