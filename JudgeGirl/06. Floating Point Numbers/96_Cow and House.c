#include <stdio.h> 
//#define DEBUG
 
int main( void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    double const pi = 3.1415926;
 
    scanf( "%lf %lf %lf", &a, &b, &c);
    #ifdef DEBUG
        printf( "%lf %lf %lf\n", a, b, c);
    #endif
 
    double area = 0.75 * pi * c * c;
    if( c > a )
    {
        area += 0.25 * pi * ( c - a ) * ( c - a );
    }
    if( c > b )
    {
        area += 0.25 * pi * ( c - b ) * ( c - b );
    }
 
    printf( "%lf\n", area);  
 
    return 0;
}