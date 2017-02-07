#include <stdio.h>

int main( void)
{
	int r = 0, c = 0, i = 0, j = 0;
	int data[100][100] = {0}, ave = 0;
	
	scanf( "%d%d", &r, &c);
	
	for( i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			scanf( "%d", &data[i][j]);
		}
	}
	
	for( i = 0; i < c; i++)
	{
		ave = 0;
		for( j = 0; j < r; j++)
		{
			ave += data[j][i];
		}
		ave /= j;
		printf( "%d\n", ave);
	}
	
	return 0;
}
