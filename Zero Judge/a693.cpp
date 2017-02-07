#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, m = 0;
    int dat[100000] = {0};
    int i = 0, j = 0;
    int l = 0, r = 0;
    int temp = 0;
    while( cin >> n >> m)
    {
        cin >> dat[0];
        for( i = 1; i < n; i++)
        {
            cin >> temp;
            dat[i] = dat[i-1] + temp;
        }
        for( i = 0; i < m; i++)
        {
            cin >> l >> r;
            if( l == 1)
            {
                cout << dat[r-1] << endl;
            }
            else
            {
                cout << dat[r-1] - dat[l-2] << endl; 
            }
        }
    }
    system("pause");
    return 0;
}
