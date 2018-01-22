#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[2010][2010],n,a[2010],s[2010];

int calc(int x,int y)
{
	int res=-1;
	if(x>n)
		return 0;
	if(y>n)
		return calc(x,n);
	if(dp[x][y]!=0)
		return dp[x][y];
	for(int i=x;i<=n;i++)
	{
		dp[x][i]=max(dp[x][i-1],s[i]-s[x-1] + s[n]-s[i]-calc(i+1,i+(i-x+1)*2));
		//cout<<x<<" "<<i<<" : "<<dp[x][i]<<" "<<s[i]-s[x-1] + s[n]-s[i]<<"\n";
	}
	return dp[x][y];
}

int main()
{
	memset(dp,0,sizeof(dp));
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cout<<calc(1,2);
}
