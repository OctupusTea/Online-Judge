#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, i = 0;
    while( cin >> n)
    {
        for( i = 1; i < n; i++)
        {
            if( i % 7 != 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
