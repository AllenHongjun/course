using System;
using System.Diagnostics;
class MySample
{
	public static void Main()
	{
		if( ! EventLog.SourceExists("MySource"))
		{
			EventLog.CreateEventSource("MySource", "MyNewLog");
			Console.WriteLine("CreatingEventSource");
		}              

		EventLog myLog = new EventLog();
		myLog.Source = "MySource";
        
		myLog.WriteEntry("Msg : Writing to event log.");
	}
}