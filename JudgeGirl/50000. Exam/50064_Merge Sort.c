#include <stdio.h>

int main( void )
{
	int file_count;
	scanf( "%d", &file_count );

	FILE *file_list[ 16 ];
	int number_list[ 16 ];
	for( int i = 0; i < file_count; ++i )
	{
		char file_name[ 16 ];
		scanf( "%s", file_name );

		file_list[ i ] = fopen( file_name, "rb" );

		fread( &number_list[ i ], sizeof( int ), 1, file_list[ i ] );
	}

	int minimal = 0;
	number_list[ 15 ] = 0x7FFFFFFF;
	while( minimal != 15 )
	{
		minimal = 15;
		for( int i = 0; i < file_count; ++i )
		{
			if( number_list[ i ] < number_list[ minimal ] && feof( file_list[ i ] ) == 0 )
			{
				minimal = i;
			}
		}

		if( minimal != 15 )
		{
			printf( "%d\n", number_list[ minimal ] );

			fread( &number_list[ minimal ], sizeof( int ), 1, file_list[ minimal ] );
		}
	}
}

