#include <stdio.h>

int main( void)
{
	int a = 0, b = 0, c = 0;
	scanf( "%d%d%d", &a, &b, &c);
	
	printf( "%d\n", ( a * b + b * c + c * a ) * 2);
	printf( "%d", a * b * c);
	
	return 0;
} 
