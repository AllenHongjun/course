using System;
class A
{
	public int a = 10;
	public void m() {
		a++; Console.WriteLine(a);
	}
}
class B : A
{
	new public int a = 20;
	new public void m() { 
		a++; Console.WriteLine(a);
	}
	static void Main()
	{
		A x = new B(); 
		Console.WriteLine( x.a ); //显示10
		x.m(); //显示11
		
		B y = new B();
		Console.WriteLine( y.a ); //显示20
		y.m(); //显示21
	}
}
