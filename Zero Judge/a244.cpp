#include <iostream>
using namespace std;

int main( void)
{
	int N = 0, a = 0;
	long long b = 0, c = 0, ans = 0;
	
	cin >> N;
	
	for( int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		
		switch(a)
		{
			case 1:
				cout << b + c << endl;
				break;
			case 2:
				cout << b - c << endl;
				break;
			case 3:
				cout << b * c << endl;
				break;
			case 4:
				cout << b / c << endl;
				break;
		}
	}
	
	return 0;
}
