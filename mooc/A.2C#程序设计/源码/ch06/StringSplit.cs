using System;
class Test
{
	static void Main() 
	{
		string path = @"d:\scExample\ch06\Test.cs";
		string [] words = path.Split( new Char[] { ':', '\\' } );

		string drive = words[ 0 ];
		string file = words[ words.Length - 1 ];

		Console.WriteLine( drive );
		Console.WriteLine( file );
	}
}
