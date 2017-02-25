#include <stdio.h>
#include "prepare_array.h"
 
//#define DEBUG
 
void prepare_array(int buffer[], int *array[], int row, int column[])
{
    int p = 0;
 
    #ifdef DEBUG
        printf( "buffer = 0x%X\n", buffer );
    #endif
 
    for( int i = 0; i < row; i++)
    {
        array[ i ] = ( buffer + p );
        #ifdef DEBUG
            printf( "array[ %d ] = 0x%X\n", i, array[ i ] );
        #endif
        p += column[ i ];
    }
}