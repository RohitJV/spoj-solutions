#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

#define pb push_back
#define MAX 1000007
#define fi freopen("input.txt","r",stdin)

int n,m,c;
int parent[30],rnk[30],setcount;

struct Edge
{
	int u,v,cost;
     Edge(int u1,int v1,int c1) {u=u1; v=v1; cost=c1;}
};

vector <Edge> edges;

void initialize()
{
	for(int i=0;i<30;i++)
	{
		parent[i]=i;
		rnk[i]=0;
	}
	setcount=n;
}

int UnionFind(int x)
{
     if(parent[x]!=x)
          parent[x]=UnionFind(parent[x]);
     return parent[x];
}

void UnionMerge(int x,int y)
{
     int x1=UnionFind(x),y1=UnionFind(y);
     if(x1==y1)
          return;
     if(rnk[x1]<rnk[y1])
          parent[x]=y1;
     else if(rnk[y1]<rnk[y1])
          parent[y]=x1;
     else
     {
          parent[y]=x1;
          rnk[x1]++;
     }
     setcount--;
}

int solve()
{
     int deg[30],res=MAX;
     //for(int i=0;i<m;i++)
     //     cout<<edges[i].u<<","<<edges[i].v<<" : "<<edges[i].cost<<"\n";
     for(int i=1;i<(1<<m);i++)
     {
          int cost=0;
          memset(deg,0,sizeof(deg));
          //for(int i=0;i<30;i++)
          //     cout<<deg[i];
          //cout<<"\n";
          initialize();
          for(int j=0;j<m;j++)
          {
               if( i & (1<<j) )
               {
                    UnionMerge(edges[j].u,edges[j].v);
                    deg[edges[j].u]++;
                    deg[edges[j].v]++;
                    cost+=edges[j].cost;
               }
          }
          bool flag=true;
          for(int j=0;j<n;j++)
               if(deg[j]<2 || (deg[j]&1) )
                    flag=false;
          //cout<<"\n"<<setcount<<" "<<flag<<" : \n";
          if(flag && setcount==1)
               res=min(res,cost);
     }
     return res;
}

int main()
{
     //fi;
     int x,y,cost;
     for(int cas=1;;cas++)
     {
          int res=MAX;
          edges.clear();
          scanf("%d%d",&n,&m);
          if(n==0 && m==0)
               break;
          for(int i=0;i<m;i++)
          {
               scanf("%d%d%d",&x,&y,&cost);
               edges.pb(Edge(x-1,y-1,cost));
          }
          res=solve();
          if(res==MAX)
                printf("There is no reliable net possible for test case %d.\n", cas);
          else
               printf("The minimal cost for test case %d is %d.\n", cas, res);
     }
}
