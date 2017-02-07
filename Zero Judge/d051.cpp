#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
int main (void)
{
	int n = 0;
	double ans = 0.0;
	while( cin >> n)
	{
		ans = ( (double)n - 32.0 ) / 9.0 * 5.0;
		cout << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}

