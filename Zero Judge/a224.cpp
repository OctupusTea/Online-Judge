#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    char dat[1001] = {0};
    int count[26] = {0};
    int i = 0, len = 0;
    int odd = 0;
    bool brk = false;
    while( cin >> dat)
    {
        for( i = 0; i < 26 ; i++)
        {
            count[i] = 0;
        }
        odd = 0;
        brk = false;
        len = strlen(dat);
        for( i = 0; i < len ; i++)
        {
            if( dat[i] >= 65 && dat[i] <= 90)
            {
                count[ dat[i]-64 ]++;
            }
            else if( dat[i] >= 97 && dat[i] <= 122)
            {
                count[ dat[i]-96 ]++;
            }
        }
        for( i = 0; i<26; i++)
        {
            if( count[i] % 2 == 1)
            {
                odd++;
            }
            if( odd >= 2)
            {
                cout << "no...\n";
                brk = true;
                break;
            }
        }
        if( !brk)
        {
            cout << "yes !\n";
        }
    }
    return 0;
}
