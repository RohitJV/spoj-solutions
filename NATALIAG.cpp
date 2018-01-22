#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;   

int t,m,n,cnt;
char a[105][105];
bool visited[105][105],flag;

struct node
{
	int x,y,c;
	node() { x=y=c=-1; };
	node(int x1,int y1,int c1) { x=x1; y=y1; c=c1; };
};

bool valid(node u)
{
	if(u.x>=0 && u.x<m && u.y>=0 && u.y<n)
	{
		if(a[u.x][u.y]=='*')
			return false;
		return true;
	}
	return false;
}

void bfs(node start)
{
	node u;
	queue <node> q;
	q.push(start);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(!valid(u))
			continue;
		if(visited[u.x][u.y])
			continue;
		visited[u.x][u.y]=true;
		if(a[u.x][u.y]=='#')
		{
			flag=true;
			cnt=u.c;
			break;
		}
		q.push( node(u.x-1,u.y,u.c+1) );
		q.push( node(u.x+1,u.y,u.c+1) );
		q.push( node(u.x,u.y-1,u.c+1) );
		q.push( node(u.x,u.y+1,u.c+1) );
	}
}

int main()
{
	node start;
	scanf("%d",&t);
	while(t--)
	{
		flag=false;
		memset(visited,false,sizeof(visited));
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				//scanf("%c",&a[i][j]);
				cin>>a[i][j];
				if(a[i][j]=='$')
					start=node(i,j,0);
			}
		}
		bfs(start);
		if(!flag)
			cnt=-1;
		printf("%d\n",cnt);
	}
}

