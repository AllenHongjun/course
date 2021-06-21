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
		this.ClientSize = new Size(350, 180);
		this.Paint += new PaintEventHandler(this.Form1_Paint);
	}
	static void Main() 
	{
		Application.Run(new Form1());
	}
	private void Form1_Paint(object sender, PaintEventArgs e)
	{
		graphics = e.Graphics ;
		width = this.Width -30;
		height = this.Height-30;
		curx = cury = 10;
		drawVonKoch( 8, width );
	}

	private Graphics graphics;
	private int width;
	private int height;
	private double th, curx, cury;
	readonly double PI = Math.PI;
	readonly double m = 2*(1 + Math.Cos(85 * Math.PI/180));
	
	void drawVonKoch( int n, double d ){
	    if( n == 0 ){
        	double x = curx + d * Math.Cos(th * PI / 180);
        	double y = cury + d * Math.Sin(th * PI / 180);
        	drawLineTo (x, y);
			return;
        }
		drawVonKoch( n - 1, d / m );
		th = th + 85;
		drawVonKoch( n - 1, d / m );
		th = th - 170;
		drawVonKoch( n - 1, d / m );
		th = th + 85;
		drawVonKoch( n - 1, d / m );
	}
	void drawLineTo( double x, double y ){
		graphics.DrawLine( 
			Pens.Blue,
			(int)curx, (int)cury, (int)x, (int)y );
		curx=x; 
		cury=y;
	}
}	
