#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main(void)
{
    int a = 0, b = 0, i = 0, j = 0, sum = 0, n = 0;
    int sqa = 0, sqb = 0;
    while( cin >> n)
    {
        for( i=0; i<n; i++)
        {
            sum = 0;
            cin >> a >> b;
            cout << "Case " << i+1 << ": ";
            sqa = (int)sqrt(a);
            if( a == sqa * sqa)
            {
                sqa--;
            }
            sqa++;
            sqb = (int)sqrt(b);
            for( j=sqa; j<=sqb; j++)
            {
                sum += j*j;
            }
            cout << sum << endl;
        }
    }
    return 0;
}
