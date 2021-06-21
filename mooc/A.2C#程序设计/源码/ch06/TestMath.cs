using System;
public class TestMath{
     public static void Main (string [] args) 
     {   
		 Console.WriteLine("ceiling(3.1415)=" + Math.Ceiling(3.1415));
		 Console.WriteLine("floor(3.1415)=" + Math.Floor(3.1415));
		 Console.WriteLine("round(987.654)=" + Math.Round(987.654));
		 Console.WriteLine("max(-987.654,301)=" + Math.Max(-987.654,301));
		 Console.WriteLine("min(-987.654,301)=" + Math.Min(-987.654,301));
		 Console.WriteLine("sqrt(-4.01)=" + Double.IsNaN(Math.Sqrt(-4.01)));
		 Console.WriteLine("PI=" + Math.PI);
		 Console.WriteLine("E=" + Math.E);
     }
}
