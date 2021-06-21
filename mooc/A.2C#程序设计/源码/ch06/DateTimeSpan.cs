using System;
class Test
{
	static void Main() 
	{
         System.DateTime today = System.DateTime.Now;
         System.TimeSpan duration = TimeSpan.Parse( "36.00:00:00");
         System.DateTime answer = today.Add(duration);
         System.Console.WriteLine("{0}  {0:dddd}", answer, answer);
	}
}
