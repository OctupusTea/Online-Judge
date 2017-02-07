#include <stdio.h>
 
int main( void)
{
    int n = 0, i = 0;
    int data[1000] = {0};
    int first = 1;
 
    scanf( "%d", &n);
 
    for( i = 0; i < n; i++)
    {
        scanf( "%d", &data[i]);
        if( data[i] % 2 )
        {
            if( first)
            {
                printf( "%d", data[i]);
                first = 0;
            }
            else
            {
                printf( " %d", data[i]);
            }
        }
    }    
 
    printf( "\n");
    first = 1;
 
    for( i = 0; i < n; i++)
    {
        if( data[i] % 2 == 0 )
        {
            if( first)
            {
                printf( "%d", data[i]);
                first = 0;
            }
            else
            {
                printf( " %d", data[i]);
            }
        }
    }
 
    return 0;
}