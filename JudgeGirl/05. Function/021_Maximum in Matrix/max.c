#include "max.h"
 
int max( int data[5][5] )
{
    int ans = -2147483648;
    int i = 0, j = 0;
 
    for( i = 0; i < 5; i++ )
    {
        for( j = 0; j < 5; j++)
        {
            if( data[i][j] > ans )
            {
                ans = data[i][j];
            }
        }
    }
 
    return ans;
}