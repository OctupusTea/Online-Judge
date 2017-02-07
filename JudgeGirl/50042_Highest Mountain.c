#include <stdio.h>
 
int main( void)
{
    int hight1 = 0, col1 = 0;
    int hight2 = 0, col2 = 0;
    int hight = 0, row = 0, col = 0;
    int m = 0, n = 0, i = 0, j = 0;
    int temp = 0;
 
    scanf( "%d%d", &n, &m);
 
    for( i = 0; i < n; i++)
    {
        hight1 = 0;
        col1 = 0;
 
        hight2 = 0;
        col2 = 0;
 
        for( j = 0; j < m; j++)
        {
            scanf( "%d", &temp);
 
            if( temp >= hight2)
            {
                if( temp >= hight1)
                {
                    hight2 = hight1;
                    col2 = col1;
 
                    hight1 = temp;
                    col1 = j;
 
                    if( temp >= hight)
                    {
                        hight = temp;
                        row = i;
                        col = j;
                    }
                }
                else
                {
                    hight2 = temp;
                    col2 = j;
                }
            }
        }
        printf( "%d %d\n", col1+1, col2+1);
    }
 
    printf( "%d %d", row+1, col+1);
 
    return 0;
}
