#include <iostream>
using namespace std;
int main( void)
{
	unsigned n = 0;
	while( cin >> n)
	{
		if( n % 2 == 0)
		{
			cout << n << endl;
		}
		else
		{
			cout << n-1 << endl;
		}
	}
	return 0;
}
