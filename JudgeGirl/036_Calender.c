#include <stdio.h>

int main( void)
{
	int y = 0, m = 0, d = 0;
	int maxd = 0, is229 = 0;
	int i = 0, j = 0;
	
	scanf( "%d%d%d", &y, &m, &d);
	
	if( y % 4 == 0)
	{
		if( y % 100 == 0)
		{
			if( y % 400 == 0)
			{
				is229 = 1;
			}
		}
		else
		{
			is229 = 1;
		}
	}
	
	if( m > 12 || m < 1 || d < 0 || d > 6)
	{
		printf( "invalid\n");
	}
	else
	{
		switch( m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxd = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				maxd = 30;
				break;
			case 2:
				if( is229)
				{
					maxd = 29;
				}
				else
				{
					maxd = 28;
				}
				break;
		}
		printf( " Su Mo Tu We Th Fr Sa\n=====================\n");
			
		for( i = 1; i <= d; i++)
		{
			printf( "   ");
		}
		for( i = 1; i <= 7-d; i++)
		{
			printf( "%3d", i);
		}
		printf( "\n");
		
		while( i <= maxd)
		{
			for( j = i; j < i + 7 && j <= maxd; j++)
			{
				printf( "%3d", j);
			}
			printf( "\n");
			i += 7;
		}
	
		printf( "=====================\n");
	}
	
	return 0;
}
