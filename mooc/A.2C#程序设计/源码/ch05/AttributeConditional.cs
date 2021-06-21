#define TRIAL_VERSION
using System;
using System.Diagnostics;
class Class1 
{
	[Conditional("TRIAL_VERSION")]
	public static void PromptCopyRight() 
	{
		Console.WriteLine("CopyRight My Corp.");
	}
	public static void DoSomething()
	{
		Console.WriteLine( "Do Something" );
		PromptCopyRight();
	}
}
class Test
{
	public static void Main() 
	{
		Class1.DoSomething();
	}
}
