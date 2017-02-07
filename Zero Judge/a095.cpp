#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, m = 0;
    while( cin >> n >> m)
    {
        if( n == m)
        {
            cout << m << endl;
        }
        else
        {
            cout << m+1 << endl;
        }
    }
    return 0;
}
