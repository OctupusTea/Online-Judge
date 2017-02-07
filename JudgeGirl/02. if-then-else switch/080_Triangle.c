#include<stdio.h>
int main(void)
{
    int n = 0, i = 0;
    int a = 0, b = 0, c = 0;
    int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    
    scanf( "%d", &n);
    
    for( i = 0; i < n; i++)
    {
    	scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    	
		a = ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
    	b = ( x3 - x2 ) * ( x3 - x2 ) + ( y3 - y2 ) * ( y3 - y2 );
    	c = ( x1 - x3 ) * ( x1 - x3 ) + ( y1 - y3 ) * ( y1 - y3 );
    	
		if( a == b || b == c || c == a )
    	{
    		printf( "isosceles\n");
    	}
    	else if( a + b > c && b + c > a && c + a > b)
    	{
      	 	printf( "acute\n");
    	}
    	else if( a + b == c || b + c == a || c + a == b)
    	{
        	printf( "right\n");
    	}
    	else
    	{
        	printf( "obtuse\n");
    	}
    }
	
	return 0;
}
