#include <stdio.h>
 
int main( void)
{
    int a = 0, b = 0, c = 0, lcm = 0, gcd = 0;
 
    scanf( "%d", &lcm );
 
    while( ~scanf( "%d", &b ) )
    {
        gcd = lcm;
        a = b;
 
        while( b != 0 )
        {
            c = gcd % b;
            gcd = b;
            b = c;
        }
 
        lcm = lcm * a / gcd;
    }
 
    printf( "%d\n", lcm );
 
    return 0;
}