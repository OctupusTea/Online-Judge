#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
char data[ 1048576 ] = {0};
 
int main( void)
{
    char instruction[3][8] = {0};
    int len = 0;
 
    while( ~scanf( "%s", instruction[0] ) )
    {
        #ifdef DEBUG
            printf( "%s\n", instruction[0] );
        #endif
 
        if( strcmp( instruction[0] , "insert" ) == 0 )
        {
            scanf( "%s %s", instruction[1], instruction[2] );
 
            #ifdef DEBUG
                printf( "%s\n%s\n", instruction[1], instruction[2] );
            #endif
 
            int start = 0;
 
            if( strcmp( instruction[1], "right" ) == 0 )
            {
                start = len;
            }
            else if( strcmp( instruction[1], "left" ) == 0 )
            {
                start = 0;
            }
            else
            {
                start = atoi( instruction[1] ) - 1;
            }
 
            for( int i = len ; i > start; i-- )
            {
                data[ i ] = data[ i-1 ];
            }
 
            len++;
            data[ start ] = instruction[2][0];
        }
        else if( strcmp( instruction[0], "delete" ) == 0 )
        {
            scanf( "%s", instruction[1] );
 
            #ifdef DEBUG
                printf( "%s\n", instruction[1] );
            #endif
 
            int start = 0;
 
            if( strcmp( instruction[1], "right" ) == 0 )
            {
                start = len - 1;
            }
            else if( strcmp( instruction[1], "left" ) == 0 )
            {
                start = 0;
            }
            else
            {
                start = atoi( instruction[1] ) - 1;
            }
 
            for( int i = start; i < len; i++ )
            {
                data[ i ] = data[ i+1 ];
            }
 
            len--;
        }
 
        #ifdef DEBUG
            printf( "data = %s\n\n", data );
        #endif
    }
 
    #ifdef DEBUG_2
        printf( "%s\n", data );
    #endif
 
    int count = 1, max = 0;
 
    for( int i = 0; i < len; i++)
    {
        if( data[ i ] == data[ i+1 ] )
        {
            count++;
        }
        else
        {
            if( count > max )
            {
                max = count;
            }
            count = 1;
        }
    }
 
    count = 1;
 
    for( int i = 0; i < len; i++ )
    {
        if( data[ i ] == data[ i+1 ] )
        {
            count++;
        }
        else
        {
            if( count == max )
            {
                printf( "%c ", data[ i ] );
            }
            count = 1;
        }
    }
 
    printf( "%d\n", max );
 
    return 0;
}