#include <stdio.h>
//#define DEBUG

int main( void)
{
	int n = 0, i = 0, j = 0;
	int block[102][102] = {0};
	int intersection = 0, tJunction = 0, turn = 0, deadEnd = 0;
	
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			scanf( "%d", &block[i][j]);
		}
	}
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			#ifdef DEBUG
				printf( "%d %d : ", i, j);
			#endif
			if( block[i][j] )
			{
				if( i == 0)
				{
					if( j == 0)
					{
						if( block[i+1][j] && block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else if( block[i+1][j] ^ block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else if( j == n - 1 )
					{
						if( block[i+1][j] && block[i][j-1] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else if( block[i+1][j] ^ block[i][j-1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else
					{
						if( block[i+1][j] )
						{
							if( block[i][j+1] && block[i][j-1] )
							{
								#ifdef DEBUG
									printf( "T-junction\n");
								#endif
								tJunction++;
							}
							else if( block[i][j+1] ^ block[i][j-1] )
							{
								#ifdef DEBUG
									printf( "turn\n");
								#endif
								turn++;
							}
							else
							{
								#ifdef DEBUG
									printf( "dead end\n");
								#endif
								deadEnd++;
							}
						}
						else if( block[i][j+1] ^ block[i][j-1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
				}
				else if( i == n - 1)
				{
					if( j == 0)
					{
						if( block[i-1][j] && block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else if( block[i-1][j] ^ block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else if( j == n - 1 )
					{
						if( block[i-1][j] && block[i][j-1] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else if( block[i-1][j] ^ block[i][j-1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else
					{
						if( block[i-1][j] )
						{
							if( block[i][j+1] && block[i][j-1] )
							{
								#ifdef DEBUG
									printf( "T-junction\n");
								#endif
								tJunction++;
							}
							else if( block[i][j-1] ^ block[i][j+1] )
							{
								#ifdef DEBUG
									printf( "turn\n");
								#endif
								turn++;
							}
							else
							{
								#ifdef DEBUG
									printf( "dead end\n");
								#endif
								deadEnd++;
							}
						}
						else if( block[i][j-1] ^ block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
				}
				else if( j == 0 )
				{
					if( block[i][j+1] )
					{
						if( block[i+1][j] && block[i-1][j] )
						{
							#ifdef DEBUG
								printf( "T-junction\n");
							#endif
							tJunction++;
						}
						else if( block[i+1][j] ^ block[i-1][j] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else if( block[i+1][j] ^ block[i-1][j] )
					{
						#ifdef DEBUG
							printf( "dead end\n");
						#endif
						deadEnd++;
					}
				}
				else if( j == n - 1 )
				{
					if( block[i][j-1] )
					{
						if( block[i+1][j] && block[i-1][j] )
						{
							#ifdef DEBUG
								printf( "T-junction\n");
							#endif
							tJunction++;
						}
						else if( block[i+1][j] ^ block[i-1][j] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else if( block[i+1][j] ^ block[i-1][j] )
					{
						#ifdef DEBUG
							printf( "dead end\n");
						#endif
						deadEnd++;
					}
				}
				else
				{
					if( block[i-1][j] && block[i+1][j] )
					{
						if( block[i][j-1] && block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "Intersection\n");
							#endif
							intersection++;
						}
						else if( block[i][j-1] ^ block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "T-junction\n");
							#endif
							tJunction++;
						}
					}
					else if( block[i-1][j] ^ block[i+1][j] )
					{
						if( block[i][j-1] && block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "T-junction\n");
							#endif
							tJunction++;
						}
						else if( block[i][j-1] ^ block[i][j+1] )
						{
							#ifdef DEBUG
								printf( "turn\n");
							#endif
							turn++;
						}
						else
						{
							#ifdef DEBUG
								printf( "dead end\n");
							#endif
							deadEnd++;
						}
					}
					else if( block[i][j-1] ^ block[i][j+1] )
					{
						#ifdef DEBUG
							printf( "dead end\n");
						#endif
						deadEnd++;
					}
				}
			}
		}
	}
	
	printf( "%d\n%d\n%d\n%d", intersection, tJunction, turn, deadEnd);
	
	return 0;
}
