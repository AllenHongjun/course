using System;
public class ExceptionIndexOutOf
{
	public static void Main(string[] args)
	{
		string [] friends={"lisa","bily","kessy"};
		try 
		{
			for(int i=0;i<5;i++) 
			{
				Console.WriteLine(friends[i]);
			}
		} 
		catch(System.IndexOutOfRangeException e) 
		{
			Console.WriteLine(e.Message);
		}
		Console.WriteLine("\nthis is the end");
	}
}
