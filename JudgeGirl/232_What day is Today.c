#include <stdio.h>

int main( void)
{
	int y = 0, f = 0, f2 = 0;
	int n = 0, i = 0, j = 0;
	int m = 0, d = 0, maxd = 0;
	int is229 = 0;
	
	scanf( "%d%d%d", &y, &f2, &n);
	
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
			is229 == 1;
		}
	}
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d%d", &m, &d);
		f = f2;
		
		if( m > 12 || m < 0 )
		{
			printf("-1\n");
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
					if( is229 == 1)
					{
						maxd = 29;
					}
					else
					{
						maxd = 28;
					}
					break;
			}
			
			if( d < 0 || d > maxd)
			{
				printf( "-2\n");
			}
			else
			{
				switch( m)
				{
					case 12:
						f += 30;
					case 11:
						f += 31;
					case 10:
						f += 30;
					case 9:
						f += 31;
					case 8:
						f += 31;
					case 7:
						f += 30;
					case 6:
						f += 31;
					case 5:
						f += 30;
					case 4:
						f += 31;
					case 3:
						if( is229)
						{
							f += 29;
						}
						else
						{
							f += 28;
						}
					case 2:
						f += 31;
				}
				
				f += d;
				f %= 7;
				
				printf( "%d\n", f);
			}
		}
	}
	
	return 0;
}
