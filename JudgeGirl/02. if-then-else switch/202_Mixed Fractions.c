#include <stdio.h>

int main( void)
{
	int frac[6] = {0}, op = 0;
	int a = 0, b = 0, c = 0;
	int i = 0;
	
	for( i = 0; i < 6; i++)
	{
		if( i == 3)
		{
			scanf( "%d", &op);
		}
		scanf( "%d", &frac[i]);
	}
	
	if( frac[0] > 0)
	{
		frac[1] += frac[0] * frac[2];
	}
	else
	{
		frac[1] = frac[0] * frac[2] - frac[1];
	}
	
	if( frac[3] > 0)
	{
		frac[4] += frac[3] * frac[5];
	}
	else
	{
		frac[4] = frac[3] * frac[5] - frac[4];
	}
	
	switch( op)
	{
		case 0:
			frac[1] = frac[1] * frac[5] + frac[4] * frac[2];
			frac[2] *= frac[5];
			break;
		case 1:
			frac[1] = frac[1] * frac[5] - frac[4] * frac[2];
			frac[2] *= frac[5];
			break;
		case 2:
			frac[1] *= frac[4];
			frac[2] *= frac[5];
			break;
		case 3:
			frac[1] *= frac[5];
			frac[2] *= frac[4];
			break;
	}
	
	if( frac[1] % frac[2] == 0)
	{
		frac[0] = frac[1] / frac[2];
		frac[1] = 0;
		frac[2] = 1;
	}
	else
	{
		a = frac[1], b = frac[2];
	
		while( b != 0)
		{
			c = b;
			b = a % b;
			a = c;
		}
		
		frac[1] /= a;
		frac[2] /= a;
		
		frac[0] = frac[1] / frac[2];
		frac[1] = abs(frac[1] - frac[2]) % frac[2];
	}
	
	frac[2] = abs( frac[2] );
	
	printf( "%d\n%d\n%d", frac[0], frac[1], frac[2]);
	
	return 0;
}
