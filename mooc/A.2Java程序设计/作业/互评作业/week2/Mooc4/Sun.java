import java.util Scanner;
public class Sun{
	public static void main(String[]args){
	int n,i,j;
	int sum1=0,y=0,z=0,sum2=0;
	Scanner sc=new Scanner(System.in);
	n=sc.nextInt();
	for(i=3;i<6;i++)
		{sum1=sum1+i*i*i;
		y=y+i;}
	
	if(sum1==(y/2)*(y/2)*(y/2))
		System.out.println("yes");
	
	for(j=6;j<70;j++)
		{sum2+=j*j*j;
		z=z+j;}

	if(sum2==(z/2)*(z/2)*(z/2))
	System.out.println("ok");
	}
}