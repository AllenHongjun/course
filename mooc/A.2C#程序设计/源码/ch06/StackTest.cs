using System;
using System.Collections;
public class StackTest 
{
	static readonly string[] months = 
	{ 
		"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December" 
	};
	public static void Main(string[] args) 
	{
		Stack stk = new Stack();
		for(int i = 0; i < months.Length; i++)
			stk.Push(months[i] + " ");
		Console.WriteLine("popping elements:");
		while( stk.Count > 0 )
			Console.WriteLine(stk.Pop());
	}
}
