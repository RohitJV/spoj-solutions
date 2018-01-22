#include<iostream>
#include "BigIntegerLibrary.hh"
using namespace std;
 
long long int s[500],n;
 
int main()
{
    s[0]=1;
    s[1]=1;
    for(int i=2;i<=500;i++)
    {
        s[i]=0;
        for(int j=0;;j++)
        {
            if(j>i-j-1)
            {
                s[i]=s[i]*2;
                break;
            }
            else if(j==i-j-1)
            {
                s[i]=s[i]*2;
                s[i]=s[i]+s[j]*s[i-j-1];;
                break;
            }
            else
                s[i]=s[i]+s[j]*s[i-j-1];
        }
    }
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        else
            cout<<s[n]<<"\n";
    }
}