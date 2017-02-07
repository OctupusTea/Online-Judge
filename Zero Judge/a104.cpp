#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, dat[1000] = {0}, i = 0, j = 0;
    while( cin >> n)
    {
        for( i=0; i<n; i++)
        {
            cin >> dat[i];
        }
        for( i=0; i<n; i++)
        {
            for( j=i+1; j<n; j++)
            {
                if( dat[i] > dat[j])
                {
                    dat[i] ^= dat[j];
                    dat[j] ^= dat[i];
                    dat[i] ^= dat[j];
                }
            }
        }
        for( i=0; i<n; i++)
        {
            cout << dat[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
