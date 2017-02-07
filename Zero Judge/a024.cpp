#include <iostream>
using namespace std;
int main(void)
{
	int m = 0, n = 0, k = 0;
	while( cin >> m >> n)
	{
		if(m<n)
		{
			m = m ^ n;
			n = m ^ n;
			m = m ^ n;
		}
		while(n!=0)
		{
			k = n;
			n = m % n;
			m = k;
		}
		cout << m <<endl;
	}
	return 0;
}

