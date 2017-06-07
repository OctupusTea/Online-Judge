#include <stdio.h>
#include <string.h>
 
int main( void)
{
    char digit[ 1000 ] = {0};
 
    scanf( "%s", &digit );
 
    while( digit[ 0 ] != '-' )
    {
        int len = strlen( digit );
        int count[ 3 ] = {0};
 
        for( int i = 0; i < len; i++)
        {
            count[ 0 ] += ( digit[ i ] - '0' );
            if( i % 2 == 0 )
            {
                count[ 1 ] += ( digit[ i ] - '0' );
            }
            else
            {
                count[ 2 ] += ( digit[ i ] - '0' );
            }
        }
 
        if( digit[ len-1 ] % 2 == 0 )
        {
            printf( "yes " );
        }
        else
        {
            printf( "no " );
        }
 
        if( count[ 0 ] % 3 == 0 )
        {
            printf( "yes " );
        }
        else
        {
            printf( "no " );
        }
 
        if( ( digit[ len-1 ] - '0' ) % 5 == 0 )
        {
            printf( "yes " );
        }
        else
        {
            printf( "no " );
        }
 
        if( abs( count[ 1 ] - count [ 2 ] ) % 11 == 0 )
        {
            printf( "yes\n" );
        }
        else
        {
            printf( "no\n" );
        }
 
        scanf( "%s", &digit );
    }
 
    return 0;
}