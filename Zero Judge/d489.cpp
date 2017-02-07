#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main(void)
{
    unsigned long long int a = 0, b = 0, c = 0, s = 0;
    unsigned long long int ans = 0;
    while( cin >> a >> b >> c)
    {
        s = a + b + c;
        ans = s*(s-2*a)*(s-2*b)*(s-2*c)/16;
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
