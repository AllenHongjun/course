using System;
using System.Drawing;
using System.Windows.Forms;
namespace ch01
{
	public class HelloWorldWin : System.Windows.Forms.Form
	{
		public HelloWorldWin()
		{
			InitializeComponent();
		}

		private void InitializeComponent()
		{
			this.ClientSize = new System.Drawing.Size(200, 180);
			this.Name = "HelloWorldWin";
			this.Text = "HelloWorldWin";
			this.Paint += new System.Windows.Forms.PaintEventHandler(
				this.HelloWorldWin_Paint);
		}
		static void Main() 
		{
			Application.Run(new HelloWorldWin());
		}
		private void HelloWorldWin_Paint(
			object sender, System.Windows.Forms.PaintEventArgs e)
		{
			e.Graphics.DrawString( "Hello, world", 
				new Font("Curior New", 12f ), 
				new SolidBrush( Color.Blue), 
				50f, 100f, null);
		}
	}
}
