#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int a = 0, b = 0, sum = 0, i = 0;
    while( cin >> a >> b)
    {
        for( i=a; i<=b; i++)
        {
            if( i%2 == 0)
            {
                sum += i;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
