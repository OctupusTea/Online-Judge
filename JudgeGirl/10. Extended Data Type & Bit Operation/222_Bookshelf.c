#include <stdio.h>
#include <stdlib.h>
 
//#define DEBUG
int hasEOF = 0;
 
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
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
 
int main( void)
{
    unsigned long long bookshelf = 0;
    int book_temp = 0;
 
    while( ReadInt( &book_temp ) )
    {
        unsigned long long mask = 0x00000000000000FF;
        unsigned long long book_read = book_temp;
        int onShelf = 8;
 
        #ifdef DEBUG
            printf( "book_temp = %2hhX, book_read = %16llX, bookshelf = %16llX, mask = %16llX\n", book_temp, book_read, bookshelf, mask );
        #endif
 
        for( int i = 0; i < 8 && onShelf == 8; i++, mask <<= 8, book_read <<= 8 )
        {
            #ifdef DEBUG
                    printf( "i = %d, book_temp = %2hhX, book_read = %16llX, bookshelf = %16llX, mask = %16llX\n", i, book_temp, book_read, bookshelf, mask );
            #endif
 
            if( ( bookshelf & mask ) == book_read )
            {
                onShelf = i;
 
                #ifdef DEBUG
                    printf( "book_temp = %2hhX, book_read = %16llX, bookshelf = %16llX, mask = %16llX\n", book_temp, book_read, bookshelf, mask );
                #endif
 
                unsigned long long keep = 0xFFFFFFFFFFFFFF00 << ( onShelf * 8 );
                unsigned long long move = ( bookshelf & ( (~keep) >> 8 ) ) << 8;
 
                #ifdef DEBUG
                    printf( "onShelf = %d, keep = %16llX, move = %16llX\n", onShelf, keep, move );
                #endif
 
                bookshelf &= keep;
                bookshelf |= move;
            }
        }
 
        if( onShelf == 8 )
        {
            bookshelf <<= 8;
        }
 
        bookshelf |= book_temp;
 
        #ifdef DEBUG
            printf( "bookshelf = %16llX\n", bookshelf );
        #endif
    }
 
    char *ptr = &bookshelf;
    for( int i = 7; i > 0; i-- )
    {
        printf( "%hhu ", *( ptr + i ) );
    }
    printf( "%hhu\n", *ptr );
 
    return 0;
}