#include <stdio.h>

int main( void)
{
	int m = 0, n = 0, x0 = 0, y0 = 0, x = 0, y = 0, i = 0, j = 0;
	
	while( ~scanf( "%d%d%d%d", &m, &n, &x0, &y0) )
	{
		x = x0, y = y0;
		do
		{
			printf( "%d %d\n", x, y);
			
			if( m == 2 )
			{
				if( x == 0 && y != 0 )
				{
					y--;
				}
				else if( y == 0 && x == 0 )
				{
					x++;
				}
				else if( y != n - 1 && x == 1 )
				{
					y++;
				}
				else
				{
					x--;
				}
			}
			else if( y == n - 1 && x != 0 )
			{
				x--;
			}
			else if( x == 0 && y != 0 )
			{
				y--;
			}
			else if( y == 0 && x != m - 1 )
			{
				x++;
			}
			else if( x == m - 1 )
			{
				if( y % 2 == 0 )
				{
					y++;
				}
				else
				{
					x--;
				}
			}
			else if( x < m - 1 && x > 1 )
			{
				if( y % 2 == 0 )
				{
					x++;
				}
				else
				{
					x--;
				}
			}
			else if( x == 1 )
			{
				if( y %2 == 0 )
				{
					x++;
				}
				else
				{
					y++;
				}
			}
		}while( x != x0 || y != y0 );
		
		printf( "%d %d\n", x0, y0);
	}
	
	return 0;
}
