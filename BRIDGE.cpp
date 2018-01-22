#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair

int a[1005],b[1005],n,t,x,dp[1005][1005];

int main() 
{
	scanf("%d",&t);
	while(t--)
	{
		vector < pair<int,int> > v1,v2,v;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
			v.pb(mp(a[i],b[i]));
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
			v1.pb(mp(v[i].first,i));
		for(int i=0;i<n;i++)
			v2.pb(mp(v[i].second,i));
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		for(int i=0;i<n;i++)
		{
			a[i]=v1[i].second;
			b[i]=v2[i].second;
		}
		for(int i=0;i<n;i++)
			dp[i][0]=dp[0][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
					dp[i][j]=1+max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[n][n]);
	}
	// your code goes here
	return 0;
}
