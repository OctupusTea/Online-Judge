#include <stdio.h>

int main( void)
{
	int n = 0, i = 0, j = 0, k = 0;
	int stepCount = 0, winner = 0;
	int board[3][3] = {0};
	int x = 0, y = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%d%d", &x, &y);
		
		if( x < 3 && x > -1 && y < 3 && y > -1 && board[x][y] == 0 )
		{
			if( stepCount % 2 == 0 )
			{
				board[x][y] = -1;
			}
			else
			{
				board[x][y] = 1;
			}
			stepCount++;
		}
		
		for( j = 0; j < 3; j++)
		{
			if( board[j][0] != 0 && board[j][0] == board[j][1] && board[j][1] == board[j][2] )
			{
				winner = board[j][0];
				break;
			}
			if( board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j] )
			{
				winner = board[0][j];
				break;
			}
		}
		
		if( board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] )
		{
			winner = board[0][0];
		}
		
		if( board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0] )
		{
			winner = board[0][2];
		}
		
		if( winner != 0 || stepCount == 9 )
		{
			break;
		}
	}
	
	if( winner == -1 )
	{
		printf( "Black wins.");
	}
	else if( winner == 1 )
	{
		printf( "White wins.");
	}
	else
	{
		printf( "There is a draw.");
	}
	
	return 0;
}
