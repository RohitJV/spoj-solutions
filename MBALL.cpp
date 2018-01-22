#include<iostream>
#include<string.h>
#include<stdio.h>
#include<assert.h>
using namespace std;

long long dp[5][100005],ans;

int main()
{
    int n,t;
    memset(dp,0,600000);
    dp[0][2]=dp[1][3]=dp[2][6]=dp[3][7]=dp[4][8]=1;
    for(int i=2;i<100001;i++)
    {
        if(i-8>=0)
        {
            dp[4][i]=dp[4][i]+dp[4][i-8];
            dp[4][i]=dp[4][i]+dp[3][i-8];
            dp[4][i]=dp[4][i]+dp[2][i-8];
            dp[4][i]=dp[4][i]+dp[1][i-8];
            dp[4][i]=dp[4][i]+dp[0][i-8];
        }
        if(i-7>=0)
        {
            dp[3][i]=dp[3][i]+dp[3][i-7];
            dp[3][i]=dp[3][i]+dp[2][i-7];
            dp[3][i]=dp[3][i]+dp[1][i-7];
            dp[3][i]=dp[3][i]+dp[0][i-7];
        }
        if(i-6>=0)
        {
            dp[2][i]=dp[2][i]+dp[2][i-6];
            dp[2][i]=dp[2][i]+dp[1][i-6];
            dp[2][i]=dp[2][i]+dp[0][i-6];
        }
        if(i-3>=0)
        {
            dp[1][i]=dp[1][i]+dp[1][i-3];
            dp[1][i]=dp[1][i]+dp[0][i-3];
        }
        if(i-2>=0)
            dp[0][i]=dp[0][i]+dp[0][i-2];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0)
          ans=1;
        else
        	ans=dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n]+dp[4][n];
        cout<<ans<<"\n";
    }
    
}