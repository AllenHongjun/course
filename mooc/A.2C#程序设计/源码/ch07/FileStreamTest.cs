using System;
using System.IO;
class Test
{
	static void  Main()
	{
		try
		{
			FileStream fsw = new FileStream("test.dat", 
				FileMode.Create, FileAccess.Write);

			//Write some data to the stream;
			fsw.WriteByte( 33 );
			fsw.Write(new byte[]{ 34,35,36 }, 0, 3);
			fsw.Close();

			FileStream fsr = new FileStream("test.dat", 
				FileMode.Open, FileAccess.Read);
			Console.WriteLine(fsr.ReadByte());
			Console.WriteLine(fsr.ReadByte());
			Console.WriteLine(fsr.ReadByte());
			Console.WriteLine(fsr.ReadByte());
		}
		catch ( Exception e )
		{
			Console.WriteLine("Exception:" + e.ToString());
		}
	}
}
