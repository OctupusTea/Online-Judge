#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LENGTH 128
#define LIST_LENGTH 65536
#define LETTER_COUNT 26

typedef struct Word
{
	char word[ WORD_LENGTH ];
	int order;
} Word;

int Word_Compare( const void *a, const void *b )
{
	const Word **x = ( const Word** )a;
	const Word **y = ( const Word** )b;

	return ( **x ).order - ( **y ).order;
}

typedef struct Node
{
	struct Node *next[ LETTER_COUNT ];
	int end_of_word;
	int order;
} Node;

Node* Trie_New( void )
{
	Node *root = ( Node* )malloc( sizeof( Node ) );

	for( int i = 0; i < LETTER_COUNT; ++i )
	{
		root -> next[ i ] = NULL;
	}
	root -> end_of_word = 0;
	root -> order = -1;

	return root;
}

void Trie_Delete( Node *root )
{
	if( root != NULL )
	{
		for( int i = 0; i < LETTER_COUNT; ++i )
		{
			if( root -> next[ i ] != NULL )
			{
				Trie_Delete( root -> next[ i ] );
			}
		}

		free( root );
	}
}

void Trie_Add( Node *root, char *word, int order )
{
	if( *word == '\0' )
	{
		root -> end_of_word = 1;
		root -> order = order;
	}
	else if( root -> next[ *word - 'a' ] != NULL )
	{
		Trie_Add( root -> next[ *word - 'a' ], word + 1, order );
	}
	else
	{
		for( ; *word != '\0'; ++word )
		{
			root -> next[ *word - 'a' ] = ( Node* )malloc( sizeof( Node ) );
			root = root -> next[ *word - 'a' ];
		}

		root -> end_of_word = 1;
		root -> order = order;
	}
}

int Trie_Find( Node *root, char *word )
{
	if( *word == '\0' )
	{
		if( root -> end_of_word )
		{
			return root -> order;
		}
		else
		{
			return -1;
		}
	}
	else if( root -> next[ *word - 'a' ] != NULL )
	{
		return Trie_Find( root -> next[ *word - 'a' ], word + 1 );
	}
	else
	{
		return -1;
	}
}

int Check_Exact( Node *root, char *word )
{
	return Trie_Find( root, word );
}

int Check_Substitute( Node *root, char *word, Word *result_list[ LIST_LENGTH ], int count )
{
	char new_word[ WORD_LENGTH ] = { 0 };
	strcpy( new_word, word );

	for( int i = 0; new_word[ i ] != '\0'; ++i )
	{
		for( char j = 'a'; j <= 'z'; ++j )
		{
			if( j != word[ i ] )
			{
				new_word[ i ] = j;

				int order = Trie_Find( root, new_word );
				if( order >= 0 )
				{
					strcpy( result_list[ count ] -> word, new_word );
					result_list[ count ] -> order = order;
					++count;
				}
			}
		}
		
		new_word[ i ] = word[ i ];
	}

	return count;
}

int Check_Add( Node *root, char *word, Word *result_list[ LIST_LENGTH ], int count )
{
	char new_word[ WORD_LENGTH ] = { 0 };
	strcpy( new_word, word );

	for( int pos = strlen( word ); pos >= 0; --pos )
	{
		new_word[ pos + 1 ] = word[ pos ];
		
		for( char j = 'a'; j <= 'z'; ++j )
		{
			new_word[ pos ] = j;

			int order = Trie_Find( root, new_word );
			if( order >= 0 )
			{
				strcpy( result_list[ count ] -> word, new_word );
				result_list[ count ] -> order = order;
				++count;
			}
		}
	}

	return count;
}

int Check_Remove( Node *root, char *word, Word *result_list[ LIST_LENGTH ], int count )
{
	char new_word[ WORD_LENGTH ] = { 0 };
	
	strcpy( new_word, word );
	
	for( int pos = strlen( word ); pos > 0; --pos )
	{
		new_word[ pos - 1 ] = word[ pos ];
		
		int order = Trie_Find( root, new_word );
		if( order >= 0 )
		{
			strcpy( result_list[ count ] -> word, new_word );
			result_list[ count ] -> order = order;
			++count;
		}
	}

	return count;
}

int main( void )
{
	Node *dictionary = Trie_New( );

	int dictionary_size;
	scanf( "%d", &dictionary_size );

	Word *result[ LIST_LENGTH ];
	for( int i = 0; i < LIST_LENGTH; ++i )
	{
		result[ i ] = ( Word* )malloc( sizeof( Word ) );
	}

	for( int i = 0; i < dictionary_size; ++i )
	{
		char word[ WORD_LENGTH ] = { 0 };
		scanf( "%s", word );

		Trie_Add( dictionary, word, i );
	}

	int query_count;
	scanf( "%d", &query_count );

	for( int i = 0; i < query_count; ++i )
	{
		char word[ WORD_LENGTH ] = { 0 };
		scanf( "%s", word );

		if( Check_Exact( dictionary, word ) >= 0 )
		{
			printf( ">%s\n", word );
		}
		else
		{
			int count = 0;
			count = Check_Substitute( dictionary, word, result, count );
			count = Check_Add( dictionary, word, result, count );
			count = Check_Remove( dictionary, word, result, count );

			if( count != 0 )
			{
				qsort( result, count, sizeof( Word* ), Word_Compare );
				
				printf( "?%s", result[ 0 ] -> word );
				for( int i = 1; i < count; ++i )
				{
					if( strcmp( result[ i ] -> word, result[ i - 1 ] -> word ) != 0 )
					{
						printf( " %s", result[ i ] -> word );
					}
				}
				printf( "\n" );

#ifdef DEBUG
				for( int i = 0; i < count; ++i )
				{
					printf( "%d ", result[ i ] -> order );
				}
				printf( "\n" );
#endif
			}
			else
			{
				printf( "!%s\n", word );
			}
		}
	}

	Trie_Delete( dictionary );

	for( int i = 0; i < LIST_LENGTH; ++i )
	{
		free( result[ i ] );
	}

	return 0;
}
