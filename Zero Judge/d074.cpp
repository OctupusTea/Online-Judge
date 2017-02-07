#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, i = 0, tmp = 0, max = 0;
    while( cin >> n)
    {
        for( i=0; i<n; i++)
        {
            cin >> tmp;
            if( tmp > max)
            {
                max = tmp;
            }
        }
        cout << max << endl;
    }
    return 0;
}
