using System;
delegate void 调温器( ref int x);

class 日光灯
{
	public void 开灯( ref int 温度)
	{
		温度 += 1;
	}
}

class 白炽灯
{
	public void 开灯( ref int 温度)
	{
		温度 += 2;
	}
}

class 电扇
{
	public void 扇风( ref int 温度)
	{
		温度 -= 5;
	}
}

class 空调
{
	static public void 打开( ref int 温度)
	{
		温度 = 25;
	}
}


class 房间
{
	static public void 调节温度()
	{
		日光灯 flu1 = new 日光灯();
		日光灯 flu2 = new 日光灯();
		白炽灯 light = new 白炽灯();
		电扇 fan1 = new 电扇();

		int 温度 = 30;
		调温器 ctrls = null;

		ctrls += new 调温器( flu1.开灯 );
		ctrls += new 调温器( flu2.开灯 );
		ctrls += new 调温器( light.开灯 );
        ctrls( ref 温度);
		Console.WriteLine( 温度 );
		
		ctrls -= new 调温器( light.开灯 );
		ctrls -= new 调温器( flu2.开灯 );
		ctrls += new 调温器( fan1.扇风 );
		ctrls( ref 温度);
		Console.WriteLine( 温度 );
		
		ctrls += new 调温器( 空调.打开 );
		ctrls( ref 温度);
		Console.WriteLine( 温度 );

	}
	static public void Main()
	{
		调节温度();
	}
}
