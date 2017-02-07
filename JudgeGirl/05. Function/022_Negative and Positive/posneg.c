#include "posneg.h"
 
void posneg( int data[5][5], int result[2] )
{
    int i = 0, j = 0;
    result[0] = 0, result[1] = 0;
 
    for( i = 0; i < 5; i++)
    {
        for( j = 0; j < 5; j++)
        {
            if( data[i][j] > 0 )
            {
                result[1]++;
            }
            else if( data[i][j] < 0 )
            {
                result[0]++;
            }
        }
    }
}