using System;
public class MainApp
{
	public static void Main()
	{
		int x = Div( 8 ,3 ); //此句在编译中会产生警告信息
		int y = Div2( 8, 3 ); //这里改用Div的新版
	}

	[Obsolete("Div已废弃，请改用 Div2")]
	public static int Div( int a, int b)
	{
		return (a/b);
	}
   
	public static int Div2( int a, int b)
	{
		return b==0? 0 : a/b;
	}
}
