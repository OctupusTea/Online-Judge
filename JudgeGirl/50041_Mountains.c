#include <stdio.h>

int main( void)
{
	int n = 0, i = 0;
	int nextUpHill = 0, prevUpHill = 0;
	int nextHight = 0, prevHight = 0;
	int fuelCost = 0;
	
	scanf( "%d", &n);
	
	scanf( "%d", &prevHight);
	scanf( "%d", &nextHight);
	
	if( nextHight > prevHight)
	{
		nextUpHill =  1;
	}
	fuelCost += ( prevUpHill + nextUpHill + 2 ) * abs( nextHight - prevHight );
	
	for( i = 0; i < n - 2; i++)
	{
		prevHight = nextHight;
		scanf( "%d", &nextHight);
		
		prevUpHill = nextUpHill;
		if( nextHight > prevHight)
		{
			nextUpHill = 1;
		}
		else
		{
			nextUpHill = 0;
		}
		
		fuelCost += ( prevUpHill + nextUpHill + 2 ) * abs( nextHight - prevHight );
	}
	
	printf( "%d", fuelCost);
	
	return 0;
}
