#include <stdio.h>

int main( void )
{
	int block_size;
	while( ~scanf( "%d", &block_size ) )
	{
		int element;
		scanf( "%d", &element );
		int block_minimum = element;
		int block_maximum = element;
		
		while( ( --block_size ) && ( ~scanf( "%d", &element ) ) )
		{
			if( element > block_maximum )
			{
				block_maximum = element;
			}
			
			if( element < block_minimum )
			{
				block_minimum = element;
			}
		}
	
		if( block_size > 0 )
		{
			printf( "%d\n", block_minimum );
		}
		else
		{
			printf( "%d\n", block_maximum );
		}
	}
	
	return 0;
}