using System;
using System.Threading;
public class StateObj 
{
	public int n;
	public int RetVal;
}

class Test
{
	static void Main()
	{
		StateObj StObj1 = new StateObj();
		StateObj StObj2 = new StateObj();

		StObj1.n = 10;
		StObj2.n = 20;

		// 将任务排队
		ThreadPool.QueueUserWorkItem(
			new WaitCallback(SomeOtherTask), StObj1);
		ThreadPool.QueueUserWorkItem(
			new WaitCallback(AnotherTask), StObj2);
		Thread.Sleep(1000);
	}

	static void SomeOtherTask( object obj )
	{
		StateObj stObj = obj as StateObj;
		int n= stObj.n;
		for( int i=1; i<n; i++ ) Console.Write( "." ); 
		Console.WriteLine( n );
		stObj.RetVal = n*n;
	}

	static void AnotherTask( object obj )
	{
		StateObj stObj = obj as StateObj;
		int n= stObj.n;
		for( int i=1; i<n; i++ ) Console.Write( "@" ); 
		Console.WriteLine( n );
		stObj.RetVal = n;
	}
}
