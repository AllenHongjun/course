public class hha
{
	public static void main(String args[])
	{
		int sum = 0;
		for(int i = 3;i <= 5;i++)
		{
		sum += Math.pow(i,3);
		}
		if(sum == Math.pow(6,3))
		{
			System.out.println("等式1成立");
			sum = 0;
		}
		else
		{
			System.out.println("等式1不成立");
			sum = 0;
		}
		for(int j = 6;j <= 69;j++)
		{
			sum += Math.pow(j,3);
		}
		if(sum == Math.pow(180,3))
		{
			System.out.println("等式2成立");
		}
		else
		{
			System.out.println("等式2不成立");
		}
	}
}