#include <iostream>
using namespace std;

char temp[20] = {0};

void runBin( int n, int i)
{
	if( i == n)
	{
		temp[i] = '\0';
		cout << temp << endl;
	}
	else
	{
		temp[i] = '0';
		runBin( n, i+1);
		
		temp[i] = '1';
		runBin( n, i+1);
	}
	return;
}

int main( void)
{
	int n = 0, i = 0;
	
	while( cin >> n)
	{
		runBin( n, 0);
	}
	
	return 0;
}
