using System;
class DoubleAndstring 
{
	public static void Main(string[] args) 
	{
		double d ; string s;

		//double转成string的几种方法
		d=3.14159;
		s = "" + d;
		s = d.ToString();
		s = string.Format( "{0}", d );
		s = Convert.ToString( d );

		// string转成double的几种方法
		s = "3.14159";
		try{
			d = Double.Parse( s );
			d = Convert.ToDouble( s );
		}
		catch(FormatException )
		{
		}
	}
}
