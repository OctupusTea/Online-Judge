#include <stdio.h>
#include <stdlib.h>
 
//#define DEBUG
 
int main( void)
{
    unsigned data[ 1024 ] = {0};
    unsigned width = 0, height = 0;
    char pattern[ 2 ] = {0};
 
    scanf( "%u %u\n", &width, &height );
    scanf( "%c %c\n", &pattern[ 1 ], &pattern[ 0 ] );
 
    for( unsigned i = 0; i < ( width * height + 31 ) / 32; i++ )
    {
        scanf( "%u", &data[ i ] );
    }
 
    unsigned count = 0;
 
    for( unsigned i = 0; i < ( width * height + 31 ) / 32; i++ )
    {
        for( unsigned mask = 1 << 31; mask >= 1 && count < width * height ; mask >>= 1 )
        {
            #ifdef DEBUG
                printf( "\n%d, %u, %u", i, mask, mask & data[ i ] );
            #endif
 
            if( mask & data[ i ] )
            {
                printf( "%c", pattern[ 1 ] );
            }
            else
            {
                printf( "%c", pattern[ 0 ] );
            }
 
            count++;
 
            #ifndef DEBUG
                if( count % width == 0 )
                {
                    printf( "\n" );
                }
            #endif
        }
    }
 
    return 0;
}