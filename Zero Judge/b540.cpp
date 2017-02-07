#include <stdio.h>
using namespace std;

int main( void)
{
	int a[6] = {0}, ans = 0;
	
	while( ~scanf( "%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) )
	{
		ans = 0;
		
		if( a[0] >= a[3])
		{
			a[0] -= a[3];
		
			ans += 2 * a[3] * ( a[1] + a[2] );
		
			a[3] = 0;
		}
		else
		{
			a[3] -= a[0];
		
			ans += 2 * a[0] * ( a[1] + a[2] );
		
			a[0] = 0;
		}
	
		if( a[1] >= a[4])
		{
			a[1] -= a[4];
		
			ans += 2 * a[4] * ( a[2] + a[3] );
		
			a[4] = 0;
		}
		else
		{
			a[4] -= a[1];
		
			ans += 2 * a[1] * ( a[2] + a[3] );
		
			a[1] = 0;
		}
	
		if( a[2] >= a[5])
		{
			a[2] -= a[5];
		
			ans += 2 * a[5] * ( a[3] + a[4] );
		
			a[5] = 0;
		}
		else
		{
			a[5] -= a[2];
		
			ans += 2 * a[2] * ( a[3] + a[4] );
		
			a[2] = 0;
		}
	
		if( a[0] > 0 )
		{
			ans += a[0] * a[0];
		}
		else
		{
			ans += a[1] * a[1];
		}
	
		printf( "%d\n", ans);
	}
	
	return 0;
}
