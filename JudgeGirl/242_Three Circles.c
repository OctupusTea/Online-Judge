#include <stdio.h>

int main( void)
{
	int n = 0, i = 0, j = 0, k = 0, l = 0;
	int cir[3][3] = {0};
	int count = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		count = 0;
		
		for( j = 0; j < 3; j++)
		{
			for( k = 0; k < 3; k++)
			{
				scanf( "%d", &cir[j][k]);
			}
		}
		
		for( j = cir[0][0] - cir[0][2]; j <= cir[0][0] + cir[0][2]; j++)
		{
			for( k = cir[0][1] - cir[0][2]; k <= cir[0][1] + cir[0][2]; k++)
			{
				if( (j-cir[0][0])*(j-cir[0][0]) + (k-cir[0][1])*(k-cir[0][1]) <= cir[0][2] * cir[0][2] )
				{
					if( abs(j-cir[1][0]) <= cir[1][2] && abs(k-cir[1][1]) <= cir[1][2] && (j-cir[1][0])*(j-cir[1][0]) + (k-cir[1][1])*(k-cir[1][1]) <= cir[1][2] * cir[1][2] )
					{
						if( abs(j-cir[2][0]) <= cir[2][2] && abs(k-cir[2][1]) <= cir[2][2] && (j-cir[2][0])*(j-cir[2][0]) + (k-cir[2][1])*(k-cir[2][1]) <= cir[2][2] * cir[2][2] )
						{
							count++;
						}
					}
					else if( abs(j-cir[2][0]) <= cir[2][2] && abs(k-cir[2][1]) <= cir[2][2] && (j-cir[2][0])*(j-cir[2][0]) + (k-cir[2][1])*(k-cir[2][1]) <= cir[2][2] * cir[2][2] )
					{
						;
					}
					else
					{
						count++;
					}
				}
			}
		}
		
		for( j = cir[1][0] - cir[1][2]; j <= cir[1][0] + cir[1][2]; j++)
		{
			for( k = cir[1][1] - cir[1][2]; k <= cir[1][1] + cir[1][2]; k++)
			{
				if( (j-cir[1][0])*(j-cir[1][0]) + (k-cir[1][1])*(k-cir[1][1]) <= cir[1][2] * cir[1][2] )
				{
					if( abs(j-cir[0][0]) <= cir[0][2] && abs(k-cir[0][1]) <= cir[0][2] && (j-cir[0][0])*(j-cir[0][0]) + (k-cir[0][1])*(k-cir[0][1]) <= cir[0][2] * cir[0][2] )
					{
						;
					}
					else if( abs(j-cir[2][0]) <= cir[2][2] && abs(k-cir[2][1]) <= cir[2][2] && (j-cir[2][0])*(j-cir[2][0]) + (k-cir[2][1])*(k-cir[2][1]) <= cir[2][2] * cir[2][2] )
					{
						;
					}
					else
					{
						count++;
					}
				}
			}
		}
		
		for( j = cir[2][0] - cir[2][2]; j <= cir[2][0] + cir[2][2]; j++)
		{
			for( k = cir[2][1] - cir[2][2]; k <= cir[2][1] + cir[2][2]; k++)
			{
				if( (j-cir[2][0])*(j-cir[2][0]) + (k-cir[2][1])*(k-cir[2][1]) <= cir[2][2] * cir[2][2] )
				{
					if( abs(j-cir[0][0]) <= cir[0][2] && abs(k-cir[0][1]) <= cir[0][2] && (j-cir[0][0])*(j-cir[0][0]) + (k-cir[0][1])*(k-cir[0][1]) <= cir[0][2] * cir[0][2] )
					{
						;
					}
					else if( abs(j-cir[1][0]) <= cir[1][2] && abs(k-cir[1][1]) <= cir[1][2] && (j-cir[1][0])*(j-cir[1][0]) + (k-cir[1][1])*(k-cir[1][1]) <= cir[1][2] * cir[1][2] )
					{
						;
					}
					else
					{
						count++;
					}
				}
			}
		}
		
		printf( "%d\n", count);
	}
	
	return 0;
}
