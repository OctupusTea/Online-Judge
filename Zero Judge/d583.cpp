#include <stdio.h>
#include <iostream>
using namespace std;

int main( void)
{
	int n = 0;
	int temp = 0;
	int i = 0;
	
	while( cin >> n )
	{
		for( i = 0; i < n; i++)
		{
			scanf( "%d", &temp);
		}
		for( i = 0; i < n; i++)
		{
			printf( "%d ", i+1);
		}
		printf( "\n");
	} 
	return 0;
}
