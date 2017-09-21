#include <stdio.h>
#include <string.h>
 
//#define DEBUG
 
int main( void)
{
    int m = 0, n = 0;
    char temp[ 128 ][ 257 ] = {0};
    char next[ 257 ] = {0};
 
    scanf( "%d%s", &m, next );
 
    while( next[ 0 ] != '\0' )
    {
        int len = strlen( next ), count = 1;
 
        strcpy( temp[ 0 ], next );
 
        for( count = 1; len <= m && temp[ count - 1 ][ 0 ] != '\0'; count++ )
        {
            if( ~scanf( "%s", temp[ count ] ) )
            {
                len += strlen( temp[ count ] ) + 1;
            }
            else
            {
                temp[ count ][ 0 ] = '\0';
                next[ 0 ] = '\0';
            }
 
            #ifdef DEBUG
                printf( "count = %d, temp = %s, len = %d\n", count, temp[ count ], len );
            #endif
        }
 
        count--;
        len -= next[ 0 ] != '\0' ? strlen( temp[ count ] ) + 1 : strlen( temp[ count ] );
        strcpy( next, temp[ count ] );
        count--;
 
        #ifdef DEBUG
            printf( "count = %d, temp = %s, m - len = %d\n", count, temp[ count ], m - len );
        #endif
 
        if( count == 0 )
        {
            printf( "%s", temp[ 0 ] );
 
            for( int i = 0; i < m - len; i++ )
            {
                printf( " " );
            }
 
            printf( "\n" );
        }
        else
        {
            #ifdef DEBUG
                printf( "remainder = %d, space = %d\n", ( m - len ) % count, ( m - len ) / count );
            #endif
 
            for( int i = 0; i < ( m - len ) % count; i++ )
            {
                printf( "%s ", temp[ i ] );
 
                for( int j = 0; j <= ( m - len ) / count; j++ )
                {
                    printf( " " );
                }
            }
 
            #ifdef DEBUG
                printf( "_switch_" );
            #endif
 
            for( int i = ( m - len ) % count; i < count; i++ )
            {
                printf( "%s ", temp[ i ] );
 
                for( int j = 0; j < ( m - len ) / count; j++ )
                {
                    printf( " " );
                }
            }
 
            printf( "%s\n", temp[ count ] );
        }
    }
 
    return 0;
}