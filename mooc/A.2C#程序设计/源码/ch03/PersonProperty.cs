using System;
class Person
{
    private string myName ="N/A";
    private int myAge = 0;

    public string Name
    {
        get 
        {
           return myName; 
        }
        set 
        {
           myName = value; 
        }
    }

    public int Age
    {
        get 
        { 
           return myAge; 
        }
        set 
        { 
           myAge = value; 
        }
    }

    public string Info
    {
		get
		{
			return "Name:" + Name + ",Age:" + Age;
		}
    }

    public static void Main()
    {
        Console.WriteLine("Simple Properties");
        Person person = new Person();
        Console.WriteLine( person.Info);

        person.Name = "Joe";
        person.Age = 99;
        Console.WriteLine( person.Info );

        person.Age += 1;
        Console.WriteLine( person.Info );
    }
}
