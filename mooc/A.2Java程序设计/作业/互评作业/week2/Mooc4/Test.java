public class Test 
{
 public static void main(String[] args) 
 {
 // 验证等式 1 是否成立
 long a = 3*3*3 + 4*4*4 + 5*5*5;
 long b = 6*6*6;
 if (a == b) 
 {
 System.out.println("等式成立");
 } 
 else 
 {
 System.out.println("等式不成立");
 }
 // 验证等式 2 是否成立
 long c = 0;
 for (int i = 6; i <= 69; i++) 
 {
 c = c + i*i*i;
 }
 long d = 180*180*180;
 if (c == d) 
 {
 System.out.println("等式成立");
 } else {
 System.out.println("等式不成立");
 }
 }
}