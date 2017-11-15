#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	unsigned data = 0;

	while( ~scanf( "%u", &data ) )
	{
		int count;

		for( count = 0; data != 0; data &= ( data >> 1 ) )
		{
			++count;
		}
		
		printf( "%d\n", count );
	}

	return 0;
}
