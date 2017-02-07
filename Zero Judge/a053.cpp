#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	int n = 0;
	while( cin >> n)
	{
		if( n <= 10)
		{
			cout << n * 6;
		}
		else if( n <= 20)
		{
			cout << n * 2 + 40;
		}
		else if ( n <= 40)
		{
			cout << n + 60;
		}
		else
		{
			cout << 100;
		}
		cout << endl;
	}
	return 0;
}

