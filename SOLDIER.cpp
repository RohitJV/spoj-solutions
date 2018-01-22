#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define MIN -1
#define pb push_back

int n,t,x,y,z,dp[10][2000],flag=0;
vector <int> cost[10],quality[10];

int main()
{
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        if(x>6 || x<1)
            continue;
        cost[x].pb(y);
        quality[x].pb(z);
    }
    for(int i=1;i<=6;i++)
    {
        if(quality[i].size()==0)
        {
            cout<<"0";
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<quality[1].size();i++)
            dp[1][cost[1][i]]=max(dp[1][cost[1][i]],quality[1][i]);
    
        for(int i=2;i<=6;i++)
        {
            for(int j=0;j<=t;j++)
            {
                for(int k=0;k<cost[i].size();k++)
                {
                    if(j-cost[i][k]<0)
                        continue;
    	            if(dp[i-1][j-cost[i][k]]!=-1)
                	    dp[i][j]=max(dp[i][j],min(dp[i-1][j-cost[i][k]],quality[i][k]));
                }
                //cout<<i<<" "<<j<<" : "<<dp[i][j]<<"\n"; 
            }
        }
        int res=-1;
        for(int i=0;i<=t;i++)
            res=max(res,dp[6][i]);
        if(res==-1)
            res=0;
        cout<<res;
    }
}
