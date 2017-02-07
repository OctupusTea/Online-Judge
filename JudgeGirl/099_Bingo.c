#include <stdio.h>
//#define DEBUG
//#define PRINT

#ifdef PRINT
void print( int board[10][160][160], int n, int p);
#endif

int main( void)
{
	int m = 0, n = 0, i = 0, j = 0, k = 0;
	#ifdef DEBUG
	int board[10][128][128] = {0};
	int pos[10][16385][2] = {0};
	#endif
	#ifndef DEBUG
	int board[10][256][256] = {0};
	int pos[10][65537][2] = {0};
	#endif
	char player[10][64] = {0};
	int bingo[10] = {0}, winnerCount = 0;
	int temp = 0, found = 0;
	
	scanf( "%d%d", &n, &m);
	
	for( i = 0; i < n; i++)
	{
		scanf( "%s", &player[i] );
		for( j = 0; j < m; j++)
		{
			for( k = 0; k < m; k++)
			{
				scanf( "%d", &board[i][j][k] );
				pos[i][ board[i][j][k] ][0] = j;
				pos[i][ board[i][j][k] ][1] = k;
			}
		}
	}
	
	while( ~scanf( "%d", &temp) )
	{
		for( i = 0; i < n; i++)
		{
			/*found = 0;
			
			for( j = 0; j < m; j++)
			{
				for( k = 0; k < m; k++)
				{
					if( board[i][j][k] == temp )
					{
						board[i][j][k] = -1;
						found = 1;
						break;
					}
				}
				if( found)
				{
					break;
				}
			}*/
			
			board[i][ pos[i][temp][0] ][ pos[i][temp][1] ] = -1;
			
			#ifdef PRINT
			print( board, m, i);
			#endif
		}
		
		for( i = 0; i < n; i++)
		{
			for( j = 0; j < m; j++)
			{
				bingo[i] = 1;
			
				for( k = 0; k < m; k++)
				{
					if( board[i][j][k] != -1 )
					{
						bingo[i] = 0;
						break;
					}
				}
				
				if( bingo[i] )
				{
					break;
				}
			}
			
			if( bingo[i] == 0 )
			{
				for( j = 0; j < m; j++)
				{
					bingo[i] = 1;
					
					for( k = 0; k < m; k++)
					{
						#ifdef PRINT
						printf( "i = %d , j = %d , k = %d , board[ %d ][ %d ][ %d ] = %d\n", i , j , k, i, k, j, board[i][k][j] );
						#endif
						
						if( board[i][k][j] != -1 )
						{
							bingo[i] = 0;
							break;
						}
					}
					
					if( bingo[i] )
					{
						break;
					}
				}
			}
			
			if( bingo[i] == 0 )
			{
				bingo[i] = 1;
				for( j = 0; j < m; j++)
				{
					if( board[i][j][j] != -1 )
					{
						bingo[i] = 0;
						break;
					}
				}
			}
			
			if( bingo[i] == 0)
			{
				bingo[i] = 1;
				for( j = 0; j < m; j++)
				{
					if( board[i][j][m-j-1] != -1 )
					{
						bingo[i] = 0;
						break;
					}
				}
			}
		}
		
		found = 0;
		
		for( i = 0; i < n; i++)
		{
			if( bingo[i] )
			{
				winnerCount++;
				if( found == 0 )
				{
					printf( "%d ", temp);
					found = 1;
				}
			}
		}
		
		for( i = 0; i < n; i++)
		{
			if( bingo[i] )
			{
				if( winnerCount != 1 )
				{
					printf( "%s ", player[i] );
					winnerCount--;
				}
				else
				{
					printf( "%s", player[i] );
				}
			}
		}
		
		if( found )
		{
			break;
		}
	}
	
	return 0;
}

#ifdef PRINT
void print( int board[10][160][160], int n, int p)
{
	int i = 0, j = 0;
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			printf( "%4d", board[p][i][j] );
		}
		printf( "\n");
	}
	printf( "\n");
}
#endif

