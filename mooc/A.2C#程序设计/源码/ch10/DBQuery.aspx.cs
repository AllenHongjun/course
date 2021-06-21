using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

namespace WebApplication1
{

	public class WebFormDBQuery : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{

			if( ! this.IsPostBack )
				this.DataGrid1.Visible = false;
			else
				this.DataGrid1.Visible = true;

		}

		#region Web Form Designer generated code
		override protected void OnInit(EventArgs e)
		{

			InitializeComponent();
			base.OnInit(e);
		}
		

		private void InitializeComponent()
		{    
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string name = this.TextBox1.Text.Trim();

			string str = "Select * From [Publishers]";
			if( name != "" ) 
				str += "Where [pub_name] like '%" + name + "%'";

			string strConn = "data source=TDS;initial catalog=pubs;" +
				"user id=sa;password=tree";

			SqlDataAdapter daAdapter = new SqlDataAdapter(str, strConn);

			SqlCommandBuilder cmdbld = new SqlCommandBuilder( daAdapter );
		
			DataSet dsMyData = new DataSet();

			daAdapter.Fill(dsMyData);

			this.DataGrid1.DataSource = dsMyData.Tables[0].DefaultView;

			this.DataBind();
		
		}
	}
}
