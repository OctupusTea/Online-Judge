#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	char dat[1000] = {0};
	int i = 0, j = 0, len = 0;
	while( cin.getline(dat,999) )
	{
		len = strlen(dat);
		for( i=0; i<len; i++)
		{
			for( j=i+1; j<len; j++)
			{
				if( dat[j] != dat[i] )
				{
					break;
				}
			}
			if( j-i > 2)
			{
				cout << j-i << dat[i];
				i = j-1;
			}
			else
			{
				cout << dat[i];
			}
		}
		cout << endl;
	}
	return 0;
}

