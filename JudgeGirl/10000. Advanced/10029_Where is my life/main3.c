#include <stdio.h>
#include <math.h>

const int MAX_LENGTH = 128;
const double EPS = 0.001;
const double DOUBLE_MIN = pow( 2, -1000 );
const double DOUBLE_MAX = pow( 2, 1000 );

// #define DEBUG

#ifdef DEBUG
	#define DEBUG_MAIN
	#define DEBUG_GAUSS_ELIMINATION
	#define DEBUG_GET_POLYNOMIAL
	
	void Print_Data( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
	{
		for( int i = 0; i < student_count; i++ )
		{
			for( int j = 0; j < problem_count; j++ )
			{
				printf( "%0.2lf ", data[ i ][ j ] );
			}
			printf( "%0.2lf\n", data[ i ][ problem_count ] );
		}
		
		for( int j = 0; j <= problem_count; j++ )
		{
			printf( "%0.2lf ", data[ student_count ][ j ] );
		}
		printf( "\n\n" );
	}
#endif

void Gaussian_Elimination( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
inline int First_Non_Zero( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
inline int Check_Previous( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );
inline int Diff( double, double );
int Get_Polynomial( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );

int main( void )
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
			printf( "Gaussian Eliminated :\n" );
			Print_Data( data, student_count, problem_count );
		#endif
		
		int verdict = Get_Polynomial( data, student_count, problem_count );
		// returns 0 for "normal", 1 for "not sure", 2 for "contradictory"
		
		switch( verdict )
		{
			case 1:
				printf( "not sure\n" );
				break;
			case 2:
				printf( "contradictory\n" );
				break;
			default:
				printf( "%d\n", ( int )data[ student_count ][ problem_count ] );
				break;
		}
	}	
	
	return 0;
}

// Apply Gaussian Elimination, eliminating bottom-half of the matrix
void Gaussian_Elimination( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
	int current_row = 0;
	
	for( int i = 0; i < problem_count; i++ )
	{
		int student_max = current_row;
		
		for( int j = current_row; j < student_count; j++ )
		{
			if( fabs( data[ j ][ i ] ) > fabs( data[ student_max ][ i ] ) )
			{
				student_max = j;
			}
		}
		#ifdef DEBUG_GAUSS_ELIMINATION
			printf( "student_max = %d, data[ %d ][ %d ] = %0.2f, current_row = %d\n", student_max, student_max, i, data[ student_max ][ i ], current_row );
		#endif
		/* if( data[ student_max ][ i ] > EPS || data[ student_max ][ i ] < -EPS )
		{
			for( int j = 0; j < student_count; j++ )
			{
				if( j != student_max )
				{
					double multiplier = data[ j ][ i ] / data[ student_max ][ i ];
					
					for( int k = 0; k <= problem_count; k++ )
					{
						data[ j ][ k ] -= multiplier * data[ student_max ][ k ];
					}
				}
			}
		} */
		
		if( data[ student_max ][ i ] > EPS || data[ student_max ][ i ] < -EPS )
		{
			for( int j = 0; j <= problem_count; j++ )
			{
				double temp = data[ student_max ][ j ];
				data[ student_max ][ j ] = data[ current_row ][ j ];
				data[ current_row ][ j ] = temp;
			}
			
			for( int j = 0; j < student_count; j++ )
			{
				if( j != current_row )
				{
					double multiplier = data[ j ][ i ] / data[ current_row ][ i ];
					
					for( int k = 0; k <= problem_count; k++ )
					{
						data[ j ][ k ] -= multiplier * data[ current_row ][ k ];
					}
				}
			}
			
			current_row++;
		}
		
		#ifdef DEBUG_GAUSS_ELIMINATION
			printf( "Aftermath # %d :\n", i );
			Print_Data( data, student_count, problem_count );
		#endif
	}
	
	for( int i = 0; i < student_count; i++ )
	{
		for( int j = 0; j < problem_count; j++ )
		{
			if( data[ i ][ j ] != 0 )
			{
				for( int k = j + 1; k <= problem_count; k++ )
				{
					data[ i ][ k ] /= data[ i ][ j ];
				}
				data[ i ][ j ] = 1;
				j = problem_count;
			}
		}
	}
}

// Checks if problem #problem_id has a non-zero term and return the first non-zero term
// if not, return -1
inline int First_Non_Zero( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_id )
{
	int return_value = -1;
	
	for( int i = 0; i < student_count; i++ )
	{
		if( data[ i ][ problem_id ] > EPS || data[ i ][ problem_id ] < -EPS )
		{
			if( Check_Previous( data, i, problem_id ) == 0 )
			{
				return_value = -2;
			}
			else
			{
				return_value = i;
				i = student_count;
			}
		}
		else
		{
			data[ i ][ problem_id ] = 0.0;
		}
	}
	
	return return_value;
}

// Checks if the coefficient preceeding problem #problem_id of student #student_id are all zero
// return 1 for yes, 0 for no
inline int Check_Previous( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_id, int problem_id )
{
	for( int i = 0; i < problem_id; i++ )
	{
		if( data[ student_id ][ i ] > EPS || data[ student_id ][ i ] < -EPS )
		{
			return 0;
		}
		else
		{
			data[ student_id ][ i ] = 0.0;
		}
	}
	
	return 1;
}

inline int Diff( double a, double b )
{
	double abs_a = fabs( a );
	double abs_b = fabs( b );
	double diff = abs( a - b );
	
	if( a == b )
	{
		return 1;
	}
	else if( a == 0 || b == 0 || diff < DOUBLE_MIN )
	{
		return diff < ( EPS * DOUBLE_MIN );
	}
	else
	{
		return diff / ( abs_a + abs_b ) < EPS;
	}
}

// If the score of the problem is a valid value, return 0.
// return 1 for not sure, 2 for contradictory
int Get_Polynomial( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
	for( int i = 0; i < student_count; i++ )
	{
		int all_zero = 1;
		
		for( int j = 0; j < problem_count && all_zero == 1; j++ )
		{
			if( data[ i ][ j ] > EPS || data[ i ][ j ] < -EPS )
			{
				all_zero = 0;
			}
			else
			{
				data[ i ][ j ] = 0.0;
			}
		}
		
		if( all_zero && ( data[ i ][ problem_count ] > 0.1 || data[ i ][ problem_count ] < -0.1 ) )
		{
			return 2;
		}
	}
	
	#ifdef DEBUG_GET_POLYNOMIAL
		printf( "Get polynomial :\n" );
	#endif
	for( int i = 0; i < problem_count; i++ )
	{
		if( data[ student_count ][ i ] > EPS || data[ student_count ][ i ] < -EPS )
		{
			#ifdef DEBUG_GET_POLYNOMIAL
				printf( "term # %d == 1.0\n", i );
			#endif
			int all_zero = 1;
		
			for( int j = 0; j < student_count && all_zero == 1; j++ )
			{
				if( data[ j ][ i ] > EPS || data[ j ][ i ] < -EPS )
				{
					all_zero = 0;
				}
				else
				{
					data[ j ][ i ] = 0.0;
				}
			}
			#ifdef DEBUG_GET_POLYNOMIAL
				printf( "all_zero = %d\n", all_zero );
			#endif
			if( all_zero != 0 )
			{
				return 1;
			}
			
			int first_non_zero = First_Non_Zero( data, student_count, i );
			#ifdef DEBUG_GET_POLYNOMIAL
				printf( "first_non_zero = %d\n", first_non_zero );
			#endif
			if( first_non_zero >= 0 )
			{
				double multiplier = data[ student_count ][ i ] / data[ first_non_zero ][ i ];
				data[ student_count ][ problem_count ] += data[ first_non_zero ][ problem_count ] * multiplier;
				for( int j = 0; j < problem_count; j++ )
				{
					if( data[ first_non_zero ][ j ] > 0.001 || data[ first_non_zero ][ j ] < -0.001 )
					{
						data[ student_count ][ j ] -= data[ first_non_zero ][ j ] * multiplier;
					}
				}
			}
			else if( first_non_zero == -2 )
			{
				return 1;
			}
		}
		else
		{
			data[ student_count ][ i ] = 0;
		}
	}
	
	return 0;
}