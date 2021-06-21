using System;
class A
{
	class B
	{ 
		public struct C
		{
			public int x;
		}
		public int i;
	}
	static void Main()
	{ 
		B.C c = new A.B.C();
		c.x = 1;
		A.B b = new A.B();
		b.i = 2;
	}
}
