#include <stdio.h>
//#define DEBUG
//#define PRINT_N

int main( void)
{
    int data[100] = {0};
    int n = 0, i = 0, j = 0, k = 0;
    int palindrome[100][2] = {0};
    int iLeft = 0, iRight = 0, jLeft = 0, jRight = 0;
    int maxLeft = 0, maxRight = 0;
    int brk = 0;
 
    #ifndef DEBUG
    while( ~scanf( "%d", &data[n++] ) );
    	#ifdef PRINT_N
    	printf( "%d\n\n", n);
    	#endif
    	n--;
    #endif
 
    #ifdef DEBUG
    scanf( "%d", &n);
    for( i = 0; i < n; i++)
    {
        scanf( "%d", &data[i] );
    }
    printf( "  ");
    #endif
 
    for( i = 0; i < n; i++)
    {
        for( j = 0; j <= i && j < n - i; j++)
        {
            if( data[i+j] == data[i-j] )
            {
                palindrome[i][1] = j;
            }
            else
            {
                break;
            }
        }
        #ifdef DEBUG
        printf( "%d ", palindrome[i][1]);
        #endif
    }
 
    #ifdef DEBUG
    printf( "\n  ");
    #endif

    for( i = 0; i < n - 1; i++)
    {
        for( j = 0; j <= i && j < n - i; j++)
        {
            if( data[i+j+1] == data[i-j] )
            {
                palindrome[i][0] = j+1;
            }
            else
            {
                break;
            }
        }
        #ifdef DEBUG
        printf( "%d ", palindrome[i][0]);
        #endif
    }
 
    #ifdef DEBUG
    printf( "\n");
    #endif
 
    for( i = 0; i < n; i++)
    {
        for( j = i + 1; j < n; j++)
        {
            /*if( palindrome[i][1] + palindrome[j][1] == j - i - 1 && 2 * ( palindrome[i][1] + palindrome[j][1] ) + 1 >= right - left )
            {
                left = i - palindrome[i][1];
                right = j + palindrome[j][1];
                #ifdef DEBUG
                printf( "find! 1 " );
                #endif
            }
            if( palindrome[i][0] + palindrome[j][0] == j - i && 2 * ( palindrome[i][0] + palindrome[j][0] ) - 1 >= right - left )
            {
                left = i - palindrome[i][0] + 1;
                right = j + palindrome[j][0];
                #ifdef DEBUG
                printf( "find! 2 " );
                #endif
            }
            if( palindrome[i][0] + palindrome[j][1] == j - i - 1 && 2 * ( palindrome[i][0] + palindrome[j][1] ) >= right - left )
            {
                left = i - palindrome[i][0] + 1;
                right = j + palindrome[j][1];
                #ifdef DEBUG
                printf( "find! 3 " );
                #endif
            }
            if( palindrome[i][1] + palindrome[j][0] == j - i && 2 * ( palindrome[i][1] + palindrome[j][0] ) >= right - left )
            {
                left = i - palindrome[i][1];
                right = j + palindrome[j][0];
                #ifdef DEBUG
                printf( "find! 4 " );
                #endif
            }
            #ifdef DEBUG
            printf( "%d, %d, %d, %d\n", i, j, left, right);
            #endif
			*/
			if( palindrome[i][1] + palindrome[j][1] >= j - i - 1 )
            {
            	iLeft = i - palindrome[i][1];
            	iRight = i + palindrome[i][1];
            	jLeft = j - palindrome[j][1];
            	jRight = j + palindrome[j][1];
            	
            	while( iRight >= jLeft )
            	{
            		iRight--;
            		iLeft++;
        			if( iRight < iLeft )
        			{
        				brk = 1;
        				break;
        			}
            	}
        		
				if( !brk )
				{
					if( jRight - iLeft > maxRight - maxLeft )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            	else if( jRight - iLeft == maxRight - maxLeft && jRight > maxRight )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            }
	            else
	            {
	            	brk = 0;
	            }
            }
            if( palindrome[i][0] + palindrome[j][0] >= j - i )
            {
            	iLeft = i - palindrome[i][0] + 1;
            	iRight = i + palindrome[i][0];
            	jLeft = j - palindrome[j][0] + 1;
            	jRight = j + palindrome[j][0];
            	
            	while( iRight >= jLeft )
            	{
            		iRight--;
            		iLeft++;
        			if( iRight < iLeft )
        			{
        				brk = 1;
        				break;
        			}
            	}
        		
				if( !brk )
				{
					if( jRight - iLeft > maxRight - maxLeft )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            	else if( jRight - iLeft == maxRight - maxLeft && jRight > maxRight )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            }
	            else
	            {
	            	brk = 0;
	            }
            }
            if( palindrome[i][0] + palindrome[j][1] >= j - i - 1 )
            {
                iLeft = i - palindrome[i][0] + 1;
            	iRight = i + palindrome[i][0];
            	jLeft = j - palindrome[j][1];
            	jRight = j + palindrome[j][1];
            	
            	while( iRight >= jLeft )
            	{
            		iRight--;
            		iLeft++;
        			if( iRight < iLeft )
        			{
        				brk = 1;
        				break;
        			}
            	}
        		
				if( !brk )
				{
					if( jRight - iLeft > maxRight - maxLeft )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            	else if( jRight - iLeft == maxRight - maxLeft && jRight > maxRight )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            }
	            else
	            {
	            	brk = 0;
	            }
            }
            if( palindrome[i][1] + palindrome[j][0] >= j - i )
            {
                iLeft = i - palindrome[i][1];
            	iRight = i + palindrome[i][1];
            	jLeft = j - palindrome[j][0] + 1;
            	jRight = j + palindrome[j][0];
            	
            	while( iRight >= jLeft )
            	{
            		iRight--;
            		iLeft++;
        			if( iRight < iLeft )
        			{
        				brk = 1;
        				break;
        			}
            	}
        		
				if( !brk )
				{
					if( jRight - iLeft > maxRight - maxLeft )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            	else if( jRight - iLeft == maxRight - maxLeft && jRight > maxRight )
	            	{
	            		maxRight = jRight;
	            		maxLeft = iLeft;
	            	}
	            }
	            else
	            {
	            	brk = 0;
	            }
            }
            #ifdef DEBUG
            printf( "%d, %d, %d, %d\n\n", i, j, maxLeft, maxRight);
            #endif
			
        }
    }
 
    for( i = maxLeft; i < maxRight; i++)
    {
        printf( "%d ", data[i] );
    }
    printf( "%d\n", data[i] );
 
    return 0;
}
