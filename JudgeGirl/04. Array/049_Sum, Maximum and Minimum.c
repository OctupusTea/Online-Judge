#include <stdio.h>

int main( void)
{
	int n = 0, m = 0, i = 0, temp = 0;
	int sum[1000] = {0}, min[1000] = {0}, max[1000] = {0};
	
	scanf( "%d%d", &n, &m);
	
	for( i = 0; i < m; i++)
	{
		min[i] = 2147483647;
	}
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &temp);
		
		sum[ temp%m ] += temp;
		
		if( temp > max[ temp%m ] )
		{
			max[ temp%m ] = temp;
		}
		
		if( temp < min[ temp%m ] )
		{
			min[ temp%m ] = temp;
		}
	}
	
	for( i = 0; i < m; i++)
	{
		printf( "%d %d %d\n", sum[i], max[i], min[i] );
	}
	
	return 0;
}
