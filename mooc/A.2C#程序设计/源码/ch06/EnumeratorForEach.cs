using System;
using System.Collections;
class Test
{
	static void Main() 
	{
		string [] ary = 
		{ "Apple", "Banana", "Cucumber", };

		IEnumerator enumerator = ary.GetEnumerator();
		while( enumerator.MoveNext() )
		{
			string str = enumerator.Current as string;
			Console.WriteLine( str );
		}

		foreach( string str in ary )
		{
			Console.WriteLine( str );
		}
	}
}
