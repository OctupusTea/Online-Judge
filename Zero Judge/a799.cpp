#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    long long n = 0;
    while( cin >> n)
    {
        cout << n * (n>=0) - n * (n<0) << endl;
    }
    system("pause");
    return 0;
}
