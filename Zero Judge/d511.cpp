#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int a[5][3] = {0}, i = 0, j = 0, ans = 0;
    while( cin >> a[0][0])
    {
        ans = 0;
        for( i=0; i<5; i++)
        {
            for( j=0; j<3; j++)
            {
                if( i!=0 || j !=0)
                {
                    cin >> a[i][j];
                }
            }
            if( a[i][0] + a[i][1] > a[i][2] && a[i][1] + a[i][2] > a[i][0] && a[i][2] + a[i][0] > a[i][1] )
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
