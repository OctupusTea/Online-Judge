void snake(const int *ptr_array[100][100], int m)
{
    int *temp[ 10000 ];
    int *tmp;
    int index = 0;
 
    /*for( int i = 0; i < m; i++)
    {
        if( i % 2 == 0 )
        {
            for( int j = 0; j < m; j++)
            {
                temp[ index ] = ptr_array[ i ][ j ];
                index++;
            }
        }
        else
        {
            for( int j = m - 1; j >= 0; j--)
            {
                temp[ index ] = ptr_array[ i ][ j ];
                index++;
            }
        }
    }*/
 
    for( int i = 0; i < m; i++)
    {
        for( int j = 0; j < m; j++)
        {
            temp[ index ] = ptr_array[i][j];
            index++;
        }
    }
 
    for( int i = 0; i < m * m; i++)
    {
        for( int j = i; j < m * m; j++)
        {
            if( *( temp[ i ] ) > *( temp[ j ] ) )
            {
                tmp = temp[ i ];
                temp[ i ] = temp[ j ];
                temp[ j ] = tmp;
            }
        }
    }
 
    index = 0;
 
    for( int i = 0; i < m; i++)
    {
        if( i % 2 == 0 )
        {
            for( int j = 0; j < m; j++)
            {
                ptr_array[ i ][ j ] = temp[ index ];
                index++;
            }
        }
        else
        {
            for( int j = m - 1; j >= 0; j--)
            {
                ptr_array[ i ][ j ] = temp[ index ];
                index++;
            }
        }
    }
 
    /*for( int i = 0; i < m; i++)
    {
        for( int j = 0; j < m; j++)
        {
            ptr_array[i][j] = temp[ index ];
            index++;
        }
    }*/
}