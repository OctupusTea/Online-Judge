#include <stdio.h>

int main(void)
{
	int n = 0, m = 0, i = 0, j = 0;
	int poly[3][200] = {0};
	
	scanf( "%d", &n );
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &poly[0][i] );
	}
	
	scanf( "%d", &m );
	for( i = 0; i < m; i++)
	{
		scanf( "%d", &poly[1][i] );
	}
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < m; j++)
		{
			poly[2][i+j] += poly[0][i] * poly[1][j];
		}
	}
	
	
	for( i = m+n; i > 0; i--)
	{
		if( poly[2][i] != 0 )
		{
			break;
		}
	}
	
	for( j = 0; j < i; j++)
	{
		printf( "%d ", poly[2][j] ); 
	}
	printf( "%d", poly[2][i] );
	
	return 0;
}
