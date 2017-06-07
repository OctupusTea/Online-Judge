#include <stdio.h>
 
int main( void)
{
    int count[26] = {0};
    char temp = 0;
 
    while( ~scanf( "%c", &temp ) )
    {
        if( temp >= 'A' && temp <= 'Z' )
        {
            count[ temp - 'A' ]++;
        }
        else if( temp >= 'a' && temp <= 'z' )
        {
            count[ temp - 'a' ]++;
        }
    }
 
    for( int i = 0; i < 26; i++)
    {
        printf( "%d\n", count[i] );
    }
 
    return 0;
}