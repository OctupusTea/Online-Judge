#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iso646.h>

//#define DEBUG
int hasEOF = 0;
 
int readchar() {
    static int N = 65536;
    static char buf[65536];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
 
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

union Bookshelf
{
	uint64_t bookshelf;
	uint8_t book[ 8 ];
};

int main( void )
{
    union Bookshelf Bookshelf = { (uint64_t)0 };
    int book_temp = 0;

	uint64_t *bookshelf = &( Bookshelf.bookshelf );
	uint8_t *book = Bookshelf.book;

    while( ReadInt( &book_temp ) )
    {
		int found = -1;
		for( int i = 0; i < 8 and ( found == -1 ); ++i )
		{
			if( book[ i ] == ( uint8_t )book_temp )
			{
				found = i;
			}
		}

		if( found == -1 )
		{
			*bookshelf >>= 8;
			book[ 7 ] = book_temp;
		}
		else
		{
			for( int i = found; i < 7; i++ )
			{
				book[ i ] = book[ i + 1 ];
			}
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
