using System;
class Test
{
	static void Main() 
	{
		string a= "A";
		string s="";
		System.Text.StringBuilder sb 
			= new System.Text.StringBuilder();
		DateTime t0 = DateTime.Now;
		for(int i=0; i<100000; i++ )
			s = s.Insert( 0, "." );
		DateTime t1 = DateTime.Now;
		for(int i=0; i<100000; i++ )
			sb = sb.Insert( 0, "." );
		DateTime t2 = DateTime.Now;

		Console.WriteLine( t1-t0 );
		Console.WriteLine( t2-t1 );
	}
}
