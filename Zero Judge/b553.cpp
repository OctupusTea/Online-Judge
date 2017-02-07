#include <stdio.h>

int main( void)
{
	int n = 0, counter = 0;
	
	while( ~scanf( "%d", &n) )
	{
		counter = 0;
		while( n != 1)
		{
			if( n % 2 == 1)
			{
				n *= 3;
				n++;
			}
			else
			{
				n /= 2;
			}
			counter++;
		}
		printf( "%d\n", counter);
	}
	
	return 0;
}
