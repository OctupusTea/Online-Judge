#include <stdio.h>
 
#define MAX_LENGTH 128
 
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
            printf( "%0.2f\n", data[ i ][ problem_count ] );
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
int Get_Polynomial( double[ MAX_LENGTH ][ MAX_LENGTH ], int, int );

int student_count, problem_count;

int Compare( const void *a, const void *b )
{
	const double *x = a;
	const double *y = b;
	for( int i = 0; i < problem_count; i++ )
	{
		if( *( x + i ) != *( y + i ) )
		{
			return *( x + i ) > *( y + i );
		}
	}
	
	return 0;
}

int main( void )
{
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
		
		qsort( data, student_count, MAX_LENGTH * sizeof( double ), Compare );
		
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
 
// Apply Gaussian Elimination, eliminating bottom-haf of the matrix
void Gaussian_Elimination( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
    for( int i = 0; i < problem_count; i++ )
    {
        int first_non_zero = First_Non_Zero( data, student_count, i );
 
        if( first_non_zero != -1 )
        {
            for( int j = 0; j < student_count; j++ )
            {
                if( j != first_non_zero )
                {
                    double first_term = data[ first_non_zero ][ i ];
                    double multiplication = data[ j ][ i ] / data[ first_non_zero ][ i ];
 
                    for( int k = 0; k <= problem_count; k++ )
                    {
                        data[ j ][ k ] -= multiplication * data[ first_non_zero ][ k ];
                        if( data[ first_non_zero ][ k ] > 0.001 || data[ first_non_zero ][ k ] < -0.001 )
                        {
                            data[ first_non_zero ][ k ] /= first_term;
                        }
						else
						{
							data[ first_non_zero ][ k ] = 0.0;
						}
                    }
                }
            }
        }
 
        #ifdef DEBUG_GAUSS_ELIMINATION
            printf( "Aftermath # %d :\n", i );
            Print_Data( data, student_count, problem_count );
        #endif
    }
}
 
// Checks if problem #problem_id has a non-zero term and return the first non-zero term
// if not, return -1
inline int First_Non_Zero( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_id )
{
    for( int i = 0; i < student_count; i++ )
    {
        if( ( data[ i ][ problem_id ] > 0.001 || data[ i ][ problem_id ] < -0.001 ) && Check_Previous( data, i, problem_id ) != 0 )
        {
            return i;
        }
    }
 
    return -1;
}
 
// Checks if the coefficient preceeding problem #problem_id of student #student_id are all zero
// return 1 for yes, 0 for no
inline int Check_Previous( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_id, int problem_id )
{
    for( int i = 0; i < problem_id; i++ )
    {
        if( data[ student_id ][ i ] > 0.001 || data[ student_id ][ i ] < -0.001 )
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
 
// If the score of the problem is a valid value, return 0.
// return 1 for not sure, 2 for contradictory
int Get_Polynomial( double data[ MAX_LENGTH ][ MAX_LENGTH ], int student_count, int problem_count )
{
    for( int i = 0; i < student_count; i++ )
    {
        int all_zero = 1;
 
        for( int j = 0; j < problem_count && all_zero == 1; j++ )
        {
            if( data[ i ][ j ] > 0.001 || data[ i ][ j ] < -0.001 )
            {
                all_zero = 0;
            }
        }
 
        if( all_zero && ( data[ i ][ problem_count ] >= 0.1 || data[ i ][ problem_count ] <= -0.1 ) )
        {
            return 2;
        }
    }
 
    #ifdef DEBUG_GET_POLYNOMIAL
        printf( "Get polynomial :\n" );
    #endif
    for( int i = 0; i < problem_count; i++ )
    {
        if( data[ student_count ][ i ] == 1.0 )
        {
            #ifdef DEBUG_GET_POLYNOMIAL
                printf( "    data[ %d ][ %d ] == 1.0\n", student_count, i );
            #endif
            int first_non_zero = First_Non_Zero( data, student_count, i );
            #ifdef DEBUG_GET_POLYNOMIAL
                printf( "    first_non_zero = %d\n", first_non_zero );
            #endif
            if( first_non_zero != -1 )
            {
                for( int j = 0; j < problem_count; j++ )
                {
                    if( j != i && ( data[ first_non_zero ][ j ] > 0.001 || data[ first_non_zero ][ j ] < -0.001 ) )
                    {
                        #ifdef DEBUG_GET_POLYNOMIAL
                            printf( "    j = %d != i    &&    data[ %d ][ %d ] != 0.0\n", j, first_non_zero, j );
                        #endif
                        if( data[ student_count ][ j ] == 0.0 || data[ first_non_zero ][ j ] != 1.0 )
                        {
                            return 1;
                        }
                        else
                        {
                            data[ student_count ][ j ] = 0.0;
                        }
                    }
                }
 
                data[ student_count ][ problem_count ] += data[ first_non_zero ][ problem_count ];
            }
            else
            {
                return 1;
            }
        }
    }
 
    return 0;
}