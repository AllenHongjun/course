using System;
using System.Collections;

class SortArrayList : ArrayList 
{
	private IComparer comparer; // To hold the callback
	public SortArrayList(IComparer comp) 
	{
		comparer = comp;
	}
	public void QuickSort() 
	{
		QuickSort(0, this.Count - 1);
	}
	private void QuickSort(int left, int right) 
	{		if(right > left) 
		{
			object o1 = this[right];
			int i = left - 1;
			int j = right;
			while(true) 
			{
				while(comparer.Compare(
					this[++i], o1) < 0 )
					;
				while(j > 0)
					if(comparer.Compare(
						this[--j], o1) <= 0 )
						break; // out of while
				if(i >= j) break;
				Swap(i, j);
			}
			Swap(i , right);
			QuickSort(left, i-1);
			QuickSort(i+1, right);
		}
	}
	private void Swap(int loc1, int loc2) 
	{
		object tmp = this[loc1];
		this[loc1] = this[loc2];
		this[loc2] = tmp;
	}
} 

class QuickSortTest 
{
	public class StringComparer : IComparer 
	{
		public int Compare(object l, object r)
		{
			return ((string)l).ToLower().CompareTo(
				((string)r).ToLower());
		}
	}
	public static void Main(string[] args) 
	{
		SortArrayList list = 
			new SortArrayList(new StringComparer());
		list.Add("d");
		list.Add("A");
		list.Add("C");
		list.Add("c");
		list.Add("b");
		list.Add("B");
		list.Add("D");
		list.Add("a");
		list.QuickSort();
		foreach( string  s in list )
			Console.WriteLine(s);
	}
} 
