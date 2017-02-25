//#define DEBUG
 
#ifdef DEBUG
    #include <stdio.h>
#endif
 
int evaluate_f(int *iptr[], int n, int *index)
{
    int i = 0, max = -2147483648, tmp = 0;
 
    for( i = 0; i < n; i++)
    {
        tmp = *( iptr[i] ) * 4 - *( iptr[i] + 1 ) * 6;
        #ifdef DEBUG
            printf( "i = %d, tmp = %d\n", i, tmp);
        #endif
 
        if( tmp > max )
        {
            *index = i;
            max = tmp;
            #ifdef DEBUG
                printf( "i = %d, max = %d\n", i, max);
            #endif
 
        }
    }
 
    return max;
}