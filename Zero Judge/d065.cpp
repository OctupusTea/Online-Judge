#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	int a = 0, b = 0, c = 0, max = 0;
	while( cin >> a >> b >> c)
	{
		max = a;
		if( b > max)
		{
			max = b;
		}
		if( c > max)
		{
			max = c;
		}
		cout << max << endl;
	} 
	return 0;
}

