#include <stdio.h>

int main( void)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	int index = 0, i = 0, j = 0, k = 0, r = 0, brk = 0;
	int num[1280] = {0};
		
	scanf( "%d%d%d", &a, &b, &c);
	
	/*for( d = -100000; d <= 100000; d++)
	{
		if( a*d*d - d*d*d - b*d + c == 0 )
		{
			printf( "%d ", d);
			break;
		}
	}
	
	for( e = d; e <= 100000; e++)
	{
		if( e*e - (a-d)*e + b + d*(d-a) == 0 )
		{
			printf( "%d ", e);
			break;
		}
	}
	
	for( f = e; f <= 100000; f++)
	{
		if( a - d - e - f == 0 )
		{
			printf( "%d", f);
			break;
		}
	}*/
	
	if( c == 0)
	{
		if( b == 0)
		{
			if( a >= 0)
			{
				printf( "0 0 %d", a);
			}
			else
			{
				printf( "%d 0 0", a);
			}
		}
		else
		{
			for( r = 0; r < abs(b); r++)
			{
				if( (r+1)*(r+1) > abs(b))
				{
					break;
				}
			}
				
			for( i = 1; i <= r; i++)
			{
				if( abs(b) % i == 0)
				{
					num[ index ] = i;
					index++;
				}
			}
			
			for( i = index; i < 2 * index; i++)
			{
				num[ i ] = abs(b) / num[ 2 * index - 1 - i];
			}
			
			index *= 2;
			
			for( i = 0; i < index; i++)
			{
				num[ i+index+1 ] = num[i];
				num[i] *= -1;
			}
			
			for( i = 0; i < index / 2; i++)
			{
				num[i] ^= num[ index-i-1 ];
				num[ index-i-1 ] ^= num[i];
				num[i] ^= num[ index-i-1];
			}
			
			index *= 2;
			index += 1;
			
			/*for( i = 0; i < index; i++)
			{
				printf( "%d\n", num[i]);
			}*/
			
			for( i = 0; i < index; i++)
			{
				for( j = i; j < index; j++)
				{
					//printf( " + + = %d\n + * = %d\n * * = %d\n\n", num[i] + num[j] + num[k], num[i] * num[j] + (num[i] + num[j]) * num[k], num[i] * num[j] * num[k] );
					if( num[i] + num[j] == a && num[i] * num[j] == b )
					{
						if( num[i] >= 0)
						{
							printf( "0 %d %d", num[i], num[j]);
						}
						else if( num[j] <= 0)
						{
							printf( "%d %d 0", num[i], num[j]);
						}
						else
						{
							printf( "%d 0 %d", num[i], num[j]);
						}
						brk = 1;
						break;
					}
				}
				if( brk)
				{
					break;
				}
			}
		}
	}
	else
	{
		for( r = 0; r < abs(c); r++)
		{
			if( (r+1)*(r+1) > abs(c))
			{
				break;
			}
		}
			
		for( i = 1; i <= r; i++)
		{
			if( abs(c) % i == 0)
			{
				num[ index ] = i;
				index++;
			}
		}
		
		for( i = index; i < 2 * index; i++)
		{
			num[ i ] = abs(c) / num[ 2 * index - 1 - i];
		}
		
		index *= 2;
		
		for( i = 0; i < index; i++)
		{
			num[ i+index+1 ] = num[i];
			num[i] *= -1;
		}
		
		for( i = 0; i < index / 2; i++)
		{
			num[i] ^= num[ index-i-1 ];
			num[ index-i-1 ] ^= num[i];
			num[i] ^= num[ index-i-1];
		}
		
		index *= 2;
		index += 1;
		
		/*for( i = 0; i < index; i++)
		{
			printf( "%d\n", num[i]);
		}*/
		
		for( i = 0; i < index; i++)
		{
			for( j = i; j < index; j++)
			{
				for( k = j; k < index; k++)
				{
					//printf( " + + = %d\n + * = %d\n * * = %d\n\n", num[i] + num[j] + num[k], num[i] * num[j] + (num[i] + num[j]) * num[k], num[i] * num[j] * num[k] );
					if( num[i] + num[j] + num[k] == a && num[i] * num[j] + (num[i] + num[j]) * num[k] == b && num[i] * num[j] * num[k] == c)
					{
						printf( "%d %d %d", num[i], num[j], num[k]);
						brk = 1;
						break;
					}
				}
				if( brk)
				{
					break;
				}
			}
			if( brk)
			{
				break;
			}
		}
	}
	
	return 0;
}
