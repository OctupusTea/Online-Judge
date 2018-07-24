#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iso646.h>
#include <unistd.h>

//#define DEBUG

#define BUFFER_SIZE 65536

int eof_reached = 0;
 
int readchar() {
    static int N = 65536;
    static char buf[65536];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + read( STDIN_FILENO, buf, N )) == buf) {
            eof_reached = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
 
int Get_Book( int *book )
{
	int temp = readchar( );
	
	while( temp < '0' or temp > '9' )
	{
		if( eof_reached )
		{
			return 0;
		}

		temp = readchar( );	
	}

	int ret = 0;
	while( temp >= '0' and temp <= '9' )
	{
		ret *= 10;
		ret += temp - '0';

		temp = readchar( );
	}

	*book = ret;
	return 1;
}

union Bookshelf
{
	uint64_t bookshelf;
	uint8_t book[ 8 ];
};

int main( void )
{
    union Bookshelf Bookshelf;
	Bookshelf.bookshelf = 0;
    int book_temp = 0;

	uint8_t *book = Bookshelf.book;

    while( Get_Book( &book_temp ) )
    {
		int found = -1;
		for( int i = 0; i < 8 and ( found == -1 ); ++i )
		{
			if( book[ i ] == ( uint8_t )book_temp )
			{
				found = i;
			}
		}

		if( found ^ -1 )
		{
			for( int i = found; i < 7; i++ )
			{
				book[ i ] = book[ i + 1 ];
			}
			book[ 7 ] = book_temp;
		}
		else
		{
			Bookshelf.bookshelf >>= 8;
			book[ 7 ] = book_temp;
		}
    }

	for( int i = 0; i < 7; i++ )
	{
		printf( "%hhu ", book[ i ] );
	}
	printf( "%hhu\n", book[ 7 ] );
 
	return 0;
}
