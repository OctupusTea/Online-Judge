#include <stdlib.h>
#include <stdio.h>

int main( void )
{
	int fixed_size, current_number = 0, last_number;
	scanf( "%d%d", &fixed_size, &last_number );
	if( last_number != 0 )
	{
		scanf( "%d", &current_number );
	}
	
	int max_subcount = 0;
	int current_subcount = current_number > 0 ? 0 : 0xFFFFFFFF;
	int current_length = 1;
	
	while( current_number != 0 )
	{
		if( current_number > 0 )
		{
			if( last_number > 0 )
			{
				current_length++;
			}
			else
			{
				if( current_length == fixed_size )
				{
					current_subcount++;
					current_length = 1;
				}
				else
				{
					current_subcount = 0;
					current_length = 1;
				}
			}
		}
		else
		{
			if( last_number < 0 )
			{
				current_length++;
			}
			else
			{
				if( current_length < fixed_size )
				{
					current_subcount = 0xFFFFFFFF;
					current_length = 1;
				}
				else if( current_length == fixed_size )
				{
					if( current_subcount < 0 )
					{
						current_subcount = 0;
					}
					else if( current_subcount + 1 > max_subcount )
					{
						max_subcount = current_subcount + 1;
					}
					
					current_subcount++;
					current_length = 1;
				}
				else
				{
					if( current_subcount + 1 > max_subcount )
					{
						max_subcount = current_subcount + 1;
					}
					
					current_subcount = 1;
					current_length = 1;
				}
			}
		}
		#ifdef DEBUG
			printf( "%3d, %3d, current_length = %d, current_subcount = %d, max_subcount = %d\n", last_number, current_number, current_length, current_subcount, max_subcount );
		#endif
		last_number = current_number;
		scanf( "%d", &current_number );
	}
	
	if( current_length >= fixed_size )
	{
		if( last_number < 0 )
		{
			current_subcount--;
		}
		
		if( current_subcount + 1 > max_subcount )
		{
			max_subcount = current_subcount + 1;
		}
	}
	
	printf( "%d\n", ( max_subcount >= 3 ? max_subcount * fixed_size : 0 ) );
	
	return 0;
}