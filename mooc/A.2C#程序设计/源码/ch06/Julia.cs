using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

public class Form1 : Form
{
	public Form1()
	{
		this.AutoScaleBaseSize = new Size(6, 14);
		this.ClientSize = new Size(292, 273);
		this.Name = "Form1";
		this.Text = "Form1";
		this.Paint += new PaintEventHandler(this.Form1_Paint);
	}
	static void Main() 
	{
		Application.Run(new Form1());
	}
	private void Form1_Paint(object sender, PaintEventArgs e)
	{
		graphics = e.Graphics ;
		drawJulia();
	}

	private Graphics graphics;

	public void drawJulia()
	{    	
		const double a = 0.5;     //c=a+bi为Julia集的参数
		const double b = 0.55;
		
		for( double x0 = -1.7; x0 < 1.7; x0+=0.01 )
		for( double y0 = -1.7; y0 < 1.7; y0+=0.01 ){
			double x=x0, y=y0;
			int n;
			for( n = 1; n<100; n++ ){
				double x2 = x * x - y * y + a;
				double y2 = 2 * x * y + b;
				x = x2;
				y = y2;
				if( x * x + y * y > 4 ) break;
			}
			pSet(x0, y0, n ); //按n值来将(x0,y0)点进行着色
		}
	}
	public void pSet(double x, double y, int n){
		graphics.DrawLine( 
			new Pen( ColorFromN( n ), 1),
			(int)(x*Width/4 + Width/2),
			(int)(y*Height/4 + Height/2 ),
			(int)(x*Width/4 + Width/2 + 1),
			(int)(y*Height/4 + Height/2 + 1)
			);
	}
	public Color ColorFromN( int n )
	{
		int k = (255-n)%4*50+50;
		return Color.FromArgb( k, k, k );
		//return Color.FromArgb( 
		//	50, n/4%4*50+50, n%4*50+50);
	}
}
