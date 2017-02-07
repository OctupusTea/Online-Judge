#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0, i = 0, tmp = 0;
    long long int sum = 0;
    while( cin >> n)
    {
        sum = 0;
        for( i=0; i<n; i++)
        {
            cin >> tmp;
            sum += tmp;
        }
        if( sum > 59 * n)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}
