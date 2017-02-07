#include <iostream>
using namespace std;

int main( void)
{
	int prime[500] = {2};
	int ans[500] = {0};
	int primeCount = 1, number = 0;
	int i = 0, j = 0;
	bool isPrime = true, initial = true;
	
	for( i = 3; i < 1000; i++)
	{
		isPrime = true;
		
		for( j = 0; j < primeCount; j++)
		{
			if( i % prime[j] == 0)
			{
				isPrime = false;
			}
		}
		
		if( isPrime)
		{
			prime[primeCount] = i;
			primeCount++;
		}
	}
	
	while( cin >> number)
	{
		for( i = 0; i < primeCount; i++)
		{
			ans[i] = 0;
		}
		
		for( i = 0; i < primeCount; i++)
		{
			while( number % prime[i] == 0)
			{
				ans[i]++;
				number /= prime[i];
			}
		}
		
		initial = true;
		
		for( i = 0; i < primeCount; i++)
		{
			if( ans[i] == 1)
			{
				if( !initial)
				{
					cout << " * ";
				}
				cout << prime[i];
				initial = false;
			}
			else if( ans[i] > 1)
			{
				if( !initial)
				{
					cout << " * ";
				}
				cout << prime[i] << "^" << ans[i];				
				initial = false;
			}
		}
		
		if( number != 1)
		{
			if( !initial)
			{
				cout << " * ";
			}
			cout << number;
		}
		
		cout << endl;
	}
	
	return 0;
}
