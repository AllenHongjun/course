

import java.util.Scanner;

public class Main {

	private static Scanner in;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=0,b=0,sum=0;
		boolean m = true;
		System.out.println("һ����֤����������ʽ�Ƿ������");
		for(int i=3;i<=5;i++)
		{
			a += i*i*i;
		}
		
		for(int i=6;i<=69;i++)
		{
			b += i*i*i;
		}
		
		if(a==6*6*6 && b==180*180*180)
			System.out.println("���������������ʽ����");
		else
			System.out.println("���������������ʽ������");
		
		System.out.println("");
		
		
		/*----------------------------------------------*/
		System.out.println("������һ��ָ����������Ѱ������������");
		
		a = 0;   b = 0;   sum = 0;
		System.out.println("��ָ��һ������");
		in = new Scanner(System.in);
		{
			System.out.print("��ʼ��");
			a = in.nextInt();
		}
		
		{
			System.out.print("������");
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
				System.out.println("���������������������ʽ������£�");
				System.out.println(a + "~" + b + "������������������ ��" + i + "������");
				m = false;
			}
		}
		
		if(m) {System.out.println("�������Ҳ�������һ������ʹ�õ�ʽ������");}

}

}