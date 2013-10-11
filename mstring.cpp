#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 2000

string a,b;
int m,n,dp[1005][1005];

int calc(int x,int y)
{
    if(x==m)
        return INF;
    if(dp[x][y]!=-1)
        return dp[x][y];
    for(int i=y;i<n;i++)
    {
        if(b[i]==a[x])
        {
            dp[x][y]=min(calc(x+1,y),1+calc(x+1,i+1));
            return(dp[x][y]);
        }
    }
    return 1;
}

int main()
{
    cin>>a>>b;
    m=a.length();
    n=b.length();
    memset(dp,-1,sizeof(dp));
    cout<<calc(0,0);
}
