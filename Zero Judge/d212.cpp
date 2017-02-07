#include<iostream>
using namespace std;
unsigned long long fabbs[120]={0};
unsigned long long fab(unsigned long long n)
{
    if(n<=2)
    {
        return fabbs[n];
    }
    else
    {
        if(fabbs[n-1]==0)
        {
            fabbs[n-1]=fab(n-1);
        }
        if(fabbs[n-2]!=0)
        {
            fabbs[n-2]=fab(n-2);
        }
        fabbs[n]=fabbs[n-1]+fabbs[n-2];
        return fabbs[n];
    }
}
int main(void)
{
    unsigned long long n=0,ans=0;
    fabbs[0] = 1;
    fabbs[1] = 1;
    fabbs[2] = 2;
    fab(120);
    
    while( cin >> n)
    {
    	cout << fabbs[n] << endl;
    }
    
    return 0;
}
