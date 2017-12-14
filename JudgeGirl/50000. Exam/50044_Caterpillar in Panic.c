#include <stdio.h>
#include <stdlib.h>

const int movement[ 4 ][ 2 ] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int In_Grid( int n, int m, int x, int y )
{
	return ( x >= 0 && x < n && y >= 0 && y < m );
}

int Collide( int caterpillar[ 1000 ][ 2 ], int caterpillar_length, int next_x, int next_y, int tail )
{
	for( int i = 0; i < caterpillar_length; ++i )
	{
		if( i != tail && caterpillar[ i ][ 0 ] == next_x && caterpillar[ i ][ 1 ] == next_y )
		{
			return 1;
		}
	}

	return 0;
}

int main( void )
{
	int x_width, y_width, movement_count;
	int head_x, head_y, tail_x, tail_y;
	int caterpillar[ 1000 ][ 2 ];
	int head_position = 0;
	int caterpillar_length;

	scanf( "%d%d%d%d%d%d%d", &x_width, &y_width, &head_x, &head_y, &tail_x, &tail_y, &movement_count );

	if( head_x == tail_x )
	{
		if( head_y < tail_y )
		{
			caterpillar_length = tail_y - head_y + 1;
			for( int i = 0; i < caterpillar_length; ++i )
			{
				caterpillar[ i ][ 0 ] = head_x;
				caterpillar[ i ][ 1 ] = i + head_y;
			}
		}
		else
		{
			caterpillar_length = head_y - tail_y + 1;
			for( int i = 0; i < caterpillar_length; ++i )
			{
				caterpillar[ i ][ 0 ] = head_x;
				caterpillar[ i ][ 1 ] = head_y - i;
			}
		}
	}
	else if( head_y == tail_y )
	{
		if( head_x < tail_x )
		{
			caterpillar_length = tail_x - head_x + 1;
			for( int i = 0; i < caterpillar_length; ++i )
			{
				caterpillar[ i ][ 0 ] = i + head_x;
				caterpillar[ i ][ 1 ] = head_y;
			}
		}
		else
		{
			caterpillar_length = head_x - tail_x + 1;
			for( int i = 0; i < caterpillar_length; ++i )
			{
				caterpillar[ i ][ 0 ] = head_x - i;
				caterpillar[ i ][ 1 ] = head_y;
			}
		}
	}

	for( int i = 0; i < movement_count; ++i )
	{
		int direction;
		scanf( "%d", &direction );
		
		int next_x = caterpillar[ head_position ][ 0 ] + movement[ direction ][ 0 ];
		int next_y = caterpillar[ head_position ][ 1 ] + movement[ direction ][ 1 ];
		int tail = head_position > 0 ? ( head_position - 1 ) : ( caterpillar_length - 1 );
		
		if( In_Grid( x_width, y_width, next_x, next_y ) != 0 && Collide( caterpillar, caterpillar_length - 1, next_x, next_y, tail ) == 0 )
		{
			caterpillar[ tail ][ 0 ] = next_x;
			caterpillar[ tail ][ 1 ] = next_y;
		}
		else
		{
			i = movement_count;
		}

		head_position = tail;
	}

	int output_board[ 1000 ][ 1000 ] = { { 0 } };
	for( int i = 0; i < caterpillar_length; ++i )
	{
		output_board[ caterpillar[ i ][ 0 ] ][ caterpillar[ i ][ 1 ] ] = 1;
	}

	for( int i = 0; i < x_width; ++i )
	{
		for( int j = 0; j < y_width; ++j )
		{
			putchar( output_board[ i ][ j ] == 0 ? '0' : '1' );
		}
		putchar( '\n' );
	}

	return 0;
}
