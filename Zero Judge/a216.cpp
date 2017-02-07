#include<iostream>
#include<string.h>
using namespace std;

unsigned long long int f(int);
unsigned long long int g(int);

int main(void)
{
    int n = 0;
    while( cin >> n)
    {
        cout << f(n) << " " << g(n) <<endl;
    }
    return 0;
}

unsigned long long int f(int i)
{
    unsigned long long int tmp = i;
    tmp = ( tmp + 1 ) * tmp / 2;
    return tmp;
}

unsigned long long int g(int i)
{
    unsigned long long int tmp = i;
    if( i == 1)
    {
        tmp = 1;
    }
    else
    {
        tmp = f(i) + g(i-1);
    }
    return tmp;
}
