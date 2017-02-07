#include<iostream>
using namespace std;
int main(void)
{
    int hh = 0, mm = 0;
    while( cin >> hh >> mm)
    {
        if( hh <= 6 || ( hh == 7 && mm < 30 ) || hh >= 17)
        {
            cout << "Off School\n";
        }
        else
        {
            cout << "At School\n";
        }
    }
    return 0;
}
