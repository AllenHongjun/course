using System;
using System.Threading;
using System.Net.Sockets;

class WorkerThreadHandler 
{
	public TcpListener myTcpListener;

	public void HandleThread() 
	{
		Thread currentThread = Thread.CurrentThread;
		Socket mySocket = myTcpListener.AcceptSocket();
		string message =
			"Thread Name: " + currentThread.Name +
			"\r\nThread Apartment State: " + currentThread.ApartmentState.ToString() +
			"\r\nThread State: " + currentThread.ThreadState.ToString();
		Console.WriteLine(message);
		byte[] buf = System.Text.Encoding.ASCII.GetBytes(message.ToCharArray());
		mySocket.Send(buf);
		Console.WriteLine("Closing connection with client.");
		mySocket.Close();
	}
}

public class MainThreadHandler 
{
	private TcpListener myTcpListener;

	public MainThreadHandler() 
	{
		myTcpListener = new TcpListener(10000);
		myTcpListener.Start();
		Console.WriteLine("Listener started. Press Ctrl+Break to stop.");

		while (true) 
		{
			while (!myTcpListener.Pending()) 
			{   
				Thread.Sleep(1000);
			}
			WorkerThreadHandler myWorkerThreadHandler = new WorkerThreadHandler();
			myWorkerThreadHandler.myTcpListener = this.myTcpListener;
			ThreadStart myThreadStart = new ThreadStart(myWorkerThreadHandler.HandleThread);
			Thread myWorkerThread = new Thread(myThreadStart);
			myWorkerThread.Name = "Created at " + DateTime.Now.ToString();
			myWorkerThread.Start();
		}
	}
	static void Main()
	{
		new MainThreadHandler();
	}
}
