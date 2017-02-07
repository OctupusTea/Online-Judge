#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char dat[100] = {0};
	int len = 0, i = 0, tmp = 0;
	while(cin.getline(dat,99))
	{
		len = strlen(dat);
		for( i=len-1; i>=0; i--)
		{
			if( dat[i] != '0')
			{
				tmp = i;
				break;
			}
		}
		for( i=tmp; i>=0; i--)
		{
			cout<<dat[i];
		}
		cout<<endl;
	}
	return 0;
}

