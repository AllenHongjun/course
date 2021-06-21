using System;
using System.Net.Sockets;
using System.Text;

class Client
{
	static void Main()
	{
		TcpClient tcpClient = new TcpClient();
		try
		{
			tcpClient.Connect("127.0.0.1", 10000);
			
			NetworkStream networkStream = tcpClient.GetStream();

			if( networkStream.CanRead)
			{
				byte[] bytes = new byte[tcpClient.ReceiveBufferSize];
				networkStream.Read(bytes, 0, (int) tcpClient.ReceiveBufferSize);
				string returndata = Encoding.ASCII.GetString(bytes);
				Console.WriteLine("This is what the host returned to you: " + returndata);
			}
		}
		catch (Exception e ) 
		{
			Console.WriteLine(e.ToString());
		}
	}
}
