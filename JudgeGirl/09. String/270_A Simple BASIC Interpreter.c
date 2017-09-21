#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
//#define DEBUG
//#define LINE
 
char var_name[ 128 ][ 8 ] = {0};
int var_value[ 128 ] = {0};
char line[ 1024 ][ 128 ][ 8 ] = {0};
 
int search( char *temp, char var_name[ 128 ][ 8 ], int var_count )
{
    for( int i = 0; i < var_count; i++ )
    {
        if( !strcmp( temp, var_name[ i ] ) )
        {
            return i;
        }
    }
 
    return -1;
}
 
int if_state( int pos0, char *op, int pos1, int var_value[ 128 ] )
{
    if( !strcmp( op, "==" ) )
    {
        if( var_value[ pos0 ] == var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( !strcmp( op, "!=" ) )
    {
        if( var_value[ pos0 ] != var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( !strcmp( op, ">" ) )
    {
        if( var_value[ pos0 ] > var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( !strcmp( op, "<" ) )
    {
        if( var_value[ pos0 ] < var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( !strcmp( op, ">=" ) )
    {
        if( var_value[ pos0 ] >= var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( !strcmp( op, "<=" ) )
    {
        if( var_value[ pos0 ] <= var_value[ pos1 ] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
 
void operate( int posLeft, char* op, int posRight0, int posRight1, int var_value[ 128 ] )
{
    int ans = var_value[ posRight0 ];
 
    if( !strcmp( op, "+" ) )
    {
        ans += var_value[ posRight1 ];
    }
    else if( !strcmp( op, "-" ) )
    {
        ans -= var_value[ posRight1 ];
    }
    else if( !strcmp( op, "*" ) )
    {
        ans *= var_value[ posRight1 ];
    }
    else if( !strcmp( op, "/" ) )
    {
        ans /= var_value[ posRight1 ];
    }
    else if( !strcmp( op, "%" ) )
    {
        ans %= var_value[ posRight1 ];
    }
 
    var_value[ posLeft ] = ans;
}
 
int main( void)
{
    int var_count = 0;
    char *var_temp = malloc( 8 * sizeof( char ) );
 
    scanf( "%s", var_temp );
 
    while( strcmp( var_temp , "END" ) )
    {
        strncpy( var_name[ var_count ], var_temp, 8 );
        scanf( "%s", var_temp );
        scanf( "%s", var_temp );
        var_value[ var_count ] = atoi( var_temp );
        var_count++;
        scanf( "%s", var_temp );
        #ifdef DEBUG
            printf( "variable # %d : %s = %d\n", var_count - 1, var_name[ var_count - 1 ], var_value[ var_count - 1 ] );
        #endif
    }
 
    int line_count = 0;
    char *line_temp = malloc( 1024 * sizeof( char ) );
 
    fgets( line_temp, 1024, stdin );
    #ifdef DEBUG
        printf( "scanned line_temp : %s\n", line_temp );
    #endif
 
    while( line_temp[ 0 ] != '\0' )
    {
        int tok_count = 0;
        char *word_temp = strtok( line_temp, " \n" );
        #ifdef DEBUG
            printf( "strtoked line_temp %d\n", line_count );
        #endif
 
        while( word_temp != NULL )
        {
            strcpy( line[ line_count ][ tok_count ], word_temp );
            tok_count++;
            word_temp = strtok( NULL, " \n" );
            #ifdef DEBUG
                printf( "strtoked word_temp %d\n", tok_count );
            #endif    
        }
 
        line_count++;
 
        line_temp[ 0 ] = '\0';
        fgets( line_temp, 1024, stdin );
    }
 
    #ifdef DEBUG
        for( int i = 1; i < line_count; i++ )
        {
            for( int j = 0; line[ i ][ j ][ 0 ] != '\0'; j++ )
            {
                printf( "%3d, %3d, %s\n", i, j, line[ i ][ j ] );
            }
        }
    #endif
 
    for( int i = 1; i < line_count ; i++ )
    {
        #ifdef LINE
            printf( "line %3d  ", i );
            for( int j = 0; line[ i ][ j ][ 0 ] != '\0'; j++ )
            {
                printf( "%s ", line[ i ][ j ] );
            }
            printf( "\n" );
        #endif
 
        int index = 0;
 
        #ifdef DEBUG
            printf( "i = %d, line[ i ][ index ] = %s\n", i, line[ i ][ index ] );
        #endif
 
        if( !strcmp( line[ i ][ index ], "IF" ) )
        {
            index++;
            #ifdef DEBUG
                printf( "if_state 0 : line[ i ][ index ] = %s, ", line[ i ][ index ] );
            #endif
            int pos0 = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, pos0 = %d, ", line[ i ][ index ], pos0 );
            #endif
 
            index++;
            char *op = line[ i ][ index ];
 
            index++;
            int pos1 = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "op = %s, line[ i ][ index ] = %s, pos1 = %d\n", op, line[ i ][ index ], pos1 );
            #endif
 
            if( if_state( pos0, op, pos1, var_value ) )
            {
                index += 2;
                i = atoi( line[ i ][ index ] ) - 1;
 
                #ifdef DEBUG
                    printf( "line[ i ][ index ] = %s, i = %d\n", line[ i ][ index ], i );
                #endif
            }
        }
        else if( !strcmp( line[ i ][ index ], "GOTO" ) )
        {
            index++;
            i = atoi( line[ i ][ index ] ) - 1;
 
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, i = %d\n", line[ i ][ index ], i );
            #endif
        }
        else if( !strcmp( line[ i ][ index ], "PRINT" ) )
        {
            index++;
            int pos = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, i = %d\n", line[ i ][ index ], i );
            #endif
 
            printf( "%d\n", var_value[ pos ] );
        }
        else if( !strcmp( line[ i ][ index ], "STOP" ) )
        {
            i = line_count;
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, i = %d\n", line[ i ][ index ], i );
            #endif
        }
        else
        {
            int posLeft = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, posLeft = %d, ", line[ i ][ index ], posLeft );
            #endif
 
            index += 2;
            int posRight0 = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "line[ i ][ index ] = %s, posRight0 = %d, ", line[ i ][ index ], posRight0 );
            #endif
 
            index++;
            char *op = line[ i ][ index ];
 
            index++;
            int posRight1 = search( line[ i ][ index ], var_name, var_count );
 
            #ifdef DEBUG
                printf( "op = %s, line[ i ][ index ] = %s, posRight1 = %d\n", op, line[ i ][ index ], posRight1 );
            #endif
 
            operate( posLeft, op, posRight0, posRight1, var_value );
        }
    }
 
    return 0;
}