#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	int i = 0;
	while( cin >> i)
	{
		if( i % 2 == 0)
		{
			cout << "Even" ;
		}
		else
		{
			cout << "Odd" ;
		}
		cout << endl;
	}
	return 0;
}

