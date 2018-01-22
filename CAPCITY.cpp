#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 100005
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);

int n,m,comp=0;
vector <int> Graph[MAX],GraphT[MAX];
vector <int> v;
bool mark[MAX],mark1[MAX];
int c[MAX],deg[MAX];

void dfs1(int x)
{
     if(mark[x])
          return;
     mark[x]=true;
     for(int i=0;i<Graph[x].size();i++)
          dfs1(Graph[x][i]);
     //cout<<x<<",";
     v.pb(x);
}

void dfs2(int x)
{
     if(mark1[x])
          return;
     mark1[x]=true;
     c[x]=comp;
     for(int i=0;i<GraphT[x].size();i++)
          dfs2(GraphT[x][i]);
}

int main()
{
     //ios_base::sync_with_stdio(true);
     //fi;
     int x,y;
     scanf("%d%d",&n,&m);
     //memset(mark,false,sizeof(mark));
     for(int i=0;i<m;i++)
     {
          scanf("%d%d",&x,&y);
          Graph[x].pb(y);
          GraphT[y].pb(x);
     }
     for(int i=1;i<=n;i++)
          if(!mark[i])
               dfs1(i);
     for(int i=n-1;i>=0;i--)
     {
          if(mark1[v[i]])
               continue;
          comp++;
          dfs2(v[i]);
     }
     //cout<<comp<<"\n";
     for(int i=1;i<=n;i++)
     {
          for(int j=0;j<Graph[i].size();j++)
          {
               if( c[i]!=c[Graph[i][j]] )
                    deg[c[i]]++;
          }
     }
     int temp;
     for(int i=1;i<=comp;i++)
     {
          if(deg[i]==0)
               temp=i;
     }
     int cnt=0;
     v.clear();
     for(int i=1;i<=n;i++)
     {
          if(c[i]==temp)
          {
               v.pb(i);
               cnt++;
          }
     }
     printf("%d\n",cnt);
     for(int i=0;i<v.size();i++)
          printf("%d ",v[i]);
}
