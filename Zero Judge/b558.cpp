#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0;
    while( cin >> n)
    {
        if( n == 1)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << (n-1)*n/2+1 << endl;
        }
    }
    system("pause");
    return 0;
}
