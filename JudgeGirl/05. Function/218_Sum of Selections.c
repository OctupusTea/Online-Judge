#include <stdio.h>
 
int cNK( int n, int k )
{
    if( k > n / 2 )
    {
        k = n - k;
    }
 
    int i = 0, ans = 1;
    for( i = 1; i <= k; i++)
    {
        ans *= ( n - i + 1 );
        ans /= i;
    }
 
    return ans;
}
 
int main( void)
{
    int m = 0, n = 0;
 
    scanf( "%d%d", &n, &m);
 
    int ans = 0, i = 0;
    for( i = 0; i <= m; i++)
    {
        ans += cNK( n, i);
    }
 
    printf( "%d\n", ans);
 
    return 0;
}