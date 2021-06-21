//下面的例子声明了一个BitArray 类，它在一个位阵列中为访问单独的位提供了一个索引。
//注意BitArray 访问元素的语法与bool[]的完全相同。
//一个类BitArray的实例比相应的bool[] 消耗更少的存储空间(每个数据只占用一位而不是一个字)，但是它允许和bool[]一样操作。
//下面的类CountPrimes 使用BitArray 和经典的"筛选"算法来计算从1到一个最大给定数据间的数据：

using System;
class BitArray
{
	int[] bits;
	int length;
	public BitArray(int length) {
		if (length < 0) throw new ArgumentException();
		bits = new int[((length - 1) >> 5) + 1];
		this.length = length;
	}
	public int Length {
		get { return length; }
	}
	public bool this[int index] {
		get {
			if (index < 0 || index >= length) {
				throw new IndexOutOfRangeException();
			}
			return (bits[index >> 5] & 1 << index) != 0;
		}
		set {
			if (index < 0 || index >= length) {
				throw new IndexOutOfRangeException();
			}
			if (value) {
				bits[index >> 5] |= 1 << index;
			}
			else {
				bits[index >> 5] &= ~(1 << index);
			}
		}
	}
}
class CountPrimes
{
	static int Count(int max) {
		BitArray flags = new BitArray(max + 1);
		int count = 1;
		for (int i = 2; i <= max; i++) {
			if (!flags[i]) {
				for (int j = i * 2; j <= max; j += i) 
					flags[j] = true;
				count++;
			}
		}
		return count;
	}
	static void Main() {
		Console.Write( "请输入一个数： " );
		string s = Console.ReadLine();
		int max = int.Parse(s);
		int count = Count(max);
		Console.WriteLine("在 1 与 {0}找到 {1} 个素数", 
			max, count);
	}
}
