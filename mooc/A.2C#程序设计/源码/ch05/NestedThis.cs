class Polygon
{
	class Point
	{
		Polygon polygon;
		int x, y;
		public Point( Polygon polygon, int x, int y )
		{
			this.polygon = polygon;
			this.x = x;
			this.y = y;
		}
		public void M()
		{
			// if( polygon....) ;.....
		}
	}

	public void AddPoint( int x, int y)
	{
		Point point = new Point( this, x, y );
		points[ num ++ ] = point;
	}
	Point [] points = new Point[ 100];
	int num = 0;
}

class Test
{
	static void Main(){}
}