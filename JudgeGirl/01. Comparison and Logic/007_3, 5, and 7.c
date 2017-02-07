#include <stdio.h>

int main( void)
{
	int x = 0;
	scanf( "%d", &x);
	
	if( (!( x % 3 )) && (!( x % 5 )) && ( x % 7) )
	{
		printf( "0");
	}
	else
	{
		printf( "1");
	}
	return 0;
}
