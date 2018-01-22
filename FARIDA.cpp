#include<iostream>
#include<stdio.h>
using namespace std;

int t,n,a[10005];
unsigned long long int dp[10005],res;

unsigned long long int max(unsigned long long int x,unsigned long long int y)
{
    return (x > y ? x : y) ;
}

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%d", &a[i]);
        if(n==0)
            res=0;
        else if(n==1)
            res=a[0];
        else
        {
            dp[0]=a[0];
            dp[1]=a[1];
            for(int i=2;i<n;i++)
                dp[i]=max(dp[i-1],dp[i-2]+a[i]);
            res=dp[n-1];
        }
        printf("Case %d: %llu\n", cas, dp[n-1]);
    }
}