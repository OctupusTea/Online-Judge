#include <iostream>
using namespace std;
int main(void)
{
	int m = 0, d = 0, s = 0;
	while( cin >> m >> d)
	{
		s = ( m*2 + d) % 3;
		if( s == 0)
		{
			cout << "´¶³q\n"; 
		}
		else if ( s == 1)
		{
			cout << "¦N\n";	
		} 
		else
		{
			cout << "¤j¦N\n";
		}
	}
	return 0;
}

