using System;
class Singleton{
	private static Singleton onlyone = new Singleton();
	private string name;
	public static Singleton getSingleton() {
		return onlyone;
	}
	private Singleton() {}
}

public class TestSingleton{
	public static void Main(string [] args) { 
		Singleton  s1 = Singleton.getSingleton();
		 Singleton  s2 = Singleton.getSingleton();
		 if (s1==s2){
			Console.WriteLine("s1 is equals to s2!");
		 }
	}
}
