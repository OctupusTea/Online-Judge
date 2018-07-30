#include <stdio.h>
#include <stdlib.h>

#include "attraction.h"

int width;

int Circle( Attraction attraction )
{
	int dist[ 4 ] = { attraction.x, attraction.y, width - attraction.x - 1, width - attraction.y - 1 };

	int min = dist[ 0 ];
	for( int i = 1; i < 4; ++i )
	{
		if( dist[ i ] < min )
		{
			min = dist[ i ];
		}
	}

	return min;
}

int Direction( Attraction attraction )
{
	if( attraction.y == 0 )
	{
		return 0;
	}
	else if( attraction.y < attraction.x )
	{
		return 1;
	}
	else if( attraction.x != 0 )
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int Compare_Direction( Attraction p, Attraction q, int direction )
{
	switch( direction )
	{
		case 0:
		{
			return p.x > q.x ? 1 : -1;
		}
		case 1:
		{
			return p.y > q.y ? 1 : -1;
		}
		case 2:
		{
			return p.x < q.x ? 1 : -1;
		}
		case 3:
		{
			return p.y < q.y ? 1 : -1;
		}
	}
}

int Compare( const void *a, const void *b )
{
	Attraction p = *( Attraction* )a;
	Attraction q = *( Attraction* )b;

	int p_circle = Circle( p );
	int q_circle = Circle( q );

	if( p_circle > q_circle )
	{
		return 1;
	}
	else if( p_circle < q_circle )
	{
		return -1;
	}

	p.x -= p_circle;
	p.y -= p_circle;

	q.x -= q_circle;
	q.y -= q_circle;

	int p_dir = Direction( p );
	int q_dir = Direction( q );

	if( p_dir > q_dir )
	{
		return 1;
	}
	else if( p_dir < q_dir )
	{
		return -1;
	}

	return Compare_Direction( p, q, p_dir );
}

int main( int argc, char **argv )
{
	FILE *file = fopen( argv[ 1 ], "rb" );

	int attraction_count;
	Attraction attraction_list[ MAXM ];

	scanf( "%d%d", &width, &attraction_count );

	fread( attraction_list, sizeof( Attraction ), attraction_count, file );

	qsort( attraction_list, attraction_count, sizeof( Attraction ), Compare );

	for( int i = 0; i < attraction_count; ++i )
	{
		printf( "%d %d\n", attraction_list[ i ].x, attraction_list[ i ].y );
	}

	return 0;
}

