#include <iostream>
#include <string.h>
using namespace std;

int dton( char[]);
void ntod( int, char[]);

int main( void)
{
	char data[3][20] = {0};
	int number[3] = {0};
	
	cin >> data[0];
	
	while( data[0][0] != '#')
	{
		cin >> data[1];
		
		number[0] = dton( data[0]);
		number[1] = dton( data[1]);
		
		if( number[1] > number[0])
		{
			number[1] ^= number[0];
			number[0] ^= number[1];
			number[1] ^= number[0];
		}
		
		number[2] = number[0] - number[1];
		
		ntod( number[2], data[2]);
		cout << data[2] << endl;
		
		for( int i = 0; i < 3; i++)
		{
			for( int j = 0; j < 20; j++)
			{
				data[i][j] = 0;
			}
		}
		
		cin >> data[0];
	}
	
	return 0;
}

int dton( char data[20])
{
	int number = 0;
	int temp[20] = {0};
	int len = strlen( data);
	int i = 0, j = 0;
	char romeChar[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int romeNum[] = { 1, 5, 10, 50, 100, 500, 1000};
	
	for( i = 0; i < len; i++)
	{
		for( j = 0; j < 7; j++)
		{
			if( data[i] == romeChar[j])
			{
				temp[i] = romeNum[j];
				break;
			}	
		}	
	}
	
	for( i = 0; i < len; i++)
	{
		if( temp[i+1] > temp[i])
		{
			number += ( temp[i+1] - temp[i] );
			i++;
		}
		else
		{
			number += temp[i];
		}
	}
	
	return number;
}

void ntod( int number, char data[20])
{
	int i = 0, j = 0;
	int index = 0;
	
	if( number == 0)
	{
		data[0] = 'Z';
		data[1] = 'E';
		data[2] = 'R';
		data[3] = 'O';
		return;
	}
	
	for( i = 0; number >= 1000; i++)
	{
		data[index] = 'M';
		index++;
		number -= 1000;
	}
	
	if( number >= 900)
	{
		data[index] = 'C';
		data[index+1] = 'M';
		index += 2;
		number -= 900;
	}
	
	if( number >= 500)
	{
		data[index] = 'D';
		index++;
		number -= 500;
	}
	
	if( number >= 400)
	{
		data[index] = 'C';
		data[index+1] = 'D';
		index += 2;
		number -= 400;
	}
	
	for( i = 0; number >= 100; i++)
	{
		data[index] = 'C';
		index++;
		number -= 100;
	}
	
	if( number >= 90)
	{
		data[index] = 'X';
		data[index+1] = 'C';
		index += 2;
		number -= 90;
	}
	
	if( number >= 50)
	{
		data[index] = 'L';
		index++;
		number -= 50;
	}
	
	if( number >= 40)
	{
		data[index] = 'X';
		data[index+1] = 'L';
		index += 2;
		number -= 40;
	}
	
	for( i = 0; number >= 10; i++)
	{
		data[index] = 'X';
		index++;
		number -= 10;
	}
	
	if( number >= 9)
	{
		data[index] = 'I';
		data[index+1] = 'X';
		index += 2;
		number -= 9;
	}
	
	if( number >= 5)
	{
		data[index] = 'V';
		index++;
		number -= 5;
	}
	
	if( number >= 4)
	{
		data[index] = 'I';
		data[index+1] = 'V';
		index += 2;
		number -= 4;
	}
	
	for( i = 0; number >= 1; i++)
	{
		data[index] = 'I';
		index++;
		number -= 1;
	}
	
	return;
}

