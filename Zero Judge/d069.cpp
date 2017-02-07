#include <iostream>
using namespace std;
int main(void)
{
	int year[1000] = {0}, i = 0, n = 0;
	while( cin >> n)
	{
    	for( i=0; i<n; i++)
    	{
            cin >> year[i];
            if( year[i] % 4 == 0)
            {
                if( year[i] % 100 == 0)
	   		    {
			    	if( year[i] % 400 == 0)
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
    }
	return 0;
}

