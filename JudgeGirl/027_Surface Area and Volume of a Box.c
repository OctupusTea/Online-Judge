#include<stdio.h>

int main( void)
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    
    scanf( "%d%d%d%d%d", &a, &b, &c, &d, &e);
    
	printf( "%d\n", ( a * b + b * c + c * a ) * 2 + ( a + b + c - e * 6 ) * d * 8 );
	
    printf( "%d", a * b * c - 2 * d * ( ( a - 2 * e ) * ( b - 2 * e ) + ( c - 2 * e ) * ( b - 2 * e ) + ( a - 2 * e ) * ( c - 2 * e ) ) );
    
	return 0;
}
