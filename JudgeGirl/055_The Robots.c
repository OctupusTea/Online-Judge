#include <stdio.h>
#define x
int main( void)
{
    int m = 0, n = 0, i = 0, j = 0, explode = 0;
    int x1 = 0, y1 = 0, e1 = 0, n1 = 0, f1 = 0, dir1 = 0, c1 = 0;
    int x2 = 0, y2 = 0, e2 = 0, n2 = 0, f2 = 0, dir2 = 1, c2 = 0;
 
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);
#ifdef DEBUG
    printf( "time 0:\n");
    printf( "pos1:( %d , %d ), dir1: %d\n", x1, y1, dir1);
    printf( "pos2:( %d , %d ), dir2: %d\n\n", x2, y2, dir2);
#endif
    for( i = 0; f1 > 0 || f2 > 0; i++)
    {
        if( f1 > 0)
        {
            if( dir1)
            {
                x1++;
                c1++;
                x1 %= m;
                if( c1 == e1)
                {
                    if( n1 != 0)
                    {
                        dir1 = 0;
                        c1 = 0;
                    }
                    else
                    {
                        c1 = 0;
                    }
                }
            }
            else
            {
                y1++;
                c1++;
                y1 %= n;
                if( c1 == n1)
                {
                    if( e1 != 0)
                    {
                        dir1 = 1;
                        c1 = 0;
                    }
                    else
                    {
                        c1 = 0;
                    }
                }
            }
            f1--; 
        }
 
        if( f2 > 0)
        {
            if( dir2)
            {
                x2++;
                c2++;
                x2 %= m;
                if( c2 == e2)
                {
                    if( n2 != 0)
                    {
                        dir2 = 0;
                        c2 = 0;
                    }
                    else
                    {
                        c2 = 0;
                    }
                }
            }
            else
            {
                y2++;
                c2++;
                y2 %= n;
                if( c2 == n2)
                {
                    if( e2 != 0)
                    {
                        dir2 = 1;
                        c2 = 0;
                    }
                    else
                    {
                        c2 = 0;
                    }
                }
            }
            f2--;
        }
#ifdef DEBUG
        printf( "time %d:\n", i+1);
        printf( "pos1:( %d , %d ), dir1: %d\n", x1, y1, dir1);
        printf( "pos2:( %d , %d ), dir2: %d\n\n", x2, y2, dir2);
#endif
        if( x1 == x2 && y1 == y2)
        {
            printf( "robots explode at time %d", i+1);
            explode = 1;
            break;
        }
    }
 
    if( explode == 0)
    {
        printf( "robots will not explode");
    }
 
    return 0;
}
