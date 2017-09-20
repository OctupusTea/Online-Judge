#include <stdio.h>

int main( void )
{
	int top, bottom;
	scanf( "%d%d", &top, &bottom );
	
	int apple_count = ( top + bottom ) * ( bottom - top + 1 ) / 2;
	int inner_count = ( top + bottom - 4 ) * ( bottom - top - 1 ) / 2;
	printf( "%d\n%d\n", apple_count, apple_count - inner_count );
	
	return 0;
}