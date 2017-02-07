#include <iostream>
using namespace std;

int main( void)
{
	int n = 0, m = 0, ans = 0;
	int i = 0, j = 0, k = 0;
	int index[2] = {0};
	int data[2][10000] = {0};
	
	cin >> n >> m;
	
	for( i = 0; i < n; i++)
	{
		ans = 0;
		index[0] = 0;
		index[1] = 0;
		
		for( j = 0; j < 2; j++)
		{
			for( k = 0; k < m; k++)
			{
				cin >> data[j][k];
			}
		}
		
		while( index[0] < m && index[1] < m )
		{
			if( data[0][ index[0] ] > data[1][ index[1] ] )
			{
				index[1]++;
			}
			else if( data[0][ index[0] ] < data[1][ index[1] ] )
			{
				index[0]++;
			}
			else
			{
				index[0]++;
				index[1]++;
				ans++;
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}
