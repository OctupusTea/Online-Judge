#include <stdlib.h>
#include <stdio.h>
#include <math.h>

inline int Min_Of( int a, int b )
{
	return a < b ? a : b;
}

inline int Max_Of( int a, int b )
{
	return a > b ? a : b;
}

inline int In_Line( int curr_x, int curr_y, int prev_x, int prev_y )
{
	if( curr_x == prev_x )
	{
		return 1;
	}
	else if( curr_y == prev_y )
	{
		return 2;
	}
	else if( abs( curr_x - prev_x ) == abs( curr_y - prev_y ) )
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int main( void )
{
	int graph[ 128 ][ 128 ] = { 0 };
	
	int l, x, y;
	scanf( "%d%d%d", &l, &y, &x );
	
	for( int i = 0; i < l; i++ )
	{
		int prev_x, prev_y;
		int curr_x, curr_y;
		int n;
		scanf( "%d%d%d", &n, &prev_x, &prev_y );
		
		if( prev_x < 0 || prev_x >= x || prev_y < 0 || prev_y >= y )
		{
			printf( "ERROR %d %d\n", i + 1, 1 );
			l = -l;
		}
		else
		{
			for( int j = 0; j < n - 1; j++ )
			{
				scanf( "%d%d", &curr_x, &curr_y );
				
				if( curr_x < 0 || curr_x >= x || curr_y < 0 || curr_y >= y )
				{
					printf( "ERROR %d %d\n", i + 1, j + 2 );
					l = -l, j = n;
				}
				else
				{
					int in_line = In_Line( curr_x, curr_y, prev_x, prev_y );
					
					if( in_line == 1 )
					{
						int start = Min_Of( curr_y, prev_y ), end = Max_Of( curr_y, prev_y );
						
						for( int k = start; k <= end; k++ )
						{
							graph[ curr_x ][ k ] = 1;
						}
					}
					else if( in_line == 2 )
					{
						int start = Min_Of( curr_x, prev_x ), end = Max_Of( curr_x, prev_x );
						
						for( int k = start; k <= end; k++ )
						{
							graph[ k ][ curr_y ] = 1;
						}
					}
					else if( in_line == 3 )
					{
						if( ( curr_x - prev_x ) * ( curr_y - prev_y ) > 0 )
						{
							int start_x = Min_Of( curr_x, prev_x ), start_y = Min_Of( curr_y, prev_y ), length = abs( curr_x - prev_x );
							for( int k = 0; k <= length; k++ )
							{
								graph[ start_x + k ][ start_y + k ] = 1;
							}
						}
						else
						{
							int start_x = Min_Of( curr_x, prev_x ), start_y = Max_Of( curr_y, prev_y ), length = abs( curr_x - prev_x );
							for( int k = 0; k <= length; k++ )
							{
								graph[ start_x + k ][ start_y - k ] = 1;
							}
						}
					}
					else
					{
						printf( "ERROR %d %d\n", i + 1, j + 2 );
						l = -l, j = n;
					}
				}
				
				prev_x = curr_x;
				prev_y = curr_y;
			}
		}
	}
		
	if( l > 0 )
	{
		for( int j = y - 1; j >= 0; j-- )
		{
			for( int k = 0; k < x; k++ )
			{
				printf( "%d", graph[ k ][ j ] );
			}
			printf( "\n" );
		}
	}
	
	return 0;
}