using System;
using System.Runtime.InteropServices;
class Test
{
	// 导入 Windows PlaySound() 函数
	[DllImport("winmm.dll")]
	public static extern bool PlaySound(
		string pszSound,
		int hmod,
		int fdwSound);

	// 定义PlaySound()要使用的常数
	public const int SND_FILENAME = 0x00020000;
	public const int SND_ASYNC = 0x0001;

	static void Main(string[] args)
	{
		// 播放声音文件
		PlaySound(
			@"c:\winnt\media\chimes.wav",
			0,
			SND_FILENAME | SND_ASYNC);
		Console.ReadLine();
	}
}
