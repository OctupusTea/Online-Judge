#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	int n = 0;
	while( cin >> n)
	{
		cout << (n+9) % 24 << endl;
	} 
	return 0;
}

