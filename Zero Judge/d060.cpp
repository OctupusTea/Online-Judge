#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	int m = 0;
	while( cin >> m)
	{
		cout << (85 - m) % 60 << endl;
	}
	return 0;
}

