#include <stdio.h>

int main( void)
{
	int n = 0, i = 0, j = 0;
	int data[4][2] = {0};
	int vec[3][2] = {0};
	int product[3] = {0};
	int len[6] = {0};
	int isRightAngle = 0, isEqualSide = 0;
		
	scanf( "%d", &n);
	
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < 4; j++)
		{
			scanf( "%d%d", &data[j][0], &data[j][1] );
		}
		
		for( j = 0; j < 3; j++)
		{
			vec[j][0] = data[j+1][0] - data[0][0];
			vec[j][1] = data[j+1][1] - data[0][1];
		}
		
		for( j = 0; j < 3; j++)
		{
			product[j] = vec[j][0] * vec[ (j+1)%3 ][1] - vec[ (j+1)%3 ][0] * vec[j][1];
		}
		
		if( product[0] > 0 )
		{
			if( product[1] > 0 )
			{
				;
			}
			else if( product[2] > 0 )
			{
				data[1][0] ^= data[3][0];
				data[3][0] ^= data[1][0];
				data[1][0] ^= data[3][0];
				
				data[1][1] ^= data[3][1];
				data[3][1] ^= data[1][1];
				data[1][1] ^= data[3][1];
				
				data[2][0] ^= data[1][0];
				data[1][0] ^= data[2][0];
				data[2][0] ^= data[1][0];
				
				data[2][1] ^= data[1][1];
				data[1][1] ^= data[2][1];
				data[2][1] ^= data[1][1];
			}
			else
			{
				data[2][0] ^= data[3][0];
				data[3][0] ^= data[2][0];
				data[2][0] ^= data[3][0];
				
				data[2][1] ^= data[3][1];
				data[3][1] ^= data[2][1];
				data[2][1] ^= data[3][1];
			}
		}
		else if( product[1] > 0 )
		{
			if( product[2] > 0 )
			{
				data[1][0] ^= data[3][0];
				data[3][0] ^= data[1][0];
				data[1][0] ^= data[3][0];
				
				data[1][1] ^= data[3][1];
				data[3][1] ^= data[1][1];
				data[1][1] ^= data[3][1];
				
				data[2][0] ^= data[1][0];
				data[1][0] ^= data[2][0];
				data[2][0] ^= data[1][0];
				
				data[2][1] ^= data[1][1];
				data[1][1] ^= data[2][1];
				data[2][1] ^= data[1][1];
			}
			else
			{
				data[1][0] ^= data[2][0];
				data[2][0] ^= data[1][0];
				data[1][0] ^= data[2][0];
				
				data[1][1] ^= data[2][1];
				data[2][1] ^= data[1][1];
				data[1][1] ^= data[2][1];
			}
		}
		else
		{
			data[1][0] ^= data[3][0];
			data[3][0] ^= data[1][0];
			data[1][0] ^= data[3][0];
				
			data[1][1] ^= data[3][1];
			data[3][1] ^= data[1][1];
			data[1][1] ^= data[3][1];
		}
		
		#ifdef DEBUG
		for( j = 0; j < 4; j++)
		{
			printf( "%d %d    ", data[j][0], data[j][1]);
		}
		#endif
		
		for( j = 0; j < 4; j++)
		{
			len[j] = ( data[j][0] - data[ (j+1)%4 ][0] ) * ( data[j][0] - data[ (j+1)%4 ][0] ) + ( data[j][1] - data[ (j+1)%4 ][1] ) * ( data[j][1] - data[ (j+1)%4 ][1] );
		}
		
		len[4] = ( data[0][0] - data[2][0] ) * ( data[0][0] - data[2][0] ) + ( data[0][1] - data[2][1] ) * ( data[0][1] - data[2][1] );
		len[5] = ( data[1][0] - data[3][0] ) * ( data[1][0] - data[3][0] ) + ( data[1][1] - data[3][1] ) * ( data[1][1] - data[3][1] );
		
		isRightAngle = 0, isEqualSide = 0;
		
		if( len[0] + len[1] == len[4] && len[2] + len[3] == len[4] && len[0] + len[3] == len[5] )
		{
			isRightAngle = 1;
		}
		
		if( len[0] == len[1] && len[1] == len[2] && len[2] == len[3] )
		{
			isEqualSide = 1;
		}
		
		if( isRightAngle )
		{
			if( isEqualSide )
			{
				printf( "square\n");
			}
			else
			{
				printf( "rectangle\n");
			}
		}
		else if( isEqualSide )
		{
			printf( "diamond\n");
		}
		else
		{
			printf( "other\n");
		}
	}
	
	return 0;
}
