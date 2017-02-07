#include "intersection.h"
//#define DEBUG
void intersection( int map[100][100], int result[4])
{
    int n = 100, i = 0, j = 0;
    result[0] = 0, result[1] = 0, result[2] = 0, result[3] = 0;
    //int block[102][102] = {0};
    //int intersection = 0, tJunction = 0, turn = 0, deadEnd = 0;
 
    //scanf( "%d", &n);
 
    /**for( i = 0; i < n; i++)
    {
        for( j = 0; j < n; j++)
        {
            scanf( "%d", &block[i][j]);
        }
    }*/
 
    for( i = 0; i < n; i++)
    {
        for( j = 0; j < n; j++)
        {
            #ifdef DEBUG
                printf( "%d %d : ", i, j);
            #endif
            if( map[i][j] )
            {
                if( i == 0)
                {
                    if( j == 0)
                    {
                        if( map[i+1][j] && map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else if( map[i+1][j] ^ map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else if( j == n - 1 )
                    {
                        if( map[i+1][j] && map[i][j-1] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else if( map[i+1][j] ^ map[i][j-1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else
                    {
                        if( map[i+1][j] )
                        {
                            if( map[i][j+1] && map[i][j-1] )
                            {
                                #ifdef DEBUG
                                    printf( "T-junction\n");
                                #endif
                                result[1]++;
                            }
                            else if( map[i][j+1] ^ map[i][j-1] )
                            {
                                #ifdef DEBUG
                                    printf( "result[2]\n");
                                #endif
                                result[2]++;
                            }
                            else
                            {
                                #ifdef DEBUG
                                    printf( "dead end\n");
                                #endif
                                result[3]++;
                            }
                        }
                        else if( map[i][j+1] ^ map[i][j-1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                }
                else if( i == n - 1)
                {
                    if( j == 0)
                    {
                        if( map[i-1][j] && map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else if( map[i-1][j] ^ map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else if( j == n - 1 )
                    {
                        if( map[i-1][j] && map[i][j-1] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else if( map[i-1][j] ^ map[i][j-1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else
                    {
                        if( map[i-1][j] )
                        {
                            if( map[i][j+1] && map[i][j-1] )
                            {
                                #ifdef DEBUG
                                    printf( "T-junction\n");
                                #endif
                                result[1]++;
                            }
                            else if( map[i][j-1] ^ map[i][j+1] )
                            {
                                #ifdef DEBUG
                                    printf( "result[2]\n");
                                #endif
                                result[2]++;
                            }
                            else
                            {
                                #ifdef DEBUG
                                    printf( "dead end\n");
                                #endif
                                result[3]++;
                            }
                        }
                        else if( map[i][j-1] ^ map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                }
                else if( j == 0 )
                {
                    if( map[i][j+1] )
                    {
                        if( map[i+1][j] && map[i-1][j] )
                        {
                            #ifdef DEBUG
                                printf( "T-junction\n");
                            #endif
                            result[1]++;
                        }
                        else if( map[i+1][j] ^ map[i-1][j] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else if( map[i+1][j] ^ map[i-1][j] )
                    {
                        #ifdef DEBUG
                            printf( "dead end\n");
                        #endif
                        result[3]++;
                    }
                }
                else if( j == n - 1 )
                {
                    if( map[i][j-1] )
                    {
                        if( map[i+1][j] && map[i-1][j] )
                        {
                            #ifdef DEBUG
                                printf( "T-junction\n");
                            #endif
                            result[1]++;
                        }
                        else if( map[i+1][j] ^ map[i-1][j] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else if( map[i+1][j] ^ map[i-1][j] )
                    {
                        #ifdef DEBUG
                            printf( "dead end\n");
                        #endif
                        result[3]++;
                    }
                }
                else
                {
                    if( map[i-1][j] && map[i+1][j] )
                    {
                        if( map[i][j-1] && map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "result[0]\n");
                            #endif
                            result[0]++;
                        }
                        else if( map[i][j-1] ^ map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "T-junction\n");
                            #endif
                            result[1]++;
                        }
                    }
                    else if( map[i-1][j] ^ map[i+1][j] )
                    {
                        if( map[i][j-1] && map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "T-junction\n");
                            #endif
                            result[1]++;
                        }
                        else if( map[i][j-1] ^ map[i][j+1] )
                        {
                            #ifdef DEBUG
                                printf( "result[2]\n");
                            #endif
                            result[2]++;
                        }
                        else
                        {
                            #ifdef DEBUG
                                printf( "dead end\n");
                            #endif
                            result[3]++;
                        }
                    }
                    else if( map[i][j-1] ^ map[i][j+1] )
                    {
                        #ifdef DEBUG
                            printf( "dead end\n");
                        #endif
                        result[3]++;
                    }
                }
            }
        }
    }
    //printf( "%d\n%d\n%d\n%d", intersection, tJunction, turn, deadEnd);
}