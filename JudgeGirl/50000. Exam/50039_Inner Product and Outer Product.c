#include <stdio.h>

int main( void)
{
	int vec[3][3] = {0};
	int i = 0, j = 0;
	int inn = 0;
	
	for( i = 0; i < 2; i++)
	{
		for( j = 0; j < 3; j++)
		{
			scanf( "%d", &vec[i][j]);
		}
	}
	
	for( i = 0; i < 3; i++)
	{
		inn += vec[0][i] * vec[1][i];
	}
	
	for( i = 0; i < 3; i++)
	{
		vec[2][i] = vec[0][(i+1)%3] * vec[1][(i+2)%3] - vec[0][(i+2)%3] * vec[1][(i+1)%3];
	}
	
	printf( "%d\n%d %d %d", inn, vec[2][0], vec[2][1], vec[2][2]);
	
	return 0;
}
