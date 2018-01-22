#include<iostream>
#include<algorithm>
using namespace std;
#define INF 10000000
 
int dp[25][30],n,h,f,s,a[25],ans,cnt=1;
 
int main()
{
    while(1)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<30;j++)
                dp[i][j]=INF;
        if(n==0)
            break;
        cin>>h>>s>>f;
        for(int i=0;i<n;i++)
            cin>>a[i];
        dp[0][a[0]]=(h+s)*a[0];
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<30;j++)
            {
                if(dp[i][j]!=INF)
                {
                    if(a[i+1]>j)
                    {
                        //cout<<"dp[i][j] : "<<dp[i][j]<<"\n";
                        dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]],dp[i][j]+s*a[i+1]+h*(a[i+1]-j));
                        //cout<<"more : "<<dp[i+1][a[i+1]]<<"\n";
                    }
                    else
                    {
                        //cout<<"less : \n";
                        for(int k=j;k>=a[i+1];k--)
                        {
                            dp[i+1][k]=min(dp[i+1][k],dp[i][j]+s*k+(j-k)*f);
                           // cout<<dp[i+1][k]<<"\n";
                        }
                    }
                }
            }
        }
        ans=INF;
        for(int i=0;i<30;i++)
            ans=min(dp[n-1][i],ans);
        //cout<<ans<<"\n\n";
        cout<<"Case "<<cnt++<<", cost = $"<<ans<<"\n";
    }
}