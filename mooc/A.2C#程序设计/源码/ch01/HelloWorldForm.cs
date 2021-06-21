using System;
using System.Drawing;
using System.Windows.Forms;
public class HelloWorldForm : System.Windows.Forms.Form
{
	public HelloWorldForm()
	{
		this.ClientSize = new System.Drawing.Size(200, 180);
		this.Name = "HelloWorldForm";
		this.Text = "HelloWorldForm";
		this.Paint += new System.Windows.Forms.PaintEventHandler(
			this.HelloWorldForm_Paint);
	}
	static void Main() 
	{
		Application.Run(new HelloWorldForm());
	}
	private void HelloWorldForm_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
	{
		e.Graphics.DrawString( "Hello, world", 
			new Font("Curior New", 12f ), 
			new SolidBrush( Color.Blue), 
			50f, 100f, null);
	}
}

