#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[1005][1005],t,n,k,s[1005];

int calc(int a,int b)
{
	if(dp[a][b]!=-1)
		return(dp[a][b]);
	if(b>=n)
		return 0;
	int res;
	if(s[b]<=a)
		res=max(s[b]+calc(a-s[b],b+2),calc(a,b+1));
	else
		res=calc(a,b+1);
	dp[a][b]=res;
	return(dp[a][b]);
}

int main()
{
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>s[i];
		cout<<"Scenario #"<<cas<<": "<<calc(k,0)<<"\n";
	}
}
