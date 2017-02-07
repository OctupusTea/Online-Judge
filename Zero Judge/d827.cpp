#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int n = 0;
    while( cin >> n)
    {
        cout << (n/12)*50 + (n%12)*5 << endl;
    }
    return 0;
}
