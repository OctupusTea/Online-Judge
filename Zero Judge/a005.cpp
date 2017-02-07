#include <iostream>
using namespace std;
int main(void)
{
	int n = 0, i = 0, j = 0;
	int t[20][5] = {0}, tmp = 0;
	cin >> n;
	for( i=0; i<n; i++)
	{
		for( j=0; j<4; j++)
		{
			cin >> t[i][j];
		}
	}
	for( i=0; i<n; i++)
	{
		tmp = t[i][1] - t[i][0];
		for( j=2; j<4; j++)
		{
			if( t[i][j] - t[i][j-1] != tmp)
			{
				t[i][4] = t[i][3] * t[i][3] / t[i][2];
				tmp = -1;
				break;
			}
		}
		if( tmp != -1)
		{
			t[i][4] = t[i][3] * 2 - t[i][2];
		}
	}
	for( i=0; i<n; i++)
	{
		for( j=0; j<5; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

