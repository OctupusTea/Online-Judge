#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, m = 0, i = 0;
    int tmp = 0;
    
    while( cin >> n >> m)
    {
        tmp = 0;
        for( i = n; ; i++)
        {
            tmp += i;
            if( tmp > m)
            {
                cout << i - n + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
