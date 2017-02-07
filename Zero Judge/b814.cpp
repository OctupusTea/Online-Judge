#include <stdio.h>
#include <string.h>
using namespace std;

int main( void)
{
	int t = 0, n = 0, m = 0;
	int l = 0, r = 0;
	int i = 0, j = 0, count = 0;
	char data[100000] = {0};
	
	scanf( "%s", data);
	n = strlen( data);
	
	scanf( "%d", &t);
	
	for( i = 0; i < t; i++)
	{
		scanf( "%d%d", &l, &r);
		count = 0;
		
		for( j = l; j < r; j++)
		{
			if( data[j-1] == data[j])
			{
				count++;
			}
		}
		
		printf( "%d\n", count);
	}
	
	return 0;
}
