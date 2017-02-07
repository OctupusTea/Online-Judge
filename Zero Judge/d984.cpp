#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    char p[3] = {'A','B','C'};
    unsigned int a[3] = {0};
    int min = 0, max = 0;
    int i = 0;
    while( cin >> a[0] >> a[1] >> a[2])
    {
        min = 0;
        max = 0;
        for( i=0; i<3; i++)
        {
            if( a[min] > a[i])
            {
                min = i;
            }
            if( a[max] < a[i])
            {
                max = i;
            }
        }
        a[3-min-max] += a[min];
        a[min] = 0;
        max = 0;
        for( i=0; i<3; i++)
        {
            if( a[i] >= a[max])
            {
                max = i;
            }
        }
        cout << p[max] << endl;
    }
    return 0;
}
