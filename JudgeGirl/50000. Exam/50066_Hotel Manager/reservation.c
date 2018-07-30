#include <stdlib.h>

#ifdef DEBUG

#include <stdio.h>

#endif

#include "reservation.h"

inline Reservation* New_Reservation( int guest_count, int start_time, int end_time, Reservation *prev, Reservation *next )
{
	Reservation *this = ( Reservation* )malloc( sizeof( Reservation ) );

	this -> nP = guest_count;
	this -> StartTime = start_time;
	this -> EndTime = end_time;

	if( prev != NULL )
	{
		prev -> next = this;
	}

	this -> next = next;

	return this;
}

int ReserveRoom( RoomStatus room_list[ ], int room_count, int guest_count, int start_time, int end_time )
{
#ifdef DEBUG
	printf( "ReserveRoom( %d, %d, %d )\n", guest_count, start_time, end_time );
#endif
	for( int i = 0; i < room_count; ++i )
	{
		if( room_list[ i ].capacity >= guest_count )
		{
			if( room_list[ i ].reservation == NULL )
			{
#ifdef DEBUG
				printf( "Room #%d empty.\n", i );
#endif
				room_list[ i ].reservation = New_Reservation( guest_count, start_time, end_time, NULL, NULL );
				return 1;
			}
			else
			{
#ifdef DEBUG
				printf( "There are some reservations for room #%d.\n", i );
#endif
				if( room_list[ i ].reservation -> StartTime >= end_time )
				{
					Reservation *head = New_Reservation( guest_count, start_time, end_time, NULL, room_list[ i ].reservation );
					room_list[ i ].reservation = head;

					return 1;
				}
				
				Reservation *curr = room_list[ i ].reservation;
				Reservation *next;

				while( curr != NULL )
				{
					next = curr -> next;
					
					if( curr -> EndTime <= start_time
						&& ( next == NULL
							 || next -> StartTime >= end_time ) )
					{
						New_Reservation( guest_count, start_time, end_time, curr, next );
						return 1;
					}

					curr = next;
				}
			}
		}
	}

	return 0;
}
