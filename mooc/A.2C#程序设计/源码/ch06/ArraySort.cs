using System;
public class Test 
{
	public static void Main(string[] args) 
	{
		string [] ary = 
		{
				"Apple", "Pearl", "Banana", "Carrot",
		};
		Show( ary );
		Array.Sort( ary );
		Show( ary );
		int i=Array.BinarySearch( ary, "Pearl" );
		Console.WriteLine( i );
		Array.Reverse( ary );
		Show( ary );
	}
	public static void Show( object [] ary )
	{
		foreach( object obj in ary )
			Console.Write( obj  + " ");
		Console.WriteLine();
	}
}
