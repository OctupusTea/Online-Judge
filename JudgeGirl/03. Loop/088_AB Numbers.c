#include <stdio.h>

int main( void)
{
	int n = 0, m = 0;
	int i = 0, j = 0;
	int a = 0, b = 0;
	int dig[2][4] = {0};
	
	scanf( "%d%d", &n, &m);
	
	for( i = 0; i < 4; i++)
	{
		dig[0][3-i] = n % 10;
		n /= 10;
	}
	for( i = 0; i < 4; i++)
	{
		dig[1][3-i] = m % 10;
		m /= 10;
	}
	
	for( i = 0; i < 4; i++)
	{
		if( dig[0][i] == dig[1][i])
		{
			a++;
		}
		for( j = i + 1; j < 4; j++)
		{
			if( dig[0][i] == dig[1][j])
			{
				b++;
			}
			if( dig[1][i] == dig[0][j])
			{
				b++;
			}
		}
	}
	
	printf( "%dA%dB", a, b);
	
	return 0;
}
