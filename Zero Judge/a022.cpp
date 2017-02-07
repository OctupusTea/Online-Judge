#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char dat[1000] = {0};
	int i = 0, len = 0;
	bool re = true;
	while( cin.getline(dat,999) )
	{
		re = true;
		len = strlen(dat);
		for( i=0; i<len/2+1 ; i++)
		{
			if(dat[i] != dat[len-1-i])
			{
				re = false;
				break;
			}
		}
		if(re)
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

