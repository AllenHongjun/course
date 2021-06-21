using System;
public struct Digit
{
	byte value;
	public Digit(byte value) 
	{
		if (value < 0 || value > 9) throw new ArgumentException();
		this.value = value;
	}
	public static implicit operator byte(Digit d) 
	{
		return d.value;
	}
	public static explicit operator Digit(byte b) 
	{
		return new Digit(b);
	}
}

class Test
{
	static void Main() 
	{
		int a = 5;
		Digit d = (Digit) a;
		byte b = d;
		System.Console.WriteLine( b );
	}
}
