using System;
using Env = System.Environment;
class Test
{
	static void Main()
	{
		string s = "";
		s += "\n当前程序名:\t" 
			+ Env.GetCommandLineArgs()[0];
		s += "\n当前目录:\t" 
			+ Env.CurrentDirectory;
		s += "\nWin操作系统:\t" 
			+ (Env.OSVersion.Platform == PlatformID.Win32NT);
		s += "\n环境变量Temp:\t"  
			+ Env.GetEnvironmentVariable( "temp" );

		Console.WriteLine( s );
	}
}

