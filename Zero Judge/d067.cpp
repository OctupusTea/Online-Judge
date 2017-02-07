#include <iostream>
using namespace std;
int main(void)
{
	int year[2] = {0}, ans = 0, i = 0;
	while( cin >> year[0] >> year[1])
	{
		for( i=year[0]; i<=year[1]; i++)
		{
            if( i % 4 == 0)
		    {
			    if( i % 100 == 0)
			    {
				    if( i % 400 == 0)
				    {
					    ans++;
				    }
			    }
			    else
			    {
				    ans++;
			    }
		    }
        }
        cout << ans << endl;
	}
	return 0;
}

