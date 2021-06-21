using System;
class ExceptionSimple 
{
	int a = 10;
	public static void Main(string[] args) 
	{
		int a = 0;
		try
		{ 
			a= int.Parse( "2" );
			a /= (a-a);  
			// 注意: 整数除以0,会产生异常,但0.0/0=NaN  FPN/0=正无穷,-FPN/0=负无穷, 
		}
		catch(System.ArithmeticException ea )
		{ Console.WriteLine("ea:" +ea); }
		catch(System.FormatException en ) 
		{ Console.WriteLine("en:" +en); }
		catch(System.NullReferenceException ep )
		{ Console.WriteLine("ep:" +ep); }
		catch(System.IndexOutOfRangeException eb )
		{ Console.WriteLine("eb:" +eb); }
		catch
		{ Console.WriteLine("Exception"); }  //先catch子类Exception,后catch父类
		finally
		{ Console.WriteLine("finally executed.");}
		Console.WriteLine("Program End!"+a );
	}
}
