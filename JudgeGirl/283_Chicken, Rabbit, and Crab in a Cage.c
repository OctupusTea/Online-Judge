#include<stdio.h>
int main(void)
{
    int count = 0, feet = 0, tail = 0;
    int chicken = 0, rabbit = 0, crab = 0;
    scanf( "%d%d%d", &count, &feet, &tail);
    if( tail > count)
    {
        printf( "0\n");
    }
    else
    {
        crab = count - tail;
        count -= crab;
        feet -= crab * 8;
        if( feet < 0 || feet % 2 == 1)
        {
            printf( "0\n");
        }
        else
        {
            chicken = ( 4 * count - feet ) / 2;
            rabbit = ( feet - 2 * count ) / 2;
            printf( "%d\n%d\n%d", chicken, rabbit, crab);
        }
    }
    return 0;
}
