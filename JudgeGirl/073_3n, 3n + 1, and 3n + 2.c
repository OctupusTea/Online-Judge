#include <stdio.h>

int main( void)
{
	int n = 0, i = 0;
	int ans[3] = {0};
	int temp = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &temp);
		
		ans[ temp%3 ]++;
	}
	
	printf( "%d %d %d", ans[0], ans[1], ans[2]);
	
	return 0;
}
