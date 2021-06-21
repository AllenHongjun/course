using System;
public class AppCharInOut 
{
	public static void Main(string[] args) 
	{
		char c = ' ';
		System.Console.Write("Please input a char: ");
		c = (char) System.Console.Read();
		Console.WriteLine("You have entered: " + c );
	}
}
