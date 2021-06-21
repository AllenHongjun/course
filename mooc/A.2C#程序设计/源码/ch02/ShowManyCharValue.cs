using System;
class  ShowManyCharValue
{
	public static void Main(string[] args) 
	{
		char c;
		do
		{
			Console.WriteLine("输入字符并按回车，按#结束");
			c = (char)Console.Read();  //读入一个字符
			Console.Read();  //忽略回车换行
			Console.Read();  //忽略回车换行
			Console.WriteLine( c + "的Ascii值为:" + (int)c );
		}
		while ( c != '#' );
	}
}
