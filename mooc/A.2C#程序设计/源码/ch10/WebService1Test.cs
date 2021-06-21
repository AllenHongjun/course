using System;
namespace WebServiceTest
{
	class Class1
	{
		static void Main(string[] args)
		{
			localhost.Service1 srv = new localhost.Service1();
			string result = srv.HelloWorld( "tang dashi");
			Console.WriteLine( result );
		}
	}
}
