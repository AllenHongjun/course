using System;
public class Sqrt
{
	public static void Main(string [] args){
		Console.WriteLine( sqrt( 2.0 ) );
		Console.WriteLine( Math.Sqrt(2.0) );
	}

	static double sqrt( double a ){
		double x=1.0;
		do{
			x = ( x + a/x ) /2;
		}while( Math.Abs(x*x-a)/a > 1e-6 );
		return x;
	}
}
