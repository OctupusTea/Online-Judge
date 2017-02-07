#include <iostream>
using namespace std;

int main( void)
{
	int n = 0;
	
	while( cin >> n)
	{
		cout << 1 + ( n * n + 5 ) * n / 6 << endl;
	}
	
	return 0;
}
