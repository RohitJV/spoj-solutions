#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[105][105],x,y,r,c,a[105][105],res;

int main()
{
	while(scanf("%d",&r)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&c);
		scanf("%d%d",&x,&y);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				scanf("%d",&a[i][j]);
		for(int i=x;i<=r;i++)
		{
			for(int j=y;j<=c;j++)
			{
				if(i==x && j==y)
					dp[i][j]=a[i][j];
				else if(i==x)
					dp[i][j]=dp[i][j-1]-a[i][j];
				else if(j==y)
					dp[i][j]=dp[i-1][j]-a[i][j];
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1])-a[i][j];
				//cout<<dp[i][j]<<" ";
			}
			//cout<<"\n";
		}
		if(dp[r][c]<0)
			printf("N\n");
		else
			printf("Y %d\n",dp[r][c]);
	}
}

