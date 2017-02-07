#include <stdio.h>

int main( void)
{
	int n = 0, i = 0;
	
	scanf( "%d", &n);
	
	for( i = 1; i <= n; i++)
	{
		printf( "%d\n", i);
	}
	for( i = n-1; i > 0; i--)
	{
		printf( "%d\n", i);
	}	
	
	return 0;
}
