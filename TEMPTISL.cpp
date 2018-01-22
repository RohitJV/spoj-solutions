#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
long long n,k,dp[55][55],x,y;
 
long long calc(int a,int b)
{
    if(b==0)
    {
        if(a==y)
            return 1;
        return 0;
    }
    if(dp[a][b]!=-1)
        return(dp[a][b]);
    long long ret1,ret2;
    if(a+1>n)
        ret1=calc(1,b-1);
    else
        ret1=calc(a+1,b-1);
    if(a-1<1)
        ret2=calc(n,b-1);
    else
        ret2=calc(a-1,b-1);
    dp[a][b]=ret1+ret2;
    //cout<<a<<" "<<b<<" : "<<dp[a][b]<<"\n";
    return(dp[a][b]);
}
 
int main()
{
    while(1)
    {
        cin>>n>>k;
        if(n==-1 && k==-1)
            break;
        memset(dp,-1,sizeof(dp));
        cin>>x>>y;
        cout<<calc(x,k)<<"\n";
    }
}
