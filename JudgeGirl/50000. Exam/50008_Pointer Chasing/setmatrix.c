#include <stdio.h>
#include "setmatrix.h"
 
inline void processSetMatrix( int ***ptr )
{
	for( int ***array = ptr; *array != NULL; array++ )
	{
		for( int **set = *array; *set != NULL; set++ )
		{
			for( int *element = *set; *element != 0; element++ )
			{
				printf( "%d ", *element );
			}
		}
	}
	printf( "\n" );
}