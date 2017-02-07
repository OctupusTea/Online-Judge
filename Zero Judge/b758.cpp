#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int h = 0, m = 0;
    while( cin >> h >> m)
    {
        m += 30;
        if( m >= 60)
        {
            h++;
            m -= 60;
        }
        h += 2;
        if( h >= 24)
        {
            h -= 24;
        }
        if( h < 10)
        {
            cout << "0" << h << ":";
        }
        else
        {
            cout << h << ":";
        }
        if( m < 10)
        {
            cout << "0" << m << endl;
        }
        else
        {
            cout << m << endl;
        }
    }
    system("pause");
    return 0;
}
