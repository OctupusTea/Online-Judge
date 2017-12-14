#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIST(X,Y) abs((X)-(Y))

inline int String_Distance( const char *a, const char *b, const int length )
{
	int distance = 0;
	for( int i = 0; i < length; ++i )
	{
		distance += DIST( a[ i ], b[ i ] );
	}
	return distance;
}

inline void Distance( const char *leader[ 3 ], const char string[ 11 ], const int length, int distance[ 3 ] )
{
	distance[ 0 ] = String_Distance( leader[ 0 ], string, length );
	distance[ 1 ] = String_Distance( leader[ 1 ], string, length );
	distance[ 2 ] = String_Distance( leader[ 2 ], string, length );
}

inline int Group( const char string_list[ 50 ][ 11 ], const int leader[ 3 ], const int distance[ 3 ] )
{
	if( distance[ 0 ] > distance[ 1 ] )
	{
		if( distance[ 1 ] > distance[ 2 ] )
		{
			return 2;
		}
		else if( distance[ 1 ] < distance[ 2 ] )
		{
			return 1;
		}
		else
		{
			return strcmp( string_list[ leader[ 1 ] ], string_list[ leader[ 2 ] ] ) > 0 ? 2 : 1;
		}
	}
	else if( distance[ 0 ] < distance[ 1 ] )
	{
		if( distance[ 0 ] > distance[ 2 ] )
		{
			return 2;
		}
		else if( distance[ 0 ] < distance[ 2 ] )
		{
			return 0;
		}
		else return strcmp( string_list[ leader[ 0 ] ], string_list[ leader[ 2 ] ] ) > 0 ? 2 : 0;
	}
	else if( distance[ 1 ] > distance[ 2 ] )
	{
		return 2;
	}
	else if( distance[ 1 ] < distance[ 2 ] )
	{
		return strcmp( string_list[ leader[ 0 ] ], string_list[ leader[ 1 ] ] ) > 0 ? 1 : 0;
	}
	else
	{
		int cmp01 = strcmp( string_list[ leader[ 0 ] ], string_list[ leader[ 1 ] ] );
		int cmp12 = strcmp( string_list[ leader[ 1 ] ], string_list[ leader[ 2 ] ] );
		int cmp20 = strcmp( string_list[ leader[ 2 ] ], string_list[ leader[ 0 ] ] );

		if( cmp01 > 0 )
		{
			if( cmp12 > 0 )
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		else if( cmp12 < 0 )
		{
			return 0;
		}
		else if( cmp20 < 0 )
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}

int main( void )
{
	int string_count;
	int string_length;
	int round_count;
	scanf( "%d%d%d", &string_count, &string_length, &round_count );

	char string_list[ 50 ][ 11 ] = { { 0 } };
	int group[ 50 ] = { 0, 1, 2 };
	for( int i = 0; i < string_count; ++i )
	{
		scanf( "%s", string_list[ i ] );
	}

	int leader[ 3 ] = { 0, 1, 2 };
	char mean[ 3 ][ 11 ] = { { 0 } };

	for( int i = 0; i < round_count; ++i )
	{
		const char *leader_string[ 3 ] = { string_list[ leader[ 0 ] ], string_list[ leader[ 1 ] ], string_list[ leader[ 2 ] ] };
#ifdef DEBUG
		printf( "leader_string : { %s, %s, %s }\n", leader_string[ 0 ], leader_string[ 1 ], leader_string[ 2 ] );
#endif
		int distance[ 50 ][ 3 ];
		int group_count[ 3 ] = { 1, 1, 1 };
		int sum[ 3 ][ 11 ] = { { 0 } };

		for( int j = 0; j < string_count; ++j )
		{
			Distance( leader_string, string_list[ j ], string_length, distance[ j ] );
#ifdef DEBUG
			printf( "\t%s [ %2d, %2d, %2d ]\n", string_list[ j ], distance[ j ][ 0 ], distance[ j ][ 1 ], distance[ j ][ 2 ] );
#endif
			if( j != leader[ 0 ] && j != leader[ 1 ] && j != leader[ 2 ] )
			{
				group[ j ] = Group( string_list, leader, distance[ j ] );
				++group_count[ group[ j ] ];
#ifdef DEBUG
				printf( "\t\t%s : %d, count = %d\n", string_list[ j ], group[ j ], group_count[ group[ j ] ] );
#endif
			}
			
			for( int k = 0; k < string_length; ++k )
			{
				sum[ group[ j ] ][ k ] += string_list[ j ][ k ];
			}
		}

		for( int j = 0; j < 3; ++j )
		{
			for( int k = 0; k < string_length; ++k )
			{
				mean[ j ][ k ] = sum[ j ][ k ] / group_count[ j ];
			}
#ifdef DEBUG
			printf( "\tmean %d : %s\n", j, mean[ j ] );
#endif
		}

		int leader_distance[ 3 ] = { String_Distance( leader_string[ 0 ], mean[ 0 ], string_length ), String_Distance( leader_string[ 1 ], mean[ 1 ], string_length ), String_Distance( leader_string[ 2 ], mean[ 2 ], string_length ) };
		for( int j = 0; j < string_count; ++j )
		{
			int distance_temp = String_Distance( string_list[ j ], mean[ group[ j ] ], string_length );
#ifdef DEBUG
			printf( "mean[ %d ] to %s : %d\n", group[ j ], string_list[ j ], distance_temp );
#endif
			if( distance_temp < leader_distance[ group[ j ] ] )
			{
				leader[ group[ j ] ] = j;
				leader_distance[ group[ j ] ] = distance_temp;
			}
			else if( distance_temp == leader_distance[ group[ j ] ] && strcmp( string_list[ leader[ group[ j ] ] ], string_list[ j ] ) > 0 )
			{
				leader[ group[ j ] ] = j;
				leader_distance[ group[ j ] ] = distance_temp;
			}
		}
	}

	int cmp01 = strncmp( string_list[ leader[ 0 ] ], string_list[ leader[ 1 ] ], string_length );
	int cmp12 = strncmp( string_list[ leader[ 1 ] ], string_list[ leader[ 2 ] ], string_length );
	int cmp20 = strncmp( string_list[ leader[ 2 ] ], string_list[ leader[ 0 ] ], string_length );

	if( cmp01 > 0 )
	{
		if( cmp12 > 0 )
		{
			puts( string_list[ leader[ 2 ] ] );
			puts( string_list[ leader[ 1 ] ] );
			puts( string_list[ leader[ 0 ] ] );
		}
		else if( cmp20 > 0 )
		{
			puts( string_list[ leader[ 1 ] ] );
			puts( string_list[ leader[ 0 ] ] );
			puts( string_list[ leader[ 2 ] ] );
		}
		else
		{
			puts( string_list[ leader[ 1 ] ] );
			puts( string_list[ leader[ 2 ] ] );
			puts( string_list[ leader[ 0 ] ] );
		}
	}
	else if( cmp12 < 0 )
	{
		puts( string_list[ leader[ 0 ] ] );
		puts( string_list[ leader[ 1 ] ] );
		puts( string_list[ leader[ 2 ] ] );
	}
	else if( cmp20 < 0 )
	{
		puts( string_list[ leader[ 2 ] ] );
		puts( string_list[ leader[ 0 ] ] );
		puts( string_list[ leader[ 1 ] ] );
	}
	else
	{
		puts( string_list[ leader[ 0 ] ] );
		puts( string_list[ leader[ 2 ] ] );
		puts( string_list[ leader[ 1 ] ] );
	}

	return 0;
}
