#include <stdio.h>
#include <iostream>
using namespace std;

int main( void)
{
	int h1 = 0, m1 = 0, h2 = 0,m2 = 0;
	
	while( cin >> h1 >> m1 >> h2 >> m2 )
	{
		if( h2 > h1)
		{
			if( m2 >= m1)
			{
				printf( "%d %d\n", h2 - h1, m2 - m1);
			}
			else
			{
				printf( "%d %d\n", h2 - h1 - 1, m2 + 60 - m1);
			}
		}
		else if( h2 == h1)
		{
			if( m2 >= m1)
			{
				printf( "0 %d\n", m2 - m1);
			}
			else
			{
				printf( "%d %d\n", 23, m2 + 60 - m1);
			}
		}
		else
		{
			if( m2 >= m1)
			{
				printf( "%d %d\n", h2 + 24 - h1, m2 - m1);
			}
			else
			{
				printf( "%d %d\n", h2 + 23 - h1, m2 + 60 - m1);
			}
		}
	}
	
	return 0;
}
