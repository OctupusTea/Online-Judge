#include <iostream>
using namespace std;

int main( void)
{
	int n = 0;
	int t[5][5] = {0};
	int c[8] = {0};
	int i = 0, j = 0;
	bool inTime = true;
	
	while( cin >> n)
	{
		inTime = true;
		for( i = 0; i < 4; i++)
		{
			cin >> t[i][i+1];
		}
		
		for( i = 0; i < 3; i++)
		{
			t[i][i+2] = t[i][i+1] + t[i+1][i+2];
		}
		
		for( i = 0; i < 2; i++)
		{
			t[i][i+3] = t[i][i+1] + t[i+1][i+3];
		}
		
		for( i = 0; i < 1; i++)
		{
			t[i][i+4] = t[i][i+2] + t[i+2][i+4];
		}
		
		for( i = 0; i < 8; i++)
		{
			cin >> c[i];
		}
		
		for( i = 0; i < 7; i++)
		{
			if( c[i] < c[i+1])
			{
				if( t[c[i]-1][c[i+1]-1] > n)
				{
					inTime = false; 
				}
			}
			else
			{
				if( t[c[i+1]-1][c[i]-1] > n)
				{
					inTime = false; 
				}
			}
		}
		
		if( inTime)
		{
			cout << "yes\n";
		} 
		else
		{
			cout << "no\n";
		}
	}
	
	return 0;
}
