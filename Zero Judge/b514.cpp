#include <stdio.h>
using namespace std;

int main (void)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	int n = 0, i = 0;
	int d0 = 0, dx = 0, dy = 0;
	int x = 0, y = 0;
	
	while( ~scanf( "%d", &n) )
	{
		for( i = 0; i < n; i++)
		{
			scanf( "%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
			
			d0 = a * e - b * d;
			dx = c * e - b * f;
			dy = a * f - d * c;
			
			x = dx / d0;
			y = dy / d0;
			
			printf( "%d %d\n", x, y);
		}
	}
	
	return 0;
}
