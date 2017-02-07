#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char dat[1000] = {0};
	int i = 0;
	while( cin.getline(dat,999) )
	{
		for( i=0; i<strlen(dat); i++)
		{
			dat[i] -= 7;
		}
		cout << dat << endl;
	}
	return 0;
}

