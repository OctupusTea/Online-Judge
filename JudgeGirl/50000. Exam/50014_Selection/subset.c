#include "subset.h"
#include <stdio.h>

int Subset( int data[ ], int n, int sum, int size )
{
	if( size == 0 )
	{
		return ( sum == 0 );
	}

	if( n == 0 )
	{
		return 0;
	}

	int next = data[ n - 1 ];

	if( sum >= next )
	{
		if( Subset( data, n - 1, sum - next, size - 1 ) )
		{
			return 1;
		}
	}

	if( Subset( data, n - 1, sum, size ) )
	{
		return 1;
	}

	return 0;
}

int subset( int numbers[ ], int n, int K, int S )
{
	if( S * 2 > n )
	{
		int sum = 0;
		for( int i = 0; i < n; ++i )
		{
			sum += numbers[ i ];
		}

		S = n - S;
		K = sum - K;
	}

	return Subset( numbers, n, K, S );
}

