#include <stdio.h>

int main( void)
{
	int point[4][2] = {0};
	int i = 0, j = 0;
	int area = 0;
	
	for( i = 0; i < 4; i++)
	{
		for( j = 0; j < 2; j++)
		{
			scanf( "%d", &point[i][j]);
		}
	}
	
	area = abs( point[0][0] * point[1][1] + point[1][0] * point[2][1] + point[2][0] * point[0][1] - point[0][0] * point[2][1] - point[1][0] * point[0][1] - point[2][0] * point[1][1] );
	area += abs( point[0][0] * point[3][1] + point[3][0] * point[2][1] + point[2][0] * point[0][1] - point[0][0] * point[2][1] - point[3][0] * point[0][1] - point[2][0] * point[3][1] );
	
	for( i = 0; i < 4; i++)
	{
		area -= abs( point[i][0] * point[ (i+1)%4 ][1] - point[ (i+1)%4 ][0] * point[i][1] );
	}
	
	if( area == 0)
	{
		printf( "1");
	}
	else
	{
		printf( "0");
	}
	
	return 0;
}
