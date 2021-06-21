using System;
public class  MaxDiv
{
	public static void Main(string[] args) 
	{
		int a = 99;
		int i = a - 1; 
		while(i>0){
			if( a % i == 0 ) break;
			i--;
		}
		Console.WriteLine(a + "的最大真约数为：" + i);
	}
}
