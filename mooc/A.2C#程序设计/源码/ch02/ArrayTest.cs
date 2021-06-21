using System;
public class ArrayTest {
	public static void Main( string [] args ){
		int i;
		int [] a=new int[5];
		for( i=0; i<5; i++ )
			a[i]=i;
		for( i=a.Length-1; i>=0; i-- )
			Console.WriteLine("a["+i+"] = "+a[i]);
	}
}
