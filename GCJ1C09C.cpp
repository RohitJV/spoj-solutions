#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
#define INF 1000000
 
int dp[200][200],t,p,n,a[200];
 
int calc(int x,int y)
{
    //cout<<x<<" "<<y<<"\n";
    if(dp[x][y]!=INF)
    {
        //cout<<"found : "<<dp[x][y]<<"\n";
            return(dp[x][y]);
    }
        if(y==x+1)
        {
                dp[x][y]=0;
                return(dp[x][y]);
        }
        for(int i=x+1;i<y;i++)
                dp[x][y]=min(dp[x][y],a[y]-a[x]-2+calc(x,i)+calc(i,y));
        return(dp[x][y]);
}
 
int main()
{
        scanf("%d",&t);
        for(int cas=1;cas<=t;cas++)
        {
                for(int i=0;i<200;i++)
            for(int j=0;j<200;j++)
                dp[i][j]=INF;
                a[0]=0;
                scanf("%d%d",&p,&n);
                a[n+1]=p+1;
                for(int i=1;i<=n;i++)
                        scanf("%d",&a[i]);
                printf("Case #%d: %d\n",cas,calc(0,n+1));
        }
}
