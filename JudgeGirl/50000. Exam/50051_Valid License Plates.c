#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Valid( char license_plate[ 8 ] )
{
	int character_count[ 128 ] = { 0 };
	int last_4 = 0;
	int sum = 0;
	int exist_digit = 0;

	for( int i = 0; i < 7; ++i )
	{
		if( isalnum( license_plate[ i ] ) == 0 && license_plate[ i ] != '-' )
		{
			return 0;
		}
		else if( isdigit( license_plate[ i ] ) )
		{
			sum += license_plate[ i ] - '0';
			exist_digit = 1;
		}

		++character_count[ ( int )license_plate[ i ] ];
		if( character_count[ ( int )license_plate[ i ] ] > 2 )
		{
			return 0;
		}
		
		if( license_plate[ i ] == '-' )
		{
			if( i != 2 && i != 3 )
			{
				return 0;
			}
			else if( character_count[ ( int )'-' ] > 1 )
			{
				return 0;
			}

			last_4 = 0;
		}
		else if( license_plate[ i ] == '4' )
		{
			if( last_4 == 0 )
			{
				last_4 = 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			last_4 = 0;
		}
	}

	if( sum % 7 == 0 || character_count[ ( int )'-' ] == 0 || exist_digit == 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Compare_License( const void *a, const void *b )
{
	const char *x = ( char* )a;
	const char *y = ( char* )b;
	
	if( ( x[ 2 ] == '-' && y[ 2 ] == '-' ) || ( x[ 3 ] == '-' && y[ 3 ] == '-' ) )
	{
		for( int i = 0; i < 7; ++i )
		{
			if( x[ i ] != y[ i ] )
			{
				return x[ i ] - y[ i ];
			}
		}

		return -1;
	}
	else if( x[ 2 ] == '-' )
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int main( void )
{
	int  license_plate_count;
	char license_plate_list[ 32 ][ 8 ] = { { 0 } };
	
	scanf( "%d", &license_plate_count );

	for( int i = 0; i < license_plate_count; i++ )
	{
		scanf( "%s", license_plate_list[ i ] );

		if( Valid( license_plate_list[ i ] ) == 0 )
		{
			--i;
			--license_plate_count;
		}
	}

	qsort( license_plate_list, license_plate_count, 8, Compare_License );
	
	for( int i = 0; i < license_plate_count; ++i )
	{
		puts( license_plate_list[ i ] );
	}

	return 0;
}
