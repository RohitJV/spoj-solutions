#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
 
int n,k,t,a[505],ans=-1;
int dp[505][505];
 
int calc(int x,int y)
{
    int smin=200;
    if(y==0 || x<0)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    int temp=calc(x-1,y);
    for(int i=0;i<t;i++)
    {
        if(x-i < 0)
            break;
        smin=min(smin,a[x-i]);
        temp=max(temp,smin*(i+1)+calc(x-i-1,y-1));
    }
    dp[x][y]=temp;
    return dp[x][y];
}
 
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k>>t;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=k;i>0;i--)
        ans=max(ans,calc(n-1,i));
    cout<<ans;
}
