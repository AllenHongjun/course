

import java.util.Scanner;

public class Main {

	private static Scanner in;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=0,b=0,sum=0;
		boolean m = true;
		System.out.println("一、验证题中所给等式是否成立：");
		for(int i=3;i<=5;i++)
		{
			a += i*i*i;
		}
		
		for(int i=6;i<=69;i++)
		{
			b += i*i*i;
		}
		
		if(a==6*6*6 && b==180*180*180)
			System.out.println("结果：题中所给等式成立");
		else
			System.out.println("结果：题中所给等式不成立");
		
		System.out.println("");
		
		
		/*----------------------------------------------*/
		System.out.println("二、在一个指定的区间内寻找其他整数：");
		
		a = 0;   b = 0;   sum = 0;
		System.out.println("请指定一个区间");
		in = new Scanner(System.in);
		{
			System.out.print("起始：");
			a = in.nextInt();
		}
		
		{
			System.out.print("结束：");
			b = in.nextInt();
		}
		
		for(int i=a;i<=b;i++)
		{
			sum += i*i*i;
		}
		
		for(int i=0;i<=10000;i++)
		{
			if(sum == i*i*i)
			{
				System.out.println("结果：满足条件的整数等式情况如下：");
				System.out.println(a + "~" + b + "相续正整数的立方和 是" + i + "的立方");
				m = false;
			}
		}
		
		if(m) {System.out.println("该区间找不到这样一个整数使得等式成立！");}

}

}