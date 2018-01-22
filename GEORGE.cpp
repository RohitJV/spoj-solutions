#include<iostream>
#include<algorithm>
using namespace std;
#define INF 1000000000;
 
int main()
{
    int n,m,a,b,k,g,gr[1000][1000],adj[1000][1000],gpath[1000],check,visited[1000],trvl[1000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=gr[i][j]=INF;
    cin>>a>>b>>k>>g;
    a--;
    b--;
    for(int i=0;i<g;i++)
    {
        cin>>gpath[i];
        gpath[i]--;
    }
    int x,y,t;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>t;
        x--;
        y--;
        adj[x][y]=adj[y][x]=t;
    }
    for(int i=1,t=0;i<g;i++)
    {
        gr[gpath[i-1]][gpath[i]]=t;
        gr[gpath[i]][gpath[i-1]]=t;
        t=t+adj[gpath[i-1]][gpath[i]];
    }
    for(int i=0;i<n;i++)
    {
        trvl[i]=INF;
        visited[i]=0;
    }
    trvl[a]=k;
    for(int i=0;i<n;i++)
    {
        check=-1;
        for(int j=0;j<n;j++)
        {
            if(visited[j])
                continue;
            if(check==-1 || trvl[j]<trvl[check])
                check=j;
        }
        visited[check]=1;
        for(int j=0;j<n;j++)
        {
            if(trvl[check] < gr[check][j])
                trvl[j]=min(adj[check][j]+trvl[check],trvl[j]);
            else
                trvl[j]=min(trvl[j],max(gr[check][j]+adj[check][j],trvl[check])+adj[check][j]);
        }
    }
    cout<<trvl[b]-trvl[a]<<"\n";
}

