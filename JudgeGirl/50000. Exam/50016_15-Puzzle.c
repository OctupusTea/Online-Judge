#include <stdio.h>

const int winning_board[ 4 ][ 4 ] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 0 } };

#ifdef DEBUG
void Print( int board[ 4 ][ 4 ] )
{
	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			printf( "%2d", board[ i ][ j ] );
		}
		printf( "\n" );
	}
	printf( "\n" );
}
#endif

int Diff( int board[ 4 ][ 4 ] )
{
	int count = 0;

	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			if( board[ i ][ j ] != winning_board[ i ][ j ] )
			{
				++count;
			}
		}
	}
#ifdef DEBUG
	printf( "Diff returns %d.\n", ( count == 0 ? 0 : count - 1 ) );
#endif
	return ( count == 0 ? 0 : count - 1 );
}

void Clone( int dest[ 4 ][ 4 ], int src[ 4 ][ 4 ] )
{
	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			dest[ i ][ j ] = src[ i ][ j ];
		}
	}
}

void Find( int board[ 4 ][ 4 ], int value, int *x, int *y )
{
	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			if( board[ i ][ j ] == value )
			{
				*x = i;
				*y = j;
			}
		}
	}
}

inline int Anti_Dir( int direction )
{
	return ( direction + 2 ) % 4;
}

int Move( int board[ 4 ][ 4 ], int *x0, int *y0, int direction )
{
	int x = *x0, y = *y0;

	switch( direction )
	{
		case 0:
			if( x == 0 ) { return 0; }

			board[ x ][ y ] = board[ x - 1 ][ y ];
			board[ x - 1 ][ y ] = 0;
			--(*x0);

			break;
		case 1:
			if( y == 3 ) { return 0; }
			
			board[ x ][ y ] = board[ x ][ y + 1 ];
			board[ x ][ y + 1 ] = 0;
			++(*y0);

			break;
		case 2:
			if( x == 3 ) { return 0; }

			board[ x ][ y ] = board[ x + 1 ][ y ];
			board[ x + 1 ][ y ] = 0;
			++(*x0);

			break;
		case 3:
			if( y == 0 ) { return 0; }
			
			board[ x ][ y ] = board[ x ][ y - 1 ];
			board[ x ][ y - 1 ] = 0;
			--(*y0);

			break;
		default:
			return 0;
	}

	return 1;
}

int Trial( int board[ 4 ][ 4 ], int step_count, int x0, int y0, int direction )
{
#ifdef DEBUG
	printf( "\nstep #%d, x0 = %d, y0 = %d, direction = %d\n", step_count, x0, y0, direction );
#endif

	int next_board[ 4 ][ 4 ];
	Clone( next_board, board );
	int next_x0 = x0, next_y0 = y0;

	if( Move( next_board, &next_x0, &next_y0, direction ) == 0 )
	{
#ifdef DEBUG
		printf( "Illegal move.\n" );
#endif
		return 0;
	}

	int diff = Diff( next_board );
#ifdef DEBUG
	Print( next_board );
	printf( "diff = %d\n", diff );
#endif

	if( step_count == 0 )
	{
		return 0;
	}
	else if( diff == 0 )
	{
		return 1;
	}
	else if( diff > step_count )
	{
		return 0;
	}

	int anti_dir = Anti_Dir( direction );

	for( int dir = 0; dir < 4; ++dir )
	{
		if( dir != anti_dir )
		{
			if( Trial( next_board, step_count - 1, next_x0, next_y0, dir ) == 1 )
			{
				return 1;
			}
		}
	}

	return 0;
}

int main( void )
{
	int step_count;
	int board[ 4 ][ 4 ];
	int x0, y0;

	while( ~scanf( "%d", &step_count ) )
	{
		for( int i = 0; i < 4; ++i )
		{
			for( int j = 0; j < 4; ++j )
			{
				scanf( "%d", &board[ i ][ j ] );

				if( board[ i ][ j ] == 0 )
				{
					x0 = i, y0 = j;
				}
			}
		}

		int diff = Diff( board );
		
		if( diff == 0 )
		{
			printf( "1\n" );
		}
		else if( diff > step_count )
		{
			printf( "0\n" );
		}
		else 
		{
			int found = 0;
			for( int i = 0; i < 4 && found == 0; ++i )
			{
				if( Trial( board, step_count, x0, y0, i ) )
				{
					found = 1;
				}
			}

			printf( "%d\n", found );
		}
#ifdef DEBUG
		printf( "\n========================================\n" );
#endif
	}

	return 0;
}
