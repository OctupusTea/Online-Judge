#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 16

int main( void )
{
	int base_size, pattern_size, mismatch_limit, distance_limit;
	scanf( "%d%d%d%d", &base_size, &pattern_size, &mismatch_limit, &distance_limit );
	
	int base[ MAX_LENGTH ][ MAX_LENGTH ] = { 0 };
	int pattern[ MAX_LENGTH ][ MAX_LENGTH ] = { 0 };
	int pattern_sum = 0;
	
	for( int i = 0; i < base_size; i++ )
	{
		for( int j = 0; j < base_size; j++ )
		{
			scanf( "%d", &base[ i ][ j ] );
		}
	}
	
	for( int i = 0; i < pattern_size; i++ )
	{
		for( int j = 0; j < pattern_size; j++ )
		{
			scanf( "%d", &pattern[ i ][ j ] );
			pattern_sum += pattern[ i ][ j ];
		}
	}
	
	int search_size = base_size - pattern_size + 1;
	int last_match_x = -1, last_match_y = -1;
	for( int i = 0; i < search_size; i++ )
	{
		for( int j = 0; j < search_size; j++ )
		{
			#ifdef DEBUG
				printf( "%d, %d\n", i, j );
			#endif
			int mismatch_count = 0;
			int base_sum = 0;
			for( int k = 0; k < pattern_size; k++ )
			{
				for( int l = 0; l < pattern_size; l++ )
				{
					base_sum += base[ i + k ][ j + l ];
					if( base[ i + k ][ j + l ] != pattern[ k ][ l ] )
					{
						mismatch_count++;
						
						if( mismatch_count > mismatch_limit )
						{
							k = pattern_size, l = pattern_size;
						}
					}
				}
			}
			#ifdef DEBUG
				printf( "\t%d, %d\n", mismatch_count, abs( base_sum - pattern_sum ) );
			#endif
			if( mismatch_count <= mismatch_limit && abs( base_sum - pattern_sum ) <= distance_limit )
			{
				last_match_x = i;
				last_match_y = j;
			}
		}
	}
	
	printf( "%d %d\n", last_match_x, last_match_y );
	
	return 0;
}