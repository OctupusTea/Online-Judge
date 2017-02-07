#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, i = 0, tmp = 0;
    int dat[1000] = {0};
    int a[3] = {0};
    while( cin >> n)
    {
        for( i=0; i<n; i++)
        {
            cin >> dat[i];
            tmp = dat[i]%3;
            a[tmp]++;
        }
        for( i=0; i<3; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
