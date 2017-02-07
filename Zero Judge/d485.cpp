#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int a = 0, b = 0;
    while( cin >> a >> b)
    {
        cout << (b-a) / 2 + 1 -(a%2)*(b%2) << endl;
    }
    return 0;
}
