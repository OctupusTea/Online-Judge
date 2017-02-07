#include <stdio.h>

int main( void)
{
	int n = 0, i = 0;
	int data[1000] = {0};
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &data[i]);
	}
	
	for( i = n-1; i > 0; i--)
	{
		printf( "%d ", data[i]);
	}
	printf( "%d", data[0]);
	
	return 0;
}
