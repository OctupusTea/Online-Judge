#include <iostream>
using namespace std;

int main( void)
{
	int n = 0, temp = 0;
	int data[100] = {0};
	int i = 0, j = 0;
	
	while( cin >> n)
	{
		for( i = 0; i < n; i++)
		{
			cin >> data[i];
			cout << data[i] << " ";
		}
		cout << endl;
		for( i = 0; i < n-1; i++)
		{
			for( j = 0; j < (n-i)/2; j++)
			{
				temp = data[n-i-j-1];
				data[n-i-j-1] = data[j];
				data[j] = temp;
			}
			for( j = 0; j < n-i-1; j++)
			{
				cout << data[j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
