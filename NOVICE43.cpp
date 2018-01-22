#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 
int dp[11][11],n,t,res[11],x;
 
int main()
{
    memset(res,0,sizeof(res));
    memset(dp,0,sizeof(dp));
        dp[0][0]=1;
    res[0]=1;
        for(int i=1;i<11;i++)
        {
                for(int j=0;j<=i;j++)
                {
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*(j+1);
                        res[i]=res[i]+dp[i][j];
                }
        }
        cin>>t;
        while(t--)
        {
                cin>>x;
                cout<<res[x-1]<<"\n";
        }
}
 
