#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
int dp[100005],a[100005],b[100005],m,n;
 
int calc(int s[100005],int x)
{
    if(x>=n)
        return(0);
    if(dp[x])
        return(dp[x]);
    else
    {
        dp[x]=max(s[x]+calc(s,x+2),calc(s,x+1));
        return(dp[x]);
    }
}
 
int main()
{
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0 && n==0)
            break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%d",&a[j]);
            fill(dp,dp+n,0);
            b[i]=calc(a,0);
        }
        fill(dp,dp+m,0);
        n=m;
        printf("%d\n",calc(b,0));
    }
}
