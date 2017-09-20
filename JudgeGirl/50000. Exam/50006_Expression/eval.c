#include "eval.h"

#ifdef DEBUG
	#include <stdio.h>
#endif

int eval( int exp[ ] )
{
	#ifdef DEBUG
		printf( "exp[ 0 ] = %d, exp[ 1 ] = %d\n", exp[ 0 ], exp[ 1 ] );
	#endif
	if( exp[ 0 ] == 3 )
	{
		switch( exp[ 2 ] )
		{
			case 1 :
				return exp[ 1 ] + exp[ 3 ];
				break;
			case 2 :
				return exp[ 1 ] - exp[ 3 ];
				break;
			case 3 :
				return exp[ 1 ] * exp[ 3 ];
				break;
			case 4 :
				return exp[ 3 ] == 0 ? -2147483647 : (exp[ 1 ] / exp[ 3 ] );
				break;
			default :
				return -2147483646;
				break;
		}
	}
	
	int answer = exp[ 1 ];
	for( int i = 2; i <= exp[ 0 ]; i += 2 )
	{
		#ifdef DEBUG
			printf( "answer = %d, exp[ %d ] = %d, next = %d\n", answer, i, exp[ i ], exp[ i + 1 ] );
		#endif
		if( exp[ i ] == 1 )
		{
			#ifdef DEBUG
				printf( "++++\n" );
			#endif
			int result_temp = exp[ i + 1 ];
			for( int j = i + 2; j <= exp[ 0 ]; j += 2 )
			{
				if( exp[ j ] == 3 )
				{
					#ifdef DEBUG
						printf( "    ****" );
					#endif
					result_temp *= exp[ j + 1 ];
					
					if( j == exp[ 0 ] - 1 )
					{
						i = j;
					}
				}
				else if( exp[ j ] == 4 )
				{
					#ifdef DEBUG
						printf( "    ////" );
					#endif
					if( exp[ j + 1 ] != 0 )
					{
						result_temp /= exp[ j + 1 ];
						
						if( j == exp[ 0 ] - 1 )
						{
							i = j;
						}
					}
					else
					{
						answer = -2147483647;
						result_temp = 0;
						i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
					}
				}
				else if( exp[ j ] == 1 || exp[ j ] == 2 )
				{
					i = j - 2;
					j = exp[ 0 ] + 1;
				}
				else
				{
					answer = -2147483646;
					result_temp = 0;
					i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
				}
			}
			#ifdef DEBUG
				printf( "result_temp = %d\n", result_temp );
			#endif
			answer += result_temp;
		}
		else if( exp[ i ] == 2 )
		{
			#ifdef DEBUG
				printf( "----\n" );
			#endif
			int result_temp = exp[ i + 1 ];
			for( int j = i + 2; j <= exp[ 0 ]; j += 2 )
			{
				if( exp[ j ] == 3 )
				{
					result_temp *= exp[ j + 1 ];
					
					if( j == exp[ 0 ] - 1 )
					{
						i = j;
					}
				}
				else if( exp[ j ] == 4 )
				{
					if( exp[ j + 1 ] != 0 )
					{
						result_temp /= exp[ j + 1 ];
						
						if( j == exp[ 0 ] - 1 )
						{
							i = j;
						}
					}
					else
					{
						answer = -2147483647;
						result_temp = 0;
						i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
					}
				}
				else if( exp[ j ] == 1 || exp[ j ] == 2 )
				{
					i = j - 2;
					j = exp[ 0 ] + 1;
				}
				else
				{
					answer = -2147483646;
					result_temp = 0;
					i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
				}
			}
			
			answer -= result_temp;
		}
		else if( exp[ i ] == 3 )
		{
			#ifdef DEBUG
				printf( "****\n" );
			#endif
			int result_temp = exp[ i - 1 ];
			for( int j = i; j <= exp[ 0 ]; j += 2 )
			{
				if( exp[ j ] == 3 )
				{
					result_temp *= exp[ j + 1 ];
				}
				else if( exp[ j ] == 4 )
				{
					if( exp[ j + 1 ] != 0 )
					{
						result_temp /= exp[ j + 1 ];
					}
					else
					{
						answer = -2147483647;
						result_temp = 2147483647;
						i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
					}
				}
				else if( exp[ j ] == 1 || exp[ j ] == 2 )
				{
					i = j - 2;
					j = exp[ 0 ] + 1;
				}
				else
				{
					answer = -2147483646;
					result_temp = -2147483646;
					i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
				}
			}
			
			answer = result_temp;
		}
		else if( exp[ i ] == 4 )
		{
			#ifdef DEBUG
				printf( "////\n" );
			#endif
			int result_temp = exp[ i - 1 ];
			for( int j = i; j <= exp[ 0 ]; j += 2 )
			{
				if( exp[ j ] == 3 )
				{
					result_temp *= exp[ j + 1 ];
				}
				else if( exp[ j ] == 4 )
				{
					if( exp[ j + 1 ] != 0 )
					{
						result_temp /= exp[ j + 1 ];
					}
					else
					{
						answer = -2147483647;
						result_temp = -2147483647;
						i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
					}
				}
				else if( exp[ j ] == 1 || exp[ j ] == 2 )
				{
					i = j - 2;
					j = exp[ 0 ] + 1;
				}
				else
				{
					answer = -2147483646;
					result_temp = -2147483646;
					i = exp[ 0 ] + 1, j = exp[ 0 ] + 1;
				}
			}
			
			answer = result_temp;
		}
		else
		{
			answer = -2147483646;
			i = exp[ 0 ];
		}
	}
	#ifdef DEBUG
		printf( "Final answer = %d\n\n", answer );
	#endif
	return answer;
}
