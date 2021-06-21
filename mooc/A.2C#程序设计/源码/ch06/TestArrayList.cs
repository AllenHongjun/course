using System;
using System.Collections;
public class TestArrayList  
{
	public static void Main()  
	{
		ArrayList myAL = new ArrayList();
		myAL.Add("Apple");
		myAL.Add("Banana");
		myAL.Add("Carrot");

		Console.WriteLine( "Count:    {0}", myAL.Count );
		PrintValues( myAL );
	}

	public static void PrintValues( IEnumerable myList )  
	{
		IEnumerator myEnumerator = myList.GetEnumerator();
		while ( myEnumerator.MoveNext() )
			Console.Write( "\t{0}", myEnumerator.Current );
		Console.WriteLine();
	}
}
