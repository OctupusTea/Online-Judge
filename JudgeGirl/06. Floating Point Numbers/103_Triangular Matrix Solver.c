#include <stdio.h>
 
int main( void)
{
    int n = 0, i = 0, j = 0;
    double matrix[16][16] = {0.0};
    double vecX[16] = {0.0};
    double vecY[16] = {0.0};
 
    scanf( "%d", &n );
 
    for( i = 0; i < n; i++)
    {
        for( j = 0; j < n; j++)
        {
            scanf( "%lf", &matrix[i][j] );
        }
    }
 
    for( i = 0; i < n; i++)
    {
        scanf( "%lf", &vecY[i] );
    }
 
    for( i = n-1; i >= 0; i--)
    {
        vecX[i] = vecY[i];
        for( j = n-1; j > i; j--)
        {
            vecX[i] -= vecX[j] * matrix[i][j];
        }
        vecX[i] /= matrix[i][j];
    }
 
    for( i = 0; i < n; i++)
    {
        printf( "%lf\n", vecX[i] ); 
    }
 
    return 0;
}