using System;
using System.Threading;

class TimerExampleState 
{
	public int counter = 0;
	public Timer tmr; //保持一个Timer引用，以便Dispose
}

class App 
{
	public static void Main()
	{
		TimerExampleState s = new TimerExampleState();
		Timer timer = new Timer(
			new TimerCallback(CheckStatus),
			s, 1000, 500);
		s.tmr = timer;

		while(s.tmr != null)
			Thread.Sleep(0);
		Console.WriteLine("Timer example done.");
	}

	static void CheckStatus(object state)
	{
		TimerExampleState s =(TimerExampleState)state;
		s.counter++;
		Console.WriteLine("{0} Checking Status {1}.",
			DateTime.Now.TimeOfDay, s.counter);
		if(s.counter == 5)
		{
			(s.tmr).Change(3000,100); //更改时间间隔
			Console.WriteLine("changed...");
		}
		if(s.counter == 10)
		{
			Console.WriteLine("disposing of timer...");
			s.tmr.Dispose();
			s.tmr = null;
		}
	}
}