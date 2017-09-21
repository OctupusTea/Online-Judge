#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
int main( void)
{
    char data[2][128] = {0};
    //char ans[128] = {0};
 
    scanf( "%s", data[0] );
 
    while( ~scanf( "%s", data[1] ) )
    {
        int len[2] = { strlen( data[0] ), strlen( data[1] ) };
        int shorter = ( len[0] > len[1] ? 1 : 0 );
        int length = 0;
 
        #ifdef DEBUG
            printf( "\nlen[0] = %d, len[1] = %d, shorter = %d\n", len[0], len[1], shorter );
        #endif
 
        for( int i = 1; i <= len[ shorter ]; i++)
        {
            int j = 0;
            for( j = 0; j < i && data[0][ len[0]-i+j ] == data[1][ j ]; j++ )
            {
                ;
            }
 
            #ifdef DEBUG
                printf( "i = %d, j = %d\n", i, j);
            #endif
 
            if( j == i )
            {
                length = i;
            }
        }
 
        //strcpy( ans, data[0] );
 
        for( int i = length; i < len[1]; i++)
        {
            data[0][ len[0] + i - length ] = data[1][i];
        }
 
        #ifdef DEBUG
            printf( "%s\n", data[0] );
        #endif
 
        //strcpy( data[0], ans );
    }
 
    printf( "%s\n", data[0] );
 
    return 0;
}