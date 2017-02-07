#include <stdio.h>
#include <iostream>
using namespace std;

int main( void)
{
	int t = 0, n = 0;
	int i = 0, j = 0;
	int ans[99][99] = {0};
	int x = 0, y = 0;
	int counter = 0;
	
	while( cin >> t)
	{
		while( cin >> n)
		{
			x = ( n - 1 ) / 2;
			y = x;
			counter = 0;
			ans[y][x] = ++counter;
			for( i = 1; i <= ( n - 1 ) / 2; i++)
			{
				x++;
				ans[y][x] = ++counter;
				
				for( j = 0; j < 2 * i - 1; j++)
				{
					y--;
					ans[y][x] = ++counter;
				}
				
				for( j = 0; j < 2 * i; j++)
				{
					x--;
					ans[y][x] = ++counter;
				}
				
				for( j = 0; j < 2 * i; j++)
				{
					y++;
					ans[y][x] = ++counter;
				}
				
				for( j = 0; j < 2 * i; j++)
				{
					x++;
					ans[y][x] = ++counter;
				}
			}
			
			for( i = 0; i < n; i++)
			{
				for( j = 0; j < n; j++)
				{
					printf( "%4d ", ans[i][j]);
				}
				printf( "\n");
			}
		}
	}
	
	return 0;
}
