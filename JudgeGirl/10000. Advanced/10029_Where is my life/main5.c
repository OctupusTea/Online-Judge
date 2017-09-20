#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
#define MAX_LENGTH 128
#define EPSILON 0.000003
 
#ifdef DEBUG
	#define DEBUG_MAIN
	// #define DEBUG_GAUSSIAN_ELIMINATION
	#define DEBUG_GET_POLYNOMIAL
 
	#ifdef DEBUG_PRINT_FLOAT
		void Print_Data( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
		{
			for( int i = 0; i <= student_count; i++ )
			{
				for( int j = 0; j <= problem_count; j++ )
				{
					printf( "%+4.2lf%c", data[ i ][ j ], " \n"[ problem_count == j ] );
				}
			}
			printf( "\n" );
		}
	#else
		void Print_Data( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
		{
			for( int i = 0; i <= student_count; i++ )
			{
				for( int j = 0; j <= problem_count; j++ )
				{
					printf( "%+4.0lf%c", data[ i ][ j ], " \n"[ problem_count == j ] );
				}
			}
			printf( "\n" );
		}
	#endif
#endif
 
int Is_Nonzero( double );
double Round( double );
int First_Student( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
void Gaussian_Elimination( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
int Get_Polynomial( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
 
int main( int argc, char **argv )
{
	int student_count, problem_count;
 
	while( ~scanf( "%d%d", &student_count, &problem_count ) )
	{
		double data[ MAX_LENGTH ][ MAX_LENGTH ] = { 0.0 };
		for( int i = 0; i < student_count; i++ )
		{
			for( int j = 0; j < problem_count; j++ )
			{
				scanf( "%lf", &( data[ i ][ j ] ) );
			}
			scanf( "%lf", &( data[ i ][ problem_count ] ) );
		}
 
		for( int j = 0; j < problem_count; j++ )
		{
			scanf( "%lf", &( data[ student_count ][ j ] ) );
		}
 
		#ifdef DEBUG_MAIN
			Print_Data( data, student_count, problem_count );
		#endif
 
		Gaussian_Elimination( data, student_count, problem_count );
 
		#ifdef DEBUG_MAIN
			printf( "\nGaussian Eliminated : \n" );
			Print_Data( data, student_count, problem_count );
		#endif
 
		int verdict = Get_Polynomial( data, student_count, problem_count );
 
		switch( verdict )
		{
			case 1:
				printf( "not sure\n" );
				break;
			case 2:
				printf( "contradictory\n" );
				break;
			default:
				printf( "%d\n", (int)Round( data[ student_count ][ problem_count ] ) );
				break;
		}
	}
 
	return 0;
}
 
int Is_Nonzero( double a )
{
	return fabs( a ) > EPSILON ? 1 : 0;
}

double Round( double a )
{
	double result;
	__asm__ (
		"frndint;" : "=t" ( result ) : "0" ( a )
	);
 
	return result;
}
 
int First_Student( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_id )
{
	int return_value = -1;
	for( int i = 0; i < student_count; i++ )
	{
		if( Is_Nonzero( data[ i ][ problem_id ] ) )
		{
			int is_leading_term = 1;
			for( int j = 0; j < problem_id && is_leading_term != 0; j++ )
			{
				if( Is_Nonzero( data[ i ][ j ] ) )
				{
					is_leading_term = 0;
				}
			}
 
			if( is_leading_term )
			{
				return_value = i;
				i = student_count;
			}
			else
			{
				return_value = -2;
			}
		}
	}
 
	return return_value;
}
 
void Gaussian_Elimination( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
	int current_student = 0;
 
	for( int i = 0; i < problem_count; i++ )
	{
		int student_max = current_student;
 
		for( int j = student_max; j < student_count; j++ )
		{
			if( fabs( data[ j ][ i ] ) > fabs( data[ student_max ][ i ] ) )
			{
				student_max = j;
			}
		}
		#ifdef DEBUG_GAUSSIAN_ELIMINATION
			printf( "\ncurrent_student = %d, student_max = %d\n", current_student, student_max );
		#endif
		if( Is_Nonzero( data[ student_max ][ i ] ) )
		{
			#ifdef DEBUG_GAUSSIAN_ELIMINATION
				printf( "\nSwaping data of student # %d and # %d\n", current_student, student_max );
			#endif
			for( int j = 0; j <= problem_count; j++ )
			{
				data[ current_student ][ j ] += data[ student_max ][ j ];
			}
			
			for( int j = 0; j < student_count; j++ )
			{
				if( j != current_student )
				{
					double multiplier = data[ j ][ i ] / data[ current_student ][ i ];
					for( int k = 0; k <= problem_count; k++ )
					{
						data[ j ][ k ] -= multiplier * data[ current_student ][ k ];
					}
				}
			}
 
			current_student++;
		}
		#ifdef DEBUG_GAUSSIAN_ELIMINATION
			printf( "\nColumn Cancellation # %d : \n", i );
			Print_Data( data, student_count, problem_count );
		#endif
	}
	
	for( int j = 0; j < student_count; j++ )
	{
		for( int k = 0; k < problem_count; k++ )
		{
			if( Is_Nonzero( data[ j ][ k ] ) )
			{
				for( int l = k + 1; l <= problem_count; l++ )
				{
					data[ j ][ l ] /= data[ j ][ k ];
				}
				data[ j ][ k ] = 1;
				k = problem_count;
			}
		}
	}
}
 
int Get_Polynomial( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
	for( int i = 0; i < student_count; i++ )
	{
		if( Is_Nonzero( data[ i ][ problem_count ] ) )
		{
			int all_zero = 1;
			for( int j = 0; j < problem_count && all_zero != 0; j++ )
			{
				if( Is_Nonzero( data[ i ][ j ] ) )
				{
					all_zero = 0;
				}
			}
	 
			if( all_zero )
			{
				return 2;
			}
		}
	}
 
	for( int i = 0; i < problem_count; i++ )
	{
		if( Is_Nonzero( data[ student_count ][ i ] ) )
		{
			#ifdef DEBUG_GET_POLYNOMIAL
				printf( "\nTerm # %d = %+4.0lf , ", i, data[ student_count ][ i ] );
			#endif
 
			int first_student = First_Student( data, student_count, i );
			#ifdef DEBUG_GET_POLYNOMIAL
				printf( "\nfirst_student = %d\n", first_student );
			#endif
			if( first_student >= 0 )
			{
				double multiplier = data[ student_count ][ i ] / data[ first_student ][ i ];
				data[ student_count ][ problem_count ] += multiplier * data[ first_student ][ problem_count ];
				for( int j = 0; j < problem_count; j++ )
				{
					if( Is_Nonzero( data[ first_student ][ j ] ) )
					{
						data[ student_count ][ j ] -= multiplier * data[ first_student ][ j ];
					}
				}
			}
			else
			{
				return 1;
			}
		}
	}
 
	return 0;
}