#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Replace( char *data_string, int data_length, char from, char to )
{
	for( int i = 0; i < data_length; ++i )
	{
		if( data_string[ i ] == from )
		{
			data_string[ i ] = to;
		}
	}
}

void Remove( char **data_string, int *data_length, int *offset, char remove )
{
	char *new_string = ( char* )malloc( 220000 * sizeof( char ) );
	int new_offset = 110000;
	int new_length = 0;
	new_string += new_offset;

	char *old_string = *data_string;
	int length = *data_length;
	for( int i = 0; i < length; ++i )
	{
		if( old_string[ i ] != remove )
		{
			new_string[ new_length ] = old_string[ i ];
			new_length++;
		}
	}
	new_string[ new_length ] = '\0';

	old_string -= *offset;
	free( old_string );

	*data_string = new_string;
	*data_length = new_length;
	*offset = new_offset;
}

void Add_Head( char **data_string, int *data_length, int *offset, char add )
{
	( *data_string )--;
	( *offset )--;
	( *data_length )++;
	*data_string[ 0 ] = add;
}

void Add_Tail( char *data_string, int *data_length, char add )
{
	data_string[ *data_length ] = add;
	data_string[ *data_length + 1 ] = '\0';
	( *data_length )++;
}

int main( void )
{
	char *data_string = ( char* )malloc( 220000 * sizeof( char ) );
	int offset = 110000;
	data_string += offset;

	scanf( "%s", data_string );
	int data_length = strlen( data_string );
	
	char command[ 256 ] = { 0 };
	scanf( "%s", command );

	while( strcmp( command, "end" ) != 0 )
	{
		if( strcmp( command, "replace" ) == 0 )
		{
			char from[ 16 ] = { 0 }, to[ 16 ] = { 0 };
			scanf( "%s %s", from, to );

			Replace( data_string, data_length, from[ 0 ], to[ 0 ] );
		}
		else if( strcmp( command, "remove" ) == 0 )
		{
			char remove[ 16 ] = { 0 };
			scanf( "%s", remove );

			Remove( &data_string, &data_length, &offset, remove[ 0 ] );
		}
		else if( strcmp( command, "addhead" ) == 0 )
		{
			char add[ 16 ] = { 0 };
			scanf( "%s", add );

			Add_Head( &data_string, &data_length, &offset, add[ 0 ] );
		}
		else if( strcmp( command, "addtail" ) == 0 )
		{
			char add[ 16 ] = { 0 };
			scanf( "%s", add );

			Add_Tail( data_string, &data_length, add[ 0 ] );
		}
		else
		{
			printf( "invalid command %s\n", command );
			return 0;
		}

		scanf( "%s", command );
	}

	printf( "%s\n", data_string );
	
	data_string -= offset;
	free( data_string );

	return 0;
}
