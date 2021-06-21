using System;
public class Prime100Continue{
	public static void Main( string [] args ){
		Console.WriteLine(" **** 100--200的质数 ****");
		int n=0;
		for(int i=101;i<200;i+=2){ //外层循环
			for(int j=2; j<i; j++){ //内层循环
				if( i%j==0 )		//不是质数，则跳转到外层循环
					goto outer;
			}
			Console.Write(" "+i);//显示质数
			n++;					//计算个数 
			if( n<10 )				//未满10个数，则不换行
				continue;	
			Console.WriteLine( );
			n=0;
			outer:; 
		}
		Console.WriteLine( );
	}
}
