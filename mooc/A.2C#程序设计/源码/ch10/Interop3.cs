using System;
class Test
{
	static void Main()
	{
		Console.Write( "请输入一个表达式：");
		string exp = Console.ReadLine();
		string result = "";
		Interop2.JSExpressObj obj = new Interop2.JSExpressObj();
		try
		{
			result = obj.Eval( exp );		
		}
		catch{}
		Module1.Msg( result );
	}
}