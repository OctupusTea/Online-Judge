#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
char data[ 1000000 ] = {0};
 
int main( void)
{
    fgets( data, 1000000, stdin );
 
    while( strlen( data ) )
    {
        int len = strlen( data );
        int left = 0, right = len;
 
        #ifdef DEBUG
            printf( "%d\n", len );
        #endif
 
        for( int i = 0; i < len && isspace( data[ i ] ); i++ )
        {
            left = i + 1;
            #ifdef DEBUG
                printf( "left = %d\n", left );
            #endif
        }
 
        for( int i = len - 1; i >= 0 && isspace( data[ i ] ); i-- )
        {
            right = i;
            #ifdef DEBUG
                printf( "right = %d\n", right );
            #endif
        }
 
        for( int i = left; i < right; i++)
        {
            printf( "%c", data[ i ] );
        }
        printf( "\n" );
 
        data[0] = '\0';
 
        fgets( data, 1000000, stdin );
    }
 
    return 0;
}