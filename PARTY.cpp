#include<iostream>
#include<algorithm>
using namespace std;

int dp[550][110],n,m,x,y,cost[110],fun[110];

int main()
{
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        for(int i=1;i<=m;i++)
            cin>>cost[i]>>fun[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i<cost[j])
                    dp[i][j]=dp[i][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-cost[j]][j-1]+fun[j]);
            }
        }
        int temp=dp[n][m];
        for(int i=n;i>=0;i--)
        {
            if(dp[i][m]!=temp)
            {
                temp=i;
                break;
            }
        }
        cout<<temp+1<<" "<<dp[n][m]<<"\n";
    }
}