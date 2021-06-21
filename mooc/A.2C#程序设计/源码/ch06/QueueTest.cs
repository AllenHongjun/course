using System;
using System.Collections;
public class QueueTest 
{
	static readonly string[] months = 
	{ 
		"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December" 
	};
	public static void Main(string[] args) 
	{
		Queue que = new Queue();
		for(int i = 0; i < months.Length; i++)
			que.Enqueue(months[i] + " ");
		Console.WriteLine("popping elements:");
		while( que.Count > 0 )
			Console.WriteLine(que.Dequeue());
	}
}
