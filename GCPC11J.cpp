#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pb push_back
#define INF 1000000

int t,n,x,y,ans,node;
vector <int> v[100005];
bool visited[100005];

void dfs(int x,int pos)
{
	visited[x]=true;
	if(pos>ans)
	{
		ans=pos;
		node=x;
	}
	for(int i=0;i<v[x].size();i++)
	{
		if(!visited[v[x][i]])
			dfs(v[x][i],pos+1);
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		node=0;
		ans=0;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<100005;i++)
			v[i].clear();
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(0,0);
		//cout<<node<<" ";
		ans=0;
		memset(visited,false,sizeof(visited));
		dfs(node,0);
		if(ans%2)
			cout<<ans/2+1<<"\n";
		else
			cout<<ans/2<<"\n";
	}
}
