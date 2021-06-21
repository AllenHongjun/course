using System;
using System.Threading;
class SyncCounter2
{
	public static void Main(string[] args){ 
		Num num = new Num();
		Thread thread1 = new Thread( new ThreadStart(num.run));
		Thread thread2 = new Thread( new ThreadStart(num.run));
		thread1.IsBackground = true;
		thread2.IsBackground = true;
		thread1.Start();
		thread2.Start();
		for( int i=0; i<10; i++ ){
			Thread.Sleep(100);
			num.testEquals();
		}
	}
}

class Num
{
	private int x=0;
	private int y=0;
	public void increase(){
		x++; 
		y++; 
	}
	public void testEquals(){
		Console.WriteLine( x+","+y+" £º"+(x==y));
	}
	public void run(){
		while(true){
			increase();
		}
	}
}
