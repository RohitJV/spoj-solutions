#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int t,n;
long long int a[100010],dp[100010],res;

long long calc(int x)
{
    if(x>n+2)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    long long int temp;
    temp=max(a[x]+calc(x+2),a[x]+a[x+1]+calc(x+4));
    temp=max(temp,a[x]+a[x+1]+a[x+2]+calc(x+6));
    dp[x]=temp;
    return dp[x];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        res=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(n<=3)
        {
            for(int i=0;i<n;i++)
                res+=a[i];
            printf("%lld\n",res);
        }
        else
        {
            dp[n]=dp[n+1]=dp[n+2]=0;
            dp[n-1]=a[n-1];
            dp[n-2]=dp[n-1]+a[n-2];
            dp[n-3]=dp[n-2]+a[n-3];
            printf("%lld\n",calc(0));
        }
    }
}
