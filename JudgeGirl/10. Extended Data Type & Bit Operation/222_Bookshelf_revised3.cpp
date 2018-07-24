#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

using namespace std;

//#define DEBUG

#define BUFFER_SIZE 65536

int eof_reached = 0;
 
int readchar() {
    static int N = 65536;
    static char buf[65536];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + read( STDIN_FILENO, buf, N )) == buf) {
            eof_reached = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
 
int Get_Book( int *book )
{
	int temp = readchar( );
	
	while( temp < '0' or temp > '9' )
	{
		if( eof_reached )
		{
			return 0;
		}

		temp = readchar( );	
	}

	int ret = 0;
	while( temp >= '0' and temp <= '9' )
	{
		ret *= 10;
		ret += temp - '0';

		temp = readchar( );
	}

	*book = ret;
	return 1;
}

int main( void )
{
	pair< int, int > last_occurence[ 256 ];
	for( int i = 0; i ^ 256; ++i )
	{
		last_occurence[ i ].first = -1;
		last_occurence[ i ].second = i;
	}

	int book_temp;
	for( int i = 0; Get_Book( &book_temp ); ++i )
	{
		last_occurence[ book_temp ].first = i;
	}

	sort( last_occurence, last_occurence + 256 );

	int output[ 8 ] = { 0 };
	for( int i = 248; i < 256; ++i )
	{
		if( last_occurence[ i ].first ^ -1 )
		{
			output[ i - 248 ] = last_occurence[ i ].second;
		}
		else
		{
			output[ i - 248 ] = 0;
		}
	}

	for( int i = 0; i < 7; ++i )
	{
		cout << output[ i ] << ' ';
	}
	cout << output[ 7 ] << '\n';

	return 0;
}
