#include <stdio.h>
#include <stdlib.h>
 
//#define DEBUG
 
int main( void)
{
    unsigned data = 0;
 
    while( ~scanf( "%d", &data ) )
    {
        int count = 0, max = 0;
 
        for( unsigned mask = 1; mask <= data && mask < ( 1 << sizeof( int ) * 8 - 1 ); mask <<= 1 )
        {
            #ifdef DEBUG
                printf( "%d\n", mask );
            #endif
 
            if( data & mask )
            {
                count++;
 
                if( count > max )
                {
                    max = count;
                }
            }
            else
            {
                count = 0;
            }
        }
 
        printf( "%d\n", max );
    }
 
    return 0;
}