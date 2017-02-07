#include <stdio.h>

int main( void)
{
	int a = 0, b = 0;
	scanf( "%d", &a);
	b += a;
	scanf( "%d", &a);
	b += a;
	scanf( "%d", &a);
	b += a;
	
	printf( "%d", b);
	
	return 0;
}
