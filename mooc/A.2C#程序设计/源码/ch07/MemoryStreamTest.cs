using System;
using System.IO;
class Test
{
	static void  Main()
	{
		try
		{
			byte [] ary = { 33, 34, 35, 36, 37 };
			int b;

			MemoryStream msr = new MemoryStream( ary );
			MemoryStream msw = new MemoryStream();

			while( ( b= msr.ReadByte()) != -1 )
			{
				msw.WriteByte( (byte) (b+3) );
			}
			byte [] result = msw.ToArray();

			foreach( byte bt in result )
				Console.WriteLine( bt );
		}
		catch ( IOException e )
		{
			Console.WriteLine("Exception:" + e.ToString());
		}
	}
}
