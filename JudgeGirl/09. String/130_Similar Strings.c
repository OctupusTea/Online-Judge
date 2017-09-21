#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
int main( void)
{
    int n = 0;
 
    scanf( "%d", &n );
 
    for( int i = 0; i < n; i++ )
    {
        char data[2][ 80 ] = {0};
        scanf( "%s", data[0] );
        scanf( "%s", data[1] );
 
        #ifdef DEBUG
            printf( "%s\n%s\n\n", data[0], data[1] );
        #endif
 
        int len[2] = { strlen( data[0] ), strlen( data[1] ) };
 
        if( len[0] == len[1] )
        {
            int diff[3] = {0}, count = 0;
 
            for( int i = 0; i < len[0] && count <= 2; i++)
            {
                if( data[0][ i ] != data[1][ i ] )
                {
                    diff[ count ] = i;
                    count++;
                }
            }
 
            if( count == 0 || ( count == 2 && diff[1] - diff[0] == 1 && data[0][ diff[0] ] == data[1][ diff[1] ] && data[1][ diff[0] ] == data[0][ diff[1] ] ) )
            {
                printf( "yes\n" );
            }
            else
            {
                printf( "no\n" );
            }
        }
        else if( len[0] - len[1] == 1 || len[0] - len[1] == -1 )
        {
            int shorter = 0, count = 0;
 
            if( len[0] > len[1] )
            {
                shorter = 1;
            }
 
            for( int i = 0; i < len[ shorter ] && count <= 1; i++ )
            {
                if( data[ shorter ][ i ] != data[ 1 - shorter ][ i+count ] )
                {
                    if( data[ shorter ][ i ] == data[ 1 - shorter ][ i+1 ] )
                    {
                        count++;
                    }
                    else
                    {
                        count += 2;
                    }
                }
            }
 
            if( count == 0 || count == 1 )
            {
                printf( "yes\n" );
            }
            else
            {
                printf( "no\n" );
            }
        }
        else
        {
            printf( "no\n" );
        }
    } 
 
    return 0;
}