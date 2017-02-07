#include <iostream>
using namespace std;
int main(void)
{
	int m = 0, n = 0, i = 0, j = 0;
	int dat[100][100];
	while( cin >> m >> n)
	{
		for( i=0; i<m; i++)
		{
			for( j=0; j<n; j++)
			{
				cin >> dat[i][j];
			}
		}
		for( i=0; i<n; i++)
		{
			for( j=0; j<m; j++)
			{
				cout << dat[j][i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

