#include <stdio.h>
//#define DEBUG
 
int main( void)
{
    int rec[3][4] = {0};
 
    int i = 0, j = 0;
    for( i = 0; i < 3; i++)
    {
        for( j = 0; j < 4; j++)
        {
            scanf( "%d", &rec[i][j] );
        }
    }
 
    int sum = 0;
    for( i = 0; i < 3; i++)
    {
        sum += ( rec[i][0] - rec[i][2] ) * ( rec[i][1] - rec[i][3] );
        #ifdef DEBUG
            printf( "rec [ %d ] : area %d added\n", i, ( rec[i][0] - rec[i][2] ) * ( rec[i][1] - rec[i][3] ) ); 
        #endif
    }
 
 
    for( i = 0; i < 3; i++)
    {
        int left = rec[i][0] > rec[ (i+1)%3 ][0] ? rec[i][0] : rec[ (i+1)%3 ][0];
        int bottom = rec[i][1] > rec[ (i+1)%3 ][1] ? rec[i][1] : rec[ (i+1)%3 ][1];
        int right = rec[i][2] < rec[ (i+1)%3 ][2] ? rec[i][2] : rec[ (i+1)%3 ][2];
        int top = rec[i][3] < rec[ (i+1)%3 ][3] ? rec[i][3] : rec[ (i+1)%3 ][3];
 
        if( left < right && bottom < top )
        {
            sum -= ( left - right ) * ( bottom - top ); 
            #ifdef DEBUG
                printf( "rec [ %d ] & [ %d ] : area %d subtracted\n", i, (i+1)%3, ( left - right ) * ( bottom - top ) ); 
            #endif
        }
    }
 
    int left = rec[0][0], bottom = rec[0][1], right = rec[0][2], top = rec[0][3];
    for( i = 1; i < 3; i++)
    {
        if( rec[i][0] > left )
        {
            left = rec[i][0];
        }
        if( rec[i][1] > bottom )
        {
            bottom = rec[i][1];
        }
        if( rec[i][2] < right )
        {
            right = rec[i][2];
        }
        if( rec[i][3] < top )
        {
            top = rec[i][3];
        }
    }
 
    if( left < right && bottom < top )
    {
        sum += ( left - right ) * ( bottom - top ); 
        #ifdef DEBUG
            printf( "rec [ all ] : area %d added\n",  ( left - right ) * ( bottom - top ) ); 
        #endif
    }
 
    printf( "%d\n", sum);
 
    return 0;
}