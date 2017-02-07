#include <stdio.h>
using namespace std;

int main( void)
{
	int n = 0, i = 0;
	int max = 0, min = 0, temp = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d", &temp);
		if( temp == 1)
		{
			min = i;
		}
		else if( temp == n)
		{
			max = i;
		}
	}
	
	if( max == 0 || max == n-1 || min == 0 || min == n-1)
	{
		printf( "%d", n-1);
	}
	else if( max > min)
	{
		if( n - 1 - max > min)
		{
			printf( "%d", n-1-min);
		}
		else
		{
			printf( "%d", max);
		}
	}
	else
	{
		if( n - 1 - min > max)
		{
			printf( "%d", n-1-max);
		}
		else
		{
			printf( "%d", min);
		}
	}
	
	return 0;
}
