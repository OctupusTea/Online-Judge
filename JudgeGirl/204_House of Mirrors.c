#include <stdio.h>

int main( void)
{
	int w = 0, d = 0;
	int i = 0, j = 0, k = 0;
	int mir[100][100] = {0};
	int x = 0, y = 0, dir = 0;
	
	scanf( "%d%d", &w, &d);
	
	for( i = 0; i < d; i++)
	{
		for( j = 0; j < w; j++)
		{
			scanf( "%d", &mir[j][i]);
		}
	}
	
	for( i = 0; i < w; i++)
	{
		dir = 0;
		x = i;
		y = d;
		//printf( "%d %d\n", x, y);
		while( 1)
		{
			if( dir)
			{
				x++;
			}
			else
			{
				y--;
			}
			//printf( "%d %d %d\n", x, y, mir[x][y]);
			
			if( x >= w)
			{
				printf( "%d\n", d + w - y - 1);
				break;
			}
			if( y < 0)
			{
				printf( "%d\n", 2 * w + d - x - 1);
				break;
			}
			
			if( mir[x][y])
			{
				if( dir)
				{
					dir = 0;
				}
				else
				{
					dir = 1;
				}
			}
		}
	}
	
	for( i = d - 1; i >= 0; i--)
	{
		dir = 3;
		x = w;
		y = i;
		//printf( "%d %d\n", x, y);
		while( 1)
		{
			if( dir == 3)
			{
				x--;
			}
			else
			{
				y++;
			}
			//printf( "%d %d %d\n", x, y, mir[x][y]);
			
			if( x < 0)
			{
				printf( "%d\n", 2 * w + d + y);
				break;
			}
			if( y >= d)
			{
				printf( "%d\n", x);
				break;
			}
			
			if( mir[x][y])
			{
				if( dir == 3)
				{
					dir = 2;
				}
				else
				{
					dir = 3;
				}
			}
		}
	}
	
	for( i = w - 1; i >= 0; i--)
	{
		dir = 2;
		x = i;
		y = -1;
		//printf( "%d %d\n", x, y);
		while( 1)
		{
			if( dir == 3)
			{
				x--;
			}
			else
			{
				y++;
			}
			//printf( "%d %d %d\n", x, y, mir[x][y]);
			
			if( x < 0)
			{
				printf( "%d\n", 2 * w + d + y);
				break;
			}
			if( y >= d)
			{
				printf( "%d\n", x);
				break;
			}
			
			if( mir[x][y])
			{
				if( dir == 3)
				{
					dir = 2;
				}
				else
				{
					dir = 3;
				}
			}
		}
	}
	
	for( i = 0; i < d; i++)
	{
		dir = 1;
		x = -1;
		y = i;
		//printf( "%d %d\n", x, y);
		while( 1)
		{
			if( dir)
			{
				x++;
			}
			else
			{
				y--;
			}
			//printf( "%d %d %d\n", x, y, mir[x][y]);
			
			if( x >= w)
			{
				printf( "%d\n", d + w - y - 1);
				break;
			}
			if( y < 0)
			{
				printf( "%d\n", 2 * w + d - x - 1);
				break;
			}
			
			if( mir[x][y])
			
			{
				if( dir)
				{
					dir = 0;
				}
				else
				{
					dir = 1;
				}
			}
		}
	}
	
	return 0;
}
