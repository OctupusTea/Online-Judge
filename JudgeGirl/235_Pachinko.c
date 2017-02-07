#include <stdio.h>

int gcd( int a, int b)
{
	int c = 0;
	
	if( a < b )
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	
	while( b != 0 )
	{
		c = a % b;
		b = c;
		a = b;
	}
	
	return a;
}

int main( void)
{
	int n = 0, pins = 0;
	int i = 0, j = 0;
	int pins[15][32768][2][2] = {0};
	int chance[15][32768][2][2] = {0};
	int expo = 1, temp = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < expo; j++)
		{
			scanf( "%d%d", &pins[n][j][0][0], &pins[n][j][1][0] );
			
			// < simplify numbers >
			if( pins[n][j][0][0] == 0 && pins[n][j][1][0] != 0)
			{
				pins[n][j][1][0] = 1;
			}
			else if( pins[n][j][1][0] == 0 && pins[n][j][0][0] != 0 );
			{
				pins[n][j][0][0] = 1;
			}
			else if( pins[n][j][1][0] != 0 )
			{
				if( pins[n][j][1][0] == pins[n][j][0][0] )
				{
					pins[n][j][1][0] = 1;
					pins[n][j][0][0] = 1;
				}
				else
				{
					temp = gcd( pins[n][j][1][0], pins[n][j][0][0] );
					pins[n][j][1][0] /= temp;
					pins[n][j][0][0] /= temp;
				}
			}
			// <\ simplify numbers >
			
			// < add chance fraction >
			if( pins[n][j][1][0] == 0 && pins[n][j][0][0] == 0 )
			{
				pins[n][j][1][1] = 1;
				pins[n][j][0][1] = 1;
			}
			else
			{
				pins[n][j][1][1] = pins[n][j][1][0] + pins[n][j][0][0];
				pins[n][j][0][1] = pins[n][j][1][0] + pins[n][j][0][0];
			}
			// <\ add chance fraction >
			
			// < merge chance with lower ones >
		}
		pins += expo;
		expo *= 2;
	}
	
	return 0;
}
