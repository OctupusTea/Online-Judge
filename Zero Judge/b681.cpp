#include <stdio.h>

int main( void)
{
	int d = 0;
	
	while( ~scanf( "%d", &d) )
	{
		if( d > 0)
		{
			printf( "%d\n", 2 * d - 1);
		}
		else
		{
			printf( "%d\n", -2 * d);
		}
	}
	
	return 0;
}
