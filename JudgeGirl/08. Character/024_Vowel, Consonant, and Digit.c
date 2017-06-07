#include <stdio.h>
#include <string.h>
 
int main( void)
{
    char temp = 0;
    int vowel = 0, consonants = 0, digits = 0;
 
    while( ~scanf( "%c", &temp ) )
    {
        if( temp == 'a' || temp == 'A' || temp == 'e' || temp == 'E' || temp == 'i' || temp == 'I' || temp == 'o' || temp == 'O' || temp == 'u' || temp == 'U' )
        {
            vowel++;
        }
        else if( ( temp > 'a' && temp <= 'z' ) || ( temp > 'A' && temp <= 'Z' ) )
        {
            consonants++;
        }
        else if( temp >= '0' && temp <= '9' )
        {
            digits++;
        }
    }
 
    printf( "%d %d %d %d\n", digits, vowel + consonants, vowel, consonants );
 
    return 0;
}