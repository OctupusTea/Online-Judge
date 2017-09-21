#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
int main( void)
{
    char data[128] = {0};
    char abbr[128] = {0};
 
 
    while( ~scanf( "%s", data ) )
    {
        int len = strlen( data );
 
        if( data[ len - 1 ] == '.' )
        {
            data[ len - 1 ] = '\0';
 
            #ifdef DEBUG
                printf( "%s\n", data );
            #endif
 
            if( strcmp( data, "of" ) == 0 || strcmp( data, "and" ) == 0 || strcmp( data, "the" ) == 0 || strcmp( data, "at" ) == 0 )
            {
                printf( "\n" );
            }
            else
            {
                printf( "%c\n", toupper( data[0] ) );
            }
        }
        else if( strcmp( data, "of" ) && strcmp( data, "and" ) && strcmp( data, "the" ) && strcmp( data, "at" ) )
        {
            printf( "%c", toupper( data[0] ) );
        }
    }
 
    return 0;
}