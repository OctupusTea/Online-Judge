#include <iostream>
using namespace std;
void convert(int);
int main(void)
{
	int dat = 0, i = 0;
	while( cin >> dat)
	{
		convert(dat);
		cout<<endl;
	}
	return 0;
}
void convert(int dat)
{
	if(dat>1)
	{
		int tmp = dat % 2;
		dat /= 2;
		convert(dat);
		cout<<tmp;
	}
	else
	{
		cout<<dat;
	}
}

