#include <stdio.h>

#define TIME_SCALE 1048576

int main( void )
{
	int counter_count, customer_count;

	scanf( "%d%d", &counter_count, &customer_count );
	
	int time_table[ TIME_SCALE ];
	for( int i = 0; i < TIME_SCALE; ++i )
	{
		time_table[ i ] = counter_count;
	}

	int last_available = 0;
	int waiting_time = 0;
	for( int i = 0; i < customer_count; ++i )
	{
		int arrival_time, service_time;
		scanf( "%d%d", &arrival_time, &service_time );
#ifdef DEBUG
		printf( "last_available = %d\n", last_available );
#endif
		if( last_available > arrival_time )
		{
			waiting_time += ( last_available - arrival_time );
			arrival_time = last_available;
		}
		
		int last_set = 0;
		
		service_time += arrival_time;
		for( int j = arrival_time; j < service_time; ++j )
		{
			--time_table[ j ];

			if( time_table[ j ] != 0 && last_set == 0 )
			{
				last_set = 1;
				last_available = j;
			}
		}

		if( last_set == 0 )
		{
			last_available = service_time;
		}
	}

	printf( "%d\n", waiting_time );

	return 0;
}
