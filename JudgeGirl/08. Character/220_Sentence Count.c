#include <stdio.h>
#include <ctype.h>
 
char data[ 1000000 ] = {0};
 
int main( void)
{
    fread( data, 1, 1000000, stdin);
 
    int count = 0;
 
    for (int i = 0; data[i] != 0; i++)
    {
        if( data[i] == '.' )
        {
            if( data[ i+1 ] == ' ' && data[ i+2 ] == ' ' )
            {
                count++;
            }
            else if( data[ i+1 ] == '\n' || data[ i+1 ] == '\0' )
            {
                count++;
            }
        }
    }
    printf( "%d\n", count );
 
    return 0;
}