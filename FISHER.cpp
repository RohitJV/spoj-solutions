#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
#define MIN 1000000
 
int n,t,tim[55][55],toll[55][55],dp[55][1005],mintime,mintoll;
 
int main()
{
    while(1)
    {
        cin>>n>>t;
        if(n==0 && t==0)
            break;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>tim[i][j];
                
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>toll[i][j];
                
        memset(dp,MIN,sizeof(dp));
        dp[0][0]=0;
        
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i-tim[k][j] < 0 )
                        continue;
                    dp[j][i]=min(dp[j][i],toll[k][j]+dp[k][i-tim[k][j]]);
                }
            }
        }
        mintime=mintoll=MIN;
        for(int i=0;i<=t;i++)
        {
            if(dp[n-1][i] < mintoll)
            {
                mintoll=dp[n-1][i];
                mintime=i;
            }
        }
        cout<<mintoll<<" "<<mintime<<"\n";
    }
}
