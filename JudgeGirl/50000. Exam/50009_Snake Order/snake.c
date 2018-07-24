#include "snake.h"
 
int snake( int *ptr, int *row, int *column )
{
	int row_counter = 0;
	int column_counter = 0;
	while( column_counter == *ptr )
	{
		++column_counter;
		++ptr;
	}
	++row_counter;

	int direction = 1;
	while( *ptr != 0 )
	{
		if( direction == 1 )
		{
			for( int i = column_counter - 1; i >= 0; --i, ++ptr )
			{
				if( *ptr != row_counter * column_counter + i )
				{
					*row = row_counter;
					*column = i;
					return 0;
				}
			}

			direction = 0;
		}
		else if( direction == 0 )
		{
			for( int i = 0; i < column_counter; ++i, ++ptr )
			{
				if( *ptr != row_counter * column_counter + i )
				{
					*row = row_counter;
					*column = i;
					return 0;
				}
			}

			direction = 1;
		}

		++row_counter;
	}

	*row = row_counter;
	*column = column_counter;
	return 1;
}
