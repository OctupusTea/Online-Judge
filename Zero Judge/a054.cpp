#include <iostream>
#include <string>

using namespace std;

const string NUM_LETTER[ 10 ] = { "BNZ", "CIP", "DOQ", "ER", "FS", "GT", "HU", "JVX", "KLY", "AMW" };
const int MULT_CONST[ 9 ] = { 8, 7, 6, 5, 4, 3, 2, 1, 1 };

int main( void )
{
	string data( 10, '\0' );
	while( cin >> data )
	{
		int sum = 0;
		for( int i = 0; i < 9; ++i )
		{
			sum += ( data[ i ] - '0' ) * MULT_CONST[ i ];
		}

		cout << NUM_LETTER[ sum % 10 ] << '\n';
	}

	return 0;
}
