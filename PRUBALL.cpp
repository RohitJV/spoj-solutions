#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
#define MAX 100000
 
int t,n,b,m;
int dp[55][1005];
 
int calc(int x,int y)
{
    if(dp[x][y]!=-1)
                return dp[x][y];
        int res=MAX,temp;
        if(x>y)
        	return dp[y][y];
        if(y==1)
        {
                dp[x][y]=1;
                return dp[x][y];
        }
        for(int i=1;i<=y;i++)
        {
                if(i==1)
                        temp=max(1,calc(x,y-1)+1);
                else if(i==y)
                        temp=max(1,calc(x-1,y-1)+1);
                else
                        temp=max(calc(x-1,i-1)+1,calc(x,y-i)+1);
                res=min(res,temp);
        }
        dp[x][y]=res;
        return res;
}
 
int main()
{
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=1000;i++)
                dp[1][i]=i;
        for(int i=1;i<=50;i++)
        {
                for(int j=1;j<=1000;j++)
                {
                        dp[i][j]=calc(i,j);
                }
        }
        cin>>t;
        while(t--)
        {
                cin>>n>>b>>m;
                cout<<n<<" "<<dp[b][m]<<"\n";
        }
}
