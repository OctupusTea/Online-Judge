#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int a = 0;
    while( cin >> a)
    {
        cout << 890 - 890 * (a<=5) - 300 * ( (a>=6) && (a<=11) ) - 100 * ( (a>=12) && (a<=17) ) - 491 * (a>=60) << endl;
    }
    return 0;
}
