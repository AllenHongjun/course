using System;
class Person {
	string name;
	int age;

	Person( string n, int a ){
		name = n;
		age = a;
	}

	Person( string n ){
		name = n;
		age = -1;
	}

	Person(  ):this(  "", 0 ){
	}

	void sayHello(){
		Console.WriteLine("Hello!  My name is " + name );
	}

	void sayHello( Person another ){
		Console.WriteLine("Hello," + another.name + "! My name is " + name );
	}

	bool isOlderThan( int anAge ){
		bool flg;
		if( age > anAge ) flg = true; else flg=false;
		return flg;
	}

	public static void Main(string[] args) 
	{
	}
}
