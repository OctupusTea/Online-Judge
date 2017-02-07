#include <stdio.h>
#include <string.h>
using namespace std;

int main( void)
{
	int n = 0, i = 0, j = 0, k = 0;
	int len = 0, index = 0;
	char prev[100000] = {'1'}, next[100000] = {0};
	
	while( ~scanf( "%d", &n) )
	{
		for( i = 0; i < 100000; i++)
		{
			prev[i] = 0;
			next[i] = 0;
		}
		
		prev[0] = '1';
		
		for( i = 1; i < n; i++)
		{
			len = strlen( prev);
			index = 0;
			for( j = 0; j < len; j++)
			{
				for( k = j+1; k < len && prev[j] == prev[k]; k++);
				
				next[index] = k - j + 48;
				next[index+1] = prev[j];
				index += 2;
				
				j = k - 1;
			}
			
			len = strlen( next);
			
			for( j = 0; j < len; j++)
			{
				prev[j] = next[j];
			}
		}
		
		printf( "%s\n", prev);
	}
	
	return 0;
}
