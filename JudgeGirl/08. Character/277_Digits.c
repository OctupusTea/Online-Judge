#include <stdio.h>
#include <string.h>
 
//#define DEBUG
 
int main( void)
{
    char data[ 10 ] = {0}, output[ 15 ][ 100 ] = {0};
    int height = 0, width = 0;
    int digits[10][7] = { { 1, 1, 1, 0, 1, 1, 1 } , 
                          { 0, 0, 0, 0, 0, 1, 1 } , 
                          { 0, 1, 1, 1, 1, 1, 0 } , 
                          { 0, 0, 1, 1, 1, 1, 1 } , 
                          { 1, 0, 0, 1, 0, 1, 1 } , 
                          { 1, 0, 1, 1, 1, 0, 1 } ,
                          { 1, 1, 1, 1, 1, 0, 1 } , 
                          { 1, 0, 1, 0, 0, 1, 1 } , 
                          { 1, 1, 1, 1, 1, 1, 1 } , 
                          { 1, 0, 1, 1, 0, 1, 1 } };
 
    while( ~scanf( "%s%d%d", data, &width, &height ) )
    {
        digits[0][0] = 1;
        int len = strlen( data );
 
        for( int i = 0; i < height; i++)
        {
            for( int j = 0; j < len*width; j++)
            {
                output[ i ][ j ] = ' ';
            }
        }
 
        for( int i = 0; i < len; i++)
        {
            #ifdef DEBUG
                for( int j = 0; j < 7; j++ )
                {
                    printf( "%d ", digits[ data[i] - '0' ][ j ] );
                }
                printf( "\n" );
            #endif
 
            if( digits[ data[i] - '0' ][ 0 ] == 1 )
            {
                for( int j = 1; j < height/2; j++)
                {
                    output[ j ][ i*width ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 1 ] == 1 )
            {
                for( int j = height/2+1 ; j < height-1; j++)
                {
                    output[ j ][ i*width ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 2 ] == 1 )
            {
                for( int j = 1; j < width - 2; j++)
                {
                    output[ 0 ][ i*width + j ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 3 ] == 1 )
            {
                for( int j = 1; j < width - 2; j++)
                {
                    output[ height/2 ][ i*width + j ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 4 ] == 1 )
            {
                for( int j = 1; j < width - 2; j++)
                {
                    output[ height-1 ][ i*width + j ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 5 ] == 1 )
            {
                for( int j = 1; j < height/2; j++)
                {
                    output[ j ][ (i+1)*width-2 ] = data[i];
                }
            }
 
            if( digits[ data[i] - '0' ][ 6 ] == 1 )
            {
                for( int j = height/2+1; j < height-1; j++)
                {
                    output[ j ][ (i+1)*width-2 ] = data[i];
                }
            }
        }
        for( int i = 0; i < height; i++)
        {
            for( int j = 0; j < len*width; j++)
            {
                printf( "%c", output[ i ][ j ] );
            }
            printf( "\n" );
        }
    }
 
    return 0;
}