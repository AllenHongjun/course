using System;
using System.Collections;
public class SamplesArrayList  
{
	public static void Main()  
	{
		BitArray ary = new BitArray( 100, true );

		for( int i=2; i<ary.Count; i++ )
		{
			if( ! ary[i] ) continue;
			for( int j=i+i; j<ary.Count; j+=i )
			{
				ary[j] = false;
			}
		}
		for( int i=2; i<ary.Count; i++ )
		{
			if( ary[i] ) Console.Write( i + " " );
		}
		Console.WriteLine();
	}
}
