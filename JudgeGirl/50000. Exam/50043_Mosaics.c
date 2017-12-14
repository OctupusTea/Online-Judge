#include <stdio.h>
#include <stdlib.h>

inline int Max( int a, int b )
{
	return a > b ? a : b;
}

inline int Min( int a, int b )
{
	return a < b ? a : b;
}

inline int In_Triangle( int x1, int y1, int x2, int y2, int x3, int y3, int i, int j )
{
	int area_diff = abs( ( x1 - x3 ) * ( y2 - y1 ) - ( x1 - x2 ) * ( y3 - y1 ) ) - abs( ( i - x3 ) * ( y2 - j ) - ( i - x2 ) * ( y3 - j ) ) - abs( ( x1 - x3 ) * ( j - y1 ) - ( x1 - i ) * ( y3 - y1 ) ) - abs( ( x1 - i ) * ( y2 - y1 ) - ( x1 - x2 ) * ( j - y1 ) );
	return area_diff == 0;
}

inline int In_Square( int x1, int y1, int x2, int y2, int x3, int y3, int i, int j )
{
	return ( In_Triangle( x1, y1, x2, y2, x3, y3, i, j ) && In_Triangle( x1, y1, x2, y2, x3, y3, i + 1, j ) && In_Triangle( x1, y1, x2, y2, x3, y3, i, j + 1 ) && In_Triangle( x1, y1, x2, y2, x3, y3, i + 1, j + 1 ) );
}

int main( void )
{
	int x1, y1, x2, y2, x3, y3;
	scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );

	int top = Max( y1, Max( y2, y3 ) );
	int bottom = Min( y1, Min( y2, y3 ) );
	int left = Min( x1, Min( x2, x3 ) );
	int right = Max( x1, Max( x2, x3 ) );
	int count = 0;

	for( int i = left; i < right; ++i )
	{
		for( int j = bottom; j < top; ++j )
		{
			if( In_Square( x1, y1, x2, y2, x3, y3, i, j ) )
			{
				++count;
			}
		}
	}
	
	printf( "%d\n", count );

	return 0;
}
