using System;
class MyDate {
    protected int day,month,year;
    public MyDate(int i,int j,int k) {
    	day = i;
    	month = j;
    	year = k;
    }
}

class MyOkDate  : MyDate{
	public MyOkDate(int i,int j,int k )
		: base(i,j,k)
	{}
	public override string ToString(){
		return year + "-" + month + "-" + day;
	}
}

public class TestTostring{
	public static void Main(string[] args) {
 	   MyDate m1 = new MyDate(24, 3, 2001);
 	   MyDate m2 = new MyOkDate(24, 3, 2001);
	   Console.WriteLine( m1 ); //œ‘ æMyDate
	   Console.WriteLine( m2 ); //œ‘ æ2001-3-24
   }
}
