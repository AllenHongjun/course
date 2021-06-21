using System;
using System.Diagnostics;
class Test
{
	static void  Main()
	{
		Trace.Listeners.Add(new TextWriterTraceListener(Console.Out));

		Trace.WriteLine("Main: calling Test");
		M(1);
		Trace.WriteLine("Main: back from call");
	}

	public static void M(int n)
	{
		Trace.Indent();
		Trace.WriteLine("Test:  entry");
		// more code...
		Trace.WriteLine("Test: exit");
		Trace.Unindent();
	}
}

