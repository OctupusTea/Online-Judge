#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    long int n = 0, a = 0;
    while( cin >> n)
    {
        a = 0;
        while( n >= 5)
        {
            a += n / 5;
            n /= 5;
        }
        cout << a << endl;
    }
    system("pause");
    return 0;
}
