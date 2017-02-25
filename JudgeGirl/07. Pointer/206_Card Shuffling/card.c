#include "card.h"
#include <stdlib.h>
#include <stdio.h>
//#define DEBUG
 
void shuffle( int *deck[] )
{
    int n = 0, i = 0;
    int temp[2][5000] = {0};
 
    if( *deck == NULL )
    {
        return;
    }
 
    for( i = 0; *( deck+i ) != NULL; i++)
    {
        ;
    }
    n = i;
    #ifdef DEBUG
        printf( "%d\n", n);
    #endif
 
    for( i = 0; i < n-n/2; i++)
    {
        temp[0][i] = **( deck+i );
        #ifdef DEBUG
            printf( "%d\n", temp[0][i] );
        #endif
    }
 
    for( i = n-n/2; i < n; i++)
    {
        temp[1][i-n+n/2] = **( deck+i );
        #ifdef DEBUG
            printf( "%d\n", temp[1][i-n+n/2] );
        #endif
    }
 
    for( i = 0; i < n-n/2-1; i++)
    {
        **( deck + 2*i ) = temp[0][i];
        #ifdef DEBUG
            printf( "%d, %d\n", 2*i, **( deck + 2*i ) );
        #endif
        **( deck + 2*i + 1 ) = temp[1][i];
        #ifdef DEBUG
            printf( "%d, %d\n", 2*i+1, **( deck + 2*i + 1 ) );
        #endif
 
    }
 
    #ifdef DEBUG
        printf( "%d, ", 2*i );
    #endif
    **( deck + 2*i ) = temp[0][i];
    #ifdef DEBUG
        printf( "%d\n", **( deck + 2*i ) );
    #endif
    if( n % 2 == 0 )
    {
        **( deck+2*i+1 ) = temp[1][i];
        #ifdef DEBUG
            printf("%d\n",2*i+1);
        #endif
    }
 
}
 
void print( int *deck[] )
{
    int i = 0;
 
    if( *deck == NULL )
    {
        return;
    }
 
    for( i = 0; *( deck + i ) != NULL; i++)
    {
        printf( "%d ", **( deck+i ) );
    }
}