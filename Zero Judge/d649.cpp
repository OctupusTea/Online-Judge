#include <iostream>
using namespace std;

int main( void)
{
	int n = 0, i = 0, j = 0;
	
	cin >> n;
	
	while( n != 0 )
	{
		for( i = 0; i < n; i++)
		{
			for( j = 0; j < n-i-1; j++)
			{
				cout << "_";
			}
			for( j = 0; j < i+1; j++)
			{
				cout << "+";
			}
			cout << endl;
		}
		
		cin >> n;
	}
	
	return 0;
}
