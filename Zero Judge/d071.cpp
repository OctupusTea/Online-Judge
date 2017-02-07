#include <iostream>
using namespace std;
int main(void)
{
	int year = 0;
	while( cin >> year)
	{
		if( year % 4 == 0)
		{
			if( year % 100 == 0)
			{
				if( year % 400 == 0)
				{
					cout << "a leap year\n";
				}
				else
				{
					cout << "a normal year\n";
				}
			}
			else
			{
				cout << "a leap year\n";
			}
		}
		else
		{
			cout << "a normal year\n";
		}
	}
	return 0;
}

