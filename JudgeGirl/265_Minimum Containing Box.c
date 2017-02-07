#include <stdio.h>

int main( void)
{
	int minX = 10000, maxX = -10000;
	int minY = 10000, maxY = -10000;
	int tempX = 0, tempY = 0;
	
	while( ~scanf( "%d%d", &tempX, &tempY ) )
	{
		if( tempX > maxX )
		{
			maxX = tempX;
		}
		
		if( tempX < minX )
		{
			minX = tempX;
		}
		
		if( tempY > maxY )
		{
			maxY = tempY;
		}
		
		if( tempY < minY )
		{
			minY = tempY;
		}
	}
	
	printf( "%d", ( maxX - minX ) * ( maxY - minY ) );
	
	return 0;
}
