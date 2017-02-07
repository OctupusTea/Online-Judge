#include <iostream>
#include <string.h>
using namespace std;

int main ( void)
{
	char data[10010] = {0};
	int len = 0;
	int sum = 0, i = 0;
	
	while( cin >> data)
	{
		len = strlen( data);
		sum = 0;
		
		if( data[0] == '-')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}
		
		for( ; i < len; i++)
		{
			sum += ( data[i] - 48);
		}
		
		if( sum % 3 == 0)
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
