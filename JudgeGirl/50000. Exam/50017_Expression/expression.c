#include <ctype.h>

#ifdef DEBUG

#include <stdio.h>

#endif

#include "expression.h"

#define ERR 0xFFFFFFFF

inline int Is_Operator( char op )
{
	return ( op == '+' || op == '-' || op == '*' || op == '/' );
}

int Is_Expression( char *string )
{
	if( *string == '-' )
	{
		return Is_Expression( string + 1 );
	}

	

	return 0;
}

int Parse_Expression( char *string )
{
	return 0;
}

int expression( char *string )
{
	if( string == NULL )
	{
		return ERR;
	}

	if( *string == '\0' )
	{
		return ERR;
	}

	if( isdigit( *string ) )
	{
		if( *( string + 1 ) == '\0' )
		{
			return ( *string - '0' );
		}
		else
		{
			return ERR;
		}
	}

	if( Is_Expression( string ) )
	{
		return Parse_Expression( string );
	}
	else
	{
		return ERR;
	}
}

