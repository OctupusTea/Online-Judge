#include <stdio.h>
#include <stdlib.h>
 
unsigned long long Gcd( unsigned long long a, unsigned long long b )
{
    unsigned long long c = 0;
 
    while( b != 0 )
    {
        c = b;
        b = a % b;
        a = c;
    }
 
    return a;
}
 
unsigned long long main( void )
{
    unsigned long long n = 0;
    scanf( "%llu", &n );
    unsigned long long pachinko[ 256 ][ 2 ] = {0};
    pachinko[ 0 ][ 0 ] = 1;
    for( unsigned long long i = 0; i < 256; i++ )
    {
        pachinko[ i ][ 1 ] = 1;
    }
 
    unsigned long long base = 0;
    for( unsigned long long i = 0; i < n; i++ )
    {
        for( unsigned long long j = 0; j < i + 1; j++ )
        {
            unsigned long long left_count = 0, right_count = 0;
            scanf( "%llu%llu", &left_count, &right_count );
            unsigned long long gcd = Gcd( left_count, right_count );
            left_count /= gcd, right_count /= gcd;
            #ifdef DEBUG
                printf( "#DEBUG : # %llu : left_count = %llu, right_count = %llu\n", base + j, left_count, right_count );
            #endif
            unsigned long long numerator_temp = left_count * pachinko[ base + j ][ 0 ];
            unsigned long long denominator_temp = ( left_count + right_count ) * pachinko[ base + j ][ 1 ];
            #ifdef DEBUG
                printf( "\t       numerator_temp = %llu, denominator_temp = %llu\n", numerator_temp, denominator_temp );
            #endif
            gcd = Gcd( numerator_temp, denominator_temp );
            numerator_temp /= gcd, denominator_temp /= gcd;
            #ifdef DEBUG
                printf( "\t       numerator_temp = %llu, denominator_temp = %llu\n", numerator_temp, denominator_temp );
            #endif
            pachinko[ base + j + i + 1 ][ 0 ] = pachinko[ base + j + i + 1 ][ 0 ] * denominator_temp + pachinko[ base + j + i + 1 ][ 1 ] * numerator_temp;
            pachinko[ base + j + i + 1 ][ 1 ] *= denominator_temp;
            gcd = Gcd( pachinko[ base + j + i + 1 ][ 0 ], pachinko[ base + j + i + 1 ][ 1 ] );
            pachinko[ base + j + i + 1 ][ 0 ] /= gcd, pachinko[ base + j + i + 1 ][ 1 ] /= gcd;
 
            numerator_temp = right_count * pachinko[ base + j ][ 0 ];
            denominator_temp = ( left_count + right_count ) * pachinko[ base + j ][ 1 ];
            gcd = Gcd( numerator_temp, denominator_temp );
            numerator_temp /= gcd, denominator_temp /= gcd;
 
            pachinko[ base + j + i + 2 ][ 0 ] = pachinko[ base + j + i + 2 ][ 0 ] * denominator_temp + pachinko[ base + j + i + 2 ][ 1 ] * numerator_temp;
            pachinko[ base + j + i + 2 ][ 1 ] *= denominator_temp;
            gcd = Gcd( pachinko[ base + j + i + 2 ][ 0 ], pachinko[ base + j + i + 2 ][ 1 ] );
            pachinko[ base + j + i + 2 ][ 0 ] /= gcd, pachinko[ base + j + i + 2 ][ 1 ] /= gcd;
        }
        base += ( i + 1 );
    }
 
    for( unsigned long long i = 0; i < n + 1; i++ )
    {
        printf( "%llu/%llu\n", pachinko[ base + i ][ 0 ], pachinko[ base + i ][ 1 ] );
    }
 
    #ifdef DEBUG
        for( unsigned long long i = 0; i < ( n + 2 ) * ( n + 3 ) / 2; i++ )
        {
            printf( "#DEBUG : # %llu = %llu/%llu\n", i, pachinko[ i ][ 0 ], pachinko[ i ][ 1 ] );
        }
    #endif
}