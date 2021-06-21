class A
{
	class B
	{ 
		public int i;
		private int j;
		private void MB()
		{
			M1();// 可以访问 A的private成员
		}
	}
	private static void M1(){}
	static void M2 ()
	{ 
		A.B b = new A.B(); // 可以访问 A.B
		b.i = 1; // 可以访问 A.B 的 public 成员
	}
}

class Test
{
	static void Main()
	{
		object obj = new A();
		//obj  = new A.B(); // 错误, A.B不可访问
	}
}
