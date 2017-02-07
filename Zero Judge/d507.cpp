#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    unsigned int a[3] = {0}, sq[3] = {0}, i = 0;
    while( cin >> a[0] >> a[1] >> a[2])
    {
        for( i=0; i<3; i++)
        {
            sq[i] = a[i] * a[i];
        }
        if( sq[0]+sq[1] > sq[2] && sq[1]+sq[2] > sq[0] && sq[2]+sq[0] > sq[1] )
        {
            cout << "acute triangle\n";
        }
        else if( sq[0]+sq[1] == sq[2] || sq[1]+sq[2] == sq[0] || sq[2]+sq[0] == sq[1] )
        {
            cout << "right triangle\n";
        }
        else
        {
            cout << "obtuse triangle\n";
        }
    }
    return 0;
}
