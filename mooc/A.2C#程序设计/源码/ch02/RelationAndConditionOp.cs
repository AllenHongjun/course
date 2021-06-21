using System;
public class RelationAndConditionOp{
	public static void Main( ){
		int a=25,b=3;
		bool d=a<b; //d=false
		Console.WriteLine("a<b = "+d);
		int e=3;
		if(e!=0 && a/e>5)
			Console.WriteLine("a/e = "+a/e);
		int f=0;
		if(f!=0 && a/f>5)
			Console.WriteLine("a/f = "+a/f);
		else
			Console.WriteLine("f = "+f);
	}
}¡¡
