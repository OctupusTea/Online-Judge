#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    char dat[15] = {0};
    int n = 0, i = 0, j = 0, len = 0;
    unsigned int product = 1; 
    while( cin >> n)
    {
        for( i = 0; i<n; i++)
        {
            cin >> dat;
            product = 1;
            len = strlen( dat);
            for( j = 0; j<len; j++)
            {
                product *= ( dat[j] - 48);
            }
            cout << product << endl;
        }
    }
    return 0;
}
