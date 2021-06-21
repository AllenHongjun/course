using System;
using System.IO;
class FileOpenText
{
	static void Main()
	{
		StreamReader sr = File.OpenText( ".\\FileOpenText.cs" );
		string contents = sr.ReadToEnd(); //读取所有内容
		sr.Close();
		string [] lines = contents.Split( new Char[] {'\n'} );
		for( int i=0; i<lines.Length; i++ )
		{
			Console.WriteLine( i + ":\t" + lines[i] );
		}
	}
}
