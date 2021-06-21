struct Point
{
	public int x, y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Test
{
	static void Main() {
		Point[] points = new Point[100];
		for (int i = 0; i < 100; i++)
			points[i] = new Point(i, i*i);
	}
}
