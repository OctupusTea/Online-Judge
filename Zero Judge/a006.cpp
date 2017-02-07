#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int a = 0, b = 0, c = 0, d = 0;
	while( cin >> a >> b >> c)
	{
		d = b * b - 4 * a * c;
		if ( d > 0)
		{
			cout << "Two different roots x1="
		    	 << ( -b + sqrt(d) ) / ( 2 * a)
				 << " , x2="
				 << ( -b - sqrt(d) ) / ( 2 * a)
				 << endl;
		}
		else if ( d == 0)
		{
			cout << "Two same roots x=" << -b / ( a * 2) << endl;
		}
		else
		{
			cout << "No real root\n";
		}
	}
	return 0;
}

