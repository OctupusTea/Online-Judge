#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
//#define DEBUG
 
char food[ 100 ][ 70 ] = {0};
int count[ 100 ] = {0};
char ingredient[ 100 ][ 10 ][ 70 ] = {0};
char *ptr_ingredient[ 100 ][ 10 ] = {0};
 
int main( void)
{
    int n = 0;
 
    scanf( "%d", &n );
 
    for( int i = 0; i < n; i++ )
    {
        scanf( "%s%d", food[ i ], &count[ i ] );
 
        for( int j = 0; j < count[ i ]; j++ )
        {
            scanf( "%s", ingredient[ i ][ j ] );
 
            ptr_ingredient[ i ][ j ] = &( ingredient[ i ][ j ][ 0 ] );
        }
 
        for( int j = 0; j < count[ i ]; j++ )
        {
            for( int k = 0; k < j; k++ )
            {
                if( strcmp( ptr_ingredient[ i ][ j ], ptr_ingredient[ i ][ k ] ) < 0 )
                {
                    char *temp = 0;
                    temp = ptr_ingredient[ i ][ j ];
                    ptr_ingredient[ i ][ j ] = ptr_ingredient[ i ][ k ];
                    ptr_ingredient[ i ][ k ] = temp;
                }
            }
        }
    }
    #ifdef DEBUG
        printf( "n = %d\n", n );
 
        for( int i = 0; i < n; i++ )
        {
            printf( "food[ %d ] = %s, count[ %d ] = %d\n", i, food[ i ], i, count[ i ] ); 
 
            for( int j = 0; j < count[ i ]; j++ )
            {
                printf( "ingredient[ %d ][ %d ] = %s\n", i, j, ptr_ingredient[ i ][ j ] );
            }
        }
    #endif
 
    int m = 0;
    scanf( "%d", &m );
 
    for( int i = 0; i < m; i++ )
    {
        char temp[ 2 ][ 70 ] = {0};
        scanf( "%s %s", temp[ 0 ], temp[ 1 ] );
 
        int index[ 2 ] = {0};
 
        for( int j = 0; j < n; j++ )
        {
            if( strcmp( temp[ 0 ], food[ j ] ) == 0 )
            {
                index[ 0 ] = j;
            }
            if( strcmp( temp[ 1 ], food[ j ] ) == 0 )
            {
                index[ 1 ] = j;
            }
        }
 
        #ifdef DEBUG
            printf( "\n\nfood to find =\n%d : %s\n%d : %s\n", index[ 0 ], food[ index[ 0 ] ], index[ 1 ], food[ index[ 1 ] ] );
        #endif
 
        int ptr[ 2 ] = {0}, found = 0;
 
        while( ptr[ 0 ] < count[ index[ 0 ] ] && ptr[ 1 ] < count[ index[ 1 ] ] )
        {
            if( strcmp( ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ], ptr_ingredient[ index[ 1 ] ][ ptr[ 1 ] ] ) > 0 )
            {
                #ifdef DEBUG
                    printf( "\n\t\t%s > %s", ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ], ptr_ingredient[ index[ 1 ] ][ ptr[ 1 ] ] );
                #endif
 
                ptr[ 1 ]++;
            }
            else if( strcmp( ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ], ptr_ingredient[ index[ 1 ] ][ ptr[ 1 ] ] ) < 0 )
            {
                #ifdef DEBUG
                    printf( "\n\t\t%s < %s", ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ], ptr_ingredient[ index[ 1 ] ][ ptr[ 1 ] ] );
                #endif
 
                ptr[ 0 ]++;
            }
            else
            {
                #ifdef DEBUG
                    printf( "\n\t\t%s == %s\n", ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ], ptr_ingredient[ index[ 1 ] ][ ptr[ 1 ] ] );
                #endif
 
                if( !found )
                {
                    printf( "%s", ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ] );
                    found = 1;
                }
                else
                {
                    printf( " %s", ptr_ingredient[ index[ 0 ] ][ ptr[ 0 ] ] );
                }
 
                ptr[ 0 ]++;
                ptr[ 1 ]++;
            }
        }
 
        if( found )
        {
            printf( "\n" );
        }
        else
        {
            printf( "nothing\n" );
        }
    }
 
    return 0;
}