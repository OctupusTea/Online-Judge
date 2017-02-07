#include <iostream>
#include <string.h>
using namespace std;
int main (void)
{
	char dat[10] = {0};
	int i = 0;
	while( cin.getline(dat,9) )
	{
		for( i=0; i<6; i++)
		{
			cout << ( dat[i+1] - dat[i] > 0 ? dat[i+1] - dat[i] : dat[i] - dat[i+1] );
		}
		cout << endl;
	}
	return 0;
}

