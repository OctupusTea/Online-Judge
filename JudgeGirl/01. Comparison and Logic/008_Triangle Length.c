#include<stdio.h>
int main(void)
{
    int a = 0, b = 0, c = 0;
    scanf( "%d%d%d", &a, &b, &c);
    if( a + b > c && b + c > a && c + a > b)
    {
        printf( "1\n");
    }
    else
    {
        printf( "0\n");
    }
    return 0;
}
