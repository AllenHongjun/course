public class test{
	private static int ccl(int i) {
		return i*i*i;	
	}
	public static void main(String[] args) {
		if(ccl(3)+ccl(4)+ccl(5)==ccl(6)) {
			System.out.println("3^3+4^3+5^3=6^3");
		}
		int total=0;
		for(int i=6;i<70;i++) {
			total+=ccl(i);
		}
		if(total==ccl(180)) {
			System.out.println("6^3+7^3+...=180^3");
		}
		
	}
}
