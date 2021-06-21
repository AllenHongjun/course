using System;
delegate void D( int a );
delegate void E( int a );
class C
{
	static void M( int a){}
	static void Main()
	{
		D d = new D(M);
		E e = new E(M);
		d += d;
		e += e;
		// e = (E)d; //D、E是不同类型的
		// d += e;
		Console.WriteLine( d == e ); //d与e相等
	}
}
