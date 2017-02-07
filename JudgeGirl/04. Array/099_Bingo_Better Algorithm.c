#include <stdio.h>
//#define DEBUG
//#define PRINT

#ifdef PRINT
void print( int xLines[10][256], int yLines[10][256], int diagonalLines[10][2], int n, int m);
#endif

int main( void)
{
	int m = 0, n = 0, i = 0, j = 0, k = 0;
	#ifdef DEBUG
	int pos[10][16385][2] = {0};
	#endif
	
	#ifndef DEBUG
	int pos[10][65537][2] = {0};
	#endif
	
	int xLines[10][256] = {0}, yLines[10][256] = {0}, diagonalLines[10][2] = {0};
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
				scanf( "%d", &temp );
				pos[i][temp][0] = j;
				pos[i][temp][1] = k;
			}
		}
	}
	
	while( ~scanf( "%d", &temp) )
	{
		for( i = 0; i < n; i++)
		{
			xLines[i][ pos[i][temp][0] ]++;
			yLines[i][ pos[i][temp][1] ]++;
			if( pos[i][temp][0] == pos[i][temp][1] )
			{
				diagonalLines[i][0]++;
			}
			if( pos[i][temp][0] + pos[i][temp][1] == m - 1 )
			{
				diagonalLines[i][1]++;
			}
		}
		
		#ifdef PRINT
		print( xLines, yLines, diagonalLines, n, m);
		#endif
		
		for( i = 0; i < n; i++)
		{
			for( j = 0; j < m; j++)
			{
				if( xLines[i][j] == m || yLines[i][j] == m )
				{
					bingo[i] = 1;
					break;
				}
			}
			if( !bingo[i] )
			{
				if( diagonalLines[i][0] == m || diagonalLines[i][1] == m )
				{
					bingo[i] = 1;
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
void print( int xLines[10][256], int yLines[10][256], int diagonalLines[10][2], int n, int m)
{
	int i = 0, j = 0;
	
	for( i = 0; i < n; i++)
	{
		printf( "player%3d : \n", i);
		for( j = 0; j < m; j++)
		{
			printf( "xLine%4d = %3d\n", j, xLines[i][j]);
		}
		printf( "\n");
		for( j = 0; j < m; j++)
		{
			printf( "yLine%4d = %3d\n", j, yLines[i][j]);
		}
		printf( "\n");
		for( j = 0; j < 2; j++)
		{
			printf( "diagonalLine%4d = %3d\n", j, diagonalLines[i][j]);
		}
		printf( "\n");
	}
	
	return;
}
#endif

