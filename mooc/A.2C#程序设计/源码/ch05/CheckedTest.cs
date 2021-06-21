using System;
public class CheckedTest 
{
	public static void Main() 
	{
		byte a,b,result;
		a = 255;
		b = 3;
		try
		{
			unchecked
			{

				// 在unchecked上下文, 不会异常，但结果都会被截断,结果为2
				result = (byte) (a + b); 
				Console.WriteLine( "Unchecked result: " + result );

				// 用checked 表达式，要进行溢出检查，可能发出异常
				result = checked( (byte)(a + b) );
				Console.WriteLine( "Checked result: " +  result );
			}
		}
		catch( OverflowException e )
		{
			Console.WriteLine( e);
		}
	}
}
