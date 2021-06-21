using System;
class Constants
{
	public const int A = 1;
	public const int B = A + 1;
}
class Test
{
	static void Main() {
		Console.WriteLine("A = {0}, B = {1}", 
			Constants.A, Constants.B);
	}
}
