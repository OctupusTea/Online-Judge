#include <iostream>
#include <stdio.h>
using namespace std;

int main( void)
{
	int n = 0;
	int temp = 0, count[3] = {0};
	int i = 0, j = 0;
	
	while( cin >> n)
	{
		for( i = 0; i < 3; i++)
		{
			count[i] = 0;
		}
		
		for( i = 0; i < n; i++)
		{
			scanf( "%d", &temp);
			for( j = 1; j <= 3; j++)
			{
				if( temp == j)
				{
					count[j-1]++;
					break;
				}
			}
		}
		
		for( i = 0; i < 3; i++)
		{
			for( j = 0; j < count[i]; j++)
			{
				printf( "%d ", i+1);
			}
		}
		
		printf( "\n");
		
	}
	
	return 0;
}
