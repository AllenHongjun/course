public class Test 
{
 public static void main(String[] args) 
 {
 // ��֤��ʽ 1 �Ƿ����
 long a = 3*3*3 + 4*4*4 + 5*5*5;
 long b = 6*6*6;
 if (a == b) 
 {
 System.out.println("��ʽ����");
 } 
 else 
 {
 System.out.println("��ʽ������");
 }
 // ��֤��ʽ 2 �Ƿ����
 long c = 0;
 for (int i = 6; i <= 69; i++) 
 {
 c = c + i*i*i;
 }
 long d = 180*180*180;
 if (c == d) 
 {
 System.out.println("��ʽ����");
 } else {
 System.out.println("��ʽ������");
 }
 }
}