#include <iostream>
#include <stdio.h>
using namespace std;

int brac[100],l=0,r=0;
void print (int in)
{
    int i=0; 
    for(i=0;i<2*in;i++)
    {
        if(brac[i]==1)
        {
            printf( "(");
        }
        if(brac[i]==2)
        {
            printf( ")"); 
        }
    }
    printf( "\n");;
    return; 
}
void f (int in,int sit)
{
    int i=0,j=0;
    if(l<in) 
    { 
        brac[sit]=1;
        l++; 
        f(in,sit+1);
        l--; 
    }
    if(r<l)
    {
        brac[sit]=2;
        r++; 
        f(in,sit+1);
        r--; 
    }
    if(r==l&&l==in)
    {
        print(in); 
    }
    return; 
} 
int main (void)
{
    int in=0,sit=0;
    int i=0;
    while( cin>>in)
    {
        for( i = 0; i<100; i++)
        {
            brac[i] = 0;
        }
        brac[0] = 1;
        l = 1;
        sit = 1;
        f(in,sit);
    }
    return 0;
}

