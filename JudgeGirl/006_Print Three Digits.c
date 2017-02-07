#include<stdio.h>

int main( void)
{
	int x = 0;
	scanf( "%d", &x);
	printf( "%d\n", x/100);
	x %= 100;
	printf( "%d\n", x/10);
	x %= 10;
	printf( "%d\n", x);
	
	return 0;
}
