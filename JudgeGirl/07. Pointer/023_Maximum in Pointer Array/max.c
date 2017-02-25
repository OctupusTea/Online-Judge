#include "max.h"
 
int max( int *iptr[], int n)
{
    int i = 0, maxN = **iptr;
 
    for( i = 1; i < n; i++)
    {
        if( **( iptr+i) > maxN )
        {
            maxN = **(iptr+i);
        }
    }
 
    return maxN;
}