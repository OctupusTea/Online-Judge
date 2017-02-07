#include <stdio.h>
 
int main( void)
{
    char m[8] = {0};
    char n[3] = {0};
 
    int i = 0, count = 0;
 
    scanf( "%s", &n);
    scanf( "%s", &m);
 
    for( i = 0; i < 6; i++)
    {
        if( m[i] == n[0] && m[i+1] == n[1])
        {
            count++;
        }
    }
 
    printf( "%d", count); 
 
    return 0;
}