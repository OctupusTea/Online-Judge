#include <stdio.h>

int main( void)
{
	int n = 0, i = 0, j = 0, ans = 1;
	
	scanf( "%d%d", &n, &i);
	
	for( j = 0; j < i; j++)
	{
		ans *= n;
	}
	
	printf( "%d", ans);
	
	return 0;
}
