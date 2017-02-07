#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int weight = 0;
    while( cin >> weight)
    {
        cout << weight - ( weight > 50 ) << endl;
    }
    return 0;
}
