#include <stdio.h>

int main( void)
{
	int n = 0, m = 0, i = 0, j = 0, k = 0;
	int min = 0;
	int lot[10][4] = {0};
	int coord[2] = {0}, dist[10] = {0};
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < 3; j++)
		{
			scanf( "%d", &lot[i][j]);
		}
	}
	
	scanf( "%d", &m);
	
	for( i = 0; i < m; i++)
	{
		scanf( "%d%d", &coord[0], &coord[1]);
		
		for( j = 0; j < n; j++)
		{
			dist[j] = abs( coord[0] - lot[j][0] ) + abs( coord[1] - lot[j][1] );
		}
		
		min = 0;
		
		for( j = 0; lot[j][2] <= lot[j][3]; j++)
		{
			
		}
		
		min = j;
		
		for( j = min; j < n; j++)
		{
			if( lot[j][2] > lot[j][3])
			{
				if( dist[j] < dist[min])
				{
					min = j;
				}
				else if( dist[j] == dist[min])
				{
					if( lot[j][0] < lot[min][0])
					{
						min = j;
					}
					else if( lot[j][0] == lot[min][0] && lot[j][1] < lot[min][1])
					{
						min = j;
					}
				}
			}
		}
		lot[min][3]++;
	}
	
	for( i = 0; i < n; i++)
	{
		printf( "%d\n", lot[i][3]);
	}
	
	return 0;
}
