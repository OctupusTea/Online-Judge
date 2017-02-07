#include <stdio.h>

int main( void)
{
	int r = 0, c = 0, i = 0, j = 0, k = 0;
	int data[100][100] = {0}, isLargest = 1;
	
	scanf( "%d%d", &r, &c);
	
	for( i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			scanf( "%d", &data[i][j]);
		}
	}
	
	for( i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			isLargest = 1;
			
			if( i > 0 && data[i][j] <= data[i-1][j] )
			{
				isLargest = 0;
			}
			
			if( i < r - 1 && data[i][j] <= data[i+1][j] )
			{
				isLargest = 0;
			}
			
			if( j > 0 && data[i][j] <= data[i][j-1] )
			{
				isLargest = 0;
			}
			
			if( j < c - 1 && data[i][j] <= data[i][j+1] )
			{
				isLargest = 0;
			}
			
			if( isLargest)
			{
				printf( "%d\n", data[i][j]);
			}
		}
	}
	return 0;
}
