

public class test01 {

	public static void main(String []arg){
		
		int a=3,b=4,c=5;
		
		double sum = Math.pow(a, 3) +Math.pow(b, 3)+Math.pow(c, 3);
		
		double sum2=0;
		for(int i=6;i<=69;i++){
			
			sum2 += Math.pow(i, 3);
		}
		System.out.println("pow()方法运算结果="+sum+"6*6*6运算结果="+6*6*6);
		System.out.println("sum2的结果="+sum2+"180*180*180的结果="+180*180*180);
		
	}
	
}
