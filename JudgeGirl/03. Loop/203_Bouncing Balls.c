#include <stdio.h>

int main( void)
{
	int X = 0, Y = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	int i = 0, n = 0;
	
	scanf( "%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &n);
	
	for( i = 0; i < n; i++)
	{
		if( x1 + dx1 > X || x1 + dx1 < 0 )
		{
			dx1 = -dx1;
		}
		if( y1 + dy1 > Y || y1 + dy1 < 0 )
		{
			dy1 = -dy1;
		}
		
		if( x2 + dx2 > X || x2 + dx2 < 0 )
		{
			dx2 = -dx2;
		}
		if( y2 + dy2 > Y || y2 + dy2 < 0 )
		{
			dy2 = -dy2;
		}
		
		if( x1 + dx1 == x2 + dx2 && y1 + dy1 == y2 + dy2)
		{
			/*x1 += dx1;
			y1 += dy1;
				
			x2 += dx2;
			y2 += dy2;
			
			i++;
			*/
			if( dx1 != dx2)
			{
				dx1 = -dx1;
				dx2 = -dx2;
			}
			if( dy1 != dy2)
			{
				dy1 = -dy1;
				dy2 = -dy2;
			}
		}
		
		x1 += dx1;
		y1 += dy1;
		
		x2 += dx2;
		y2 += dy2;
		
		i++;
	}
	
	printf( "%d\n%d\n%d\n%d", x1, y1, x2, y2);
	
	return 0;
}
