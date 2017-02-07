#include <stdio.h>

int main( void)
{
	int data[200000] = {0};
	int mod[200000] = {0};
	int n = 0, m = 0, i = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &data[i]);
	}
	
	scanf( "%d", &m);
	
	for( i = 0; i < n; i++)
	{
		mod[ data[i] % m ] ++;
	}
	
	for( i = 0; i < m; i++)
	{
		printf( "%d\n", mod[i]);
	}
	
	return 0;
}
