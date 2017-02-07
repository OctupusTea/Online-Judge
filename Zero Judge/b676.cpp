#include <stdio.h>

int main( void)
{
	int n = 0;
	
	while( ~scanf( "%d", &n) )
	{
		switch( n%5)
		{
			case 0:
				printf( "U\n");
				break;
			case 1:
				printf( "G\n");
				break;
			case 2:
				printf( "Y\n");
				break;
			case 3:
				printf( "T\n");
				break;
			case 4:
				printf( "I\n");
				break;
		}
	}
	return 0;
}
