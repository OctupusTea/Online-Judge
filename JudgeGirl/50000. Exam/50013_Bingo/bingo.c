const unsigned long long diagonal_mask[ 2 ] = { 0x8040201008040201, 0x0102040810204080 };
const unsigned long long column_mask[ 8 ] = { 0x8080808080808080, 0x4040404040404040, 0x2020202020202020, 0x1010101010101010,
											  0x0808080808080808, 0x0404040404040404, 0x0202020202020202, 0x0101010101010101 };

int bingo( const unsigned long long int *board, int *rowColumn )
{
	unsigned char *bingo_board = ( unsigned char* ) board;

	for( int i = 7 ; i >= 0; --i )
	{
		if( bingo_board[ i ] == 0xFF )
		{
			*rowColumn = 7 - i;
			return 1;
		}
	}

	for( int i = 0; i < 8; ++i )
	{
		if( ( ( *board ) & column_mask[ i ] ) == column_mask[ i ] )
		{
			*rowColumn = i;
			return 2;
		}
	}
	
	if( ( ( *board ) & diagonal_mask[ 0 ] ) == diagonal_mask[ 0 ] )
	{
		*rowColumn = 0;
		return 3;
	}
	if( ( ( *board ) & diagonal_mask[ 1 ] ) == diagonal_mask[ 1 ] )
	{
		*rowColumn = 1;
		return 3;
	}

	return 0;
}
