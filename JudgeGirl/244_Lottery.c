#include <stdio.h>

int main( void)
{
	char spec[3][9] = {0};
	char first[3][9] = {0};
	char temp[9] = {0};
	int i = 0, j = 0, count = 0;
	unsigned long int prize[9] = {0,0,0,200,1000,4000,10000,40000,200000};
	unsigned long int amount = 0;
	
	scanf( "%s%s%s%s%s%s", &spec[0], &spec[1], &spec[2], &first[0], &first[1], &first[2] );
	
	while( ~scanf( "%s", &temp) )
	{
		count = 0;
		for( i = 0; i < 3; i++)
		{
			count = 0;
			for( j = 7; j >= 0; j--)
			{
				if( temp[j] == spec[i][j])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if( count == 8)
			{
				amount += 2000000;
			}
		}
		
		for( i = 0; i < 3; i++)
		{
			count = 0;
			for( j = 7; j >= 0; j--)
			{
				if( temp[j] == first[i][j])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			
			amount += prize[count];
		}
	}
	
	printf( "%d", amount);
	
	return 0;
}
