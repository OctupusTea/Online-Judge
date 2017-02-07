#include <iostream>
#include <string.h>
using namespace std;
int main( void)
{
	char data[210] = {0};
	int len = 0;
	int sum = 0;
	bool succ = true;
	
	cin >> data;
	len = strlen( data);
	
	while( len != 1 || data[0] != '0')
	{
		for( int i = 0; i < len; i++)
		{
			if( data[i] >= 65 && data[i] <= 90)
			{
				sum += ( data[i] - 64 );
			}
			else if( data[i] >= 97 && data[i] <= 122)
			{
				sum += ( data[i] - 96 );
			}
			else
			{
				cout << "Fail\n";
				succ = false;
				break;
			}
		}
		
		if( succ)
		{
			cout << sum << endl;
		}
		
		sum = 0;
		succ = true;
		cin >> data;
		len = strlen( data);
	}
	return 0;
}
