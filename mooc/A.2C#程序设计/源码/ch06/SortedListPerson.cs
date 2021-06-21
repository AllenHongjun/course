using System;
using System.Collections;
public class Test  
{
	public static void Main()  
	{
		Person [] Persons = 
		{
			new Person( "Li ", true, 12 ),
			new Person( "Zhang", true, 18 ),
			new Person( "Tang", false, 23 ),
			new Person( "Chen", false, 37 ),
		};
		Random rnd = new Random();
		SortedList list1 = new SortedList();
		foreach( Person r in Persons )
			list1.Add( r, "Room:" + rnd.Next(1000) );
		PrintKeysAndValues( list1 );

		SortedList list2 = 
			new SortedList( list1, new MyComparer() );
		PrintKeysAndValues( list2 );
	}

	public struct Person : IComparable
	{
		public string Name;
		public bool Sex;
		public int Age;
		public Person( string name, bool sex, int age )
		{
			this.Name = name;
			this.Sex = sex;
			this.Age = age;
		}
		public int CompareTo( object obj2 )
		{
			if( ! (obj2 is Person) )
				throw new System.ArgumentException();
			Person rec2 = (Person) obj2;
			if( this.Age > rec2.Age ) return 1;
			else if( this.Age == rec2.Age ) return 0;
			return -1;
		}
		public override string ToString()
		{
			return "Name:"+Name + "\tSex:"+Sex +"\tAge:"+Age;
		}
	}

	public class MyComparer : IComparer
	{
		public int Compare( object obj1, object obj2 )
		{
			if( ! (obj2 is Person)  || ! (obj2 is Person) )
				throw new System.ArgumentException();
			Person rec1 = (Person) obj1;
			Person rec2 = (Person) obj2;
			return rec1.Name.ToLower().CompareTo(  rec2.Name.ToLower() );
		}
	}

	public static void PrintKeysAndValues( SortedList myList )  
	{
		IDictionaryEnumerator myEnumerator = myList.GetEnumerator();
		while ( myEnumerator.MoveNext() )
			Console.WriteLine("\t{0}:\t\t{1}", 
				myEnumerator.Key, myEnumerator.Value);
		Console.WriteLine();
	}
}
