//#define DEBUG
 
#ifdef DEBUG
    #include <stdio.h>
#endif
 
void fill_array(int *ptr[], int n)
{
    int i = 0, j = 0, k = 0, m = ptr[n-1] - ptr[0];
    int *p = ptr[0], *temp[100];
    //int *tmp = 0;
 
    #ifdef DEBUG
        printf( "\nm = %d\n\n", m );
    #endif
 
    /*for( i = 0; i < n; i++)
    {
        temp[i] = ptr[i];
        #ifdef DEBUG
            printf( "temp[ %d ] = 0x%X\n", i, temp[i] );
            printf( "*( temp[ %d ] ) = %d\n\n", i, *( temp[i] ) );
        #endif
    }
    temp[i] = 0;
 
    for( i = 0; i < n; i++)
    {
        for( j = i; j < n; j++)
        {
            if( temp[i] > temp[j] )
            {
                tmp = temp[i] ;
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }
    */
 
    #ifdef DEBUG
        for( i = 0; i < n; i++)
        {
            printf( "ptr[ %d ] = 0x%X\n", i, ptr[i] );
        }
    #endif
 
    for( i = 0; i <= m ; i++)
    {
        *( p + i ) = 0;
        #ifdef DEBUG
            printf( "p + %d = %d\n", i, p + i );
            printf( "*( p + %d ) = %d\n", i, *( p + i ) );
        #endif
    }
 
    *( ptr[ 0 ] ) = 0;
 
    for( i = 0; i < n-1; i++)
    {
        *( ptr[ i+1 ] ) = i + 1;
 
        #ifdef DEBUG
            printf( "*( temp[ %2d ] ) = %2d    ", i, *( temp[i] ) );
            printf( "*(  ptr[ %2d ] ) = %2d\n", i, *( ptr[i] ) );
        #endif
 
        /*for( p = temp[i] + 1; i + 1 < n && p < temp[ i+1 ]; p++)
        {
            //*p = *( temp[i] ) + *( temp[ i+1 ] );
            #ifdef DEBUG
                printf( "*( 0x%X ) = %d\n", p, *p );
            #endif
        }*/
    }
 
    #ifdef DEBUG
        for( i = 0; i <= m; i++)
        {
            printf("%d%c", *( p + i ), " \n"[ i == m ]);
        }
    #endif
 
    for( i = 0; i < m; i++)
    {
        for( j = 1; i+j < m && *( p + i + j ) == 0 ; j++)
        {
            ;
        }
        for( k = 1; k < j; k++)
        {
            *( p + i + k ) = *( p + i ) + *( p + i + j );
        }
        i += j - 1;
    }
}