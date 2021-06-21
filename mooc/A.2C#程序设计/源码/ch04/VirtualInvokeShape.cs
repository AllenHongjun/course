using System;
class VirtualInvokeShape
{
	static void doStuff( Shape s )
	{
		s.draw();
	}

	public static void Main( string [] args )
	{
		Shape  c = new Circle();
		Shape  r = new Rectangle();
		Shape  s = new Square();
		doStuff(c);
		doStuff(r);
		doStuff(s);
	}
}

class Shape
{
	public virtual void draw(){ Console.WriteLine("Shape Drawing"); }
}

class Circle : Shape
{
	public override void draw(){ Console.WriteLine("Draw Circle"); }
}

class Rectangle : Shape
{
	public override void draw(){ Console.WriteLine("Draw Four Lines"); }
}

class Square : Rectangle
{
	public override void draw(){ Console.WriteLine("Draw Four Same Length Lines"); }
}

