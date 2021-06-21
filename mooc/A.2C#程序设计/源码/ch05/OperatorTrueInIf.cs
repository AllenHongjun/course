public class T
{
	public int x;
	public static bool operator true( T t )
	{
		return t.x != 0;
	}
	public static bool operator false( T t )
	{
		return t.x != 0;
	}
	public static void Main()
	{
		T t = new T();
		t.x = 5;
		if( t ) 
			System.Console.WriteLine( "T is Ok!" );
		else 
			System.Console.WriteLine( "T is Bad!" );
	}
}
