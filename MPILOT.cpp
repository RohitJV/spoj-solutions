#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 
int dp[2][100005],a[100005],b[100005],cur=0;
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    dp[1][0]=0;
    for(int i=1;i<=n/2;i++)
    {
        dp[cur][0]=dp[(cur+1)%2][0]+b[i-1];
        for(int j=1;j<=i;j++)
        {
            if(j==i)
                dp[cur][j]=dp[cur][j-1]+a[i+j-1];
            else
                dp[cur][j]=min(dp[cur][j-1]+a[i+j-1],dp[(cur+1)%2][j]+b[i+j-1]);
        }
        cur=(cur+1)%2;
    }
    printf("%d",dp[(cur+1)%2][n/2]);
 }
