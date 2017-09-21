#include <stdio.h>
#include <stdlib.h>
 
//#define DEBUG
 
int main( void)
{
    unsigned long long data = 0, one = 1;
 
    while( ~scanf( "%llu", &data ) )
    {
        int count = 0;
 
        for( unsigned long long mask = 1; mask <= data && mask < ( one << ( sizeof( long long ) * 8 - 1 ) ); mask <<= 1 )
        {
            #ifdef DEBUG
                printf( "%llu\n", mask );
            #endif
 
            if( data & mask )
            {
                count++;
            }
        }
 
        printf( "%d\n", count );
    }
 
    return 0;
}