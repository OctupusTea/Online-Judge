#include "blockmover.h"

#include <stdlib.h>
#include <stdio.h>

void printBlock( unsigned long long int *blcok )
{
	unsigned char *board = ( unsigned char* )blcok;
	for( int i = 0; i < 8; ++i )
	{
		unsigned char mask = 0x01;
		for( int j = 0; j < 8; ++j )
		{
			printf( "%s", ( ( board[ i ] ) & mask ) ? "1" : "0" );
			mask <<= 1;
		}

		printf( "\n" );
	}
}

void initialize( unsigned long long int *block, int row, int column, int size )
{
	*block = 0;
	unsigned char *board = ( unsigned char* )block;
	static const unsigned char pos[ 9 ] = { 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF };

	for( int i = 0; i < size; ++i )
	{
		board[ i ] |= pos[ size ];
	}

	for( int i = 0; i < row; ++i )
	{
		moveDown( block );
	}

	for( int i = 0; i < column; ++i )
	{
		moveRight( block );
	}
}

int moveLeft( unsigned long long int *block )
{
	static const unsigned long long left_bound = 0x0101010101010101;
	if( ( *block ) & left_bound )
	{
		return 0;
	}
	else
	{
		( *block ) >>= 1;
		return 1;
	}
}

int moveRight( unsigned long long int *block )
{
	static const unsigned long long right_bound = 0x8080808080808080;
	if( ( *block ) & right_bound )
	{
		return 0;
	}
	else
	{
		( *block ) <<= 1;
		return 1;
	}
}

int moveUp( unsigned long long int *block )
{
	
	static const unsigned long long top_bound = 0x00000000000000FF;
	if( ( *block ) & top_bound )
	{
		return 0;
	}
	else
	{
		( *block ) >>= 8;
		return 1;
	}
}

int moveDown( unsigned long long int *block )
{
	static const unsigned long long bottom_bound = 0xFF00000000000000;
	if( ( *block ) & bottom_bound )
	{
		return 0;
	}
	else
	{
		( *block ) <<= 8;
		return 1;
	}
}
