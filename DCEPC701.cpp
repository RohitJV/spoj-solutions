#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
 
#define pb push_back
 
int t,n,m,a[250][250],x1,y1,x2,y2,store,tym,visited[250][250];
char s[250][250];
 
struct node
{
    int x,y;
    node() { x=-1; y=-1; }
    node(int u,int v) { x=u; y=v; }
};
 
vector<node> v[10005];
 
bool valid(node u)
{
    if(u.x>=0 && u.y>=0 && u.x<n && u.y<m)
    {
        if(s[u.x][u.y]!='#')
            return true;
    }
    return false;
}
 
void bfs(int p,int q)
{
    vector <node> w;
    node start(p,q);
    node u;
    w.pb(start);
    while(1)
    {   
        for(int i=0;i<w.size();i++)
        {
            if(w[i].x==x2 && w[i].y==y2)
            {
                cout<<tym<<"\n";
                return;
            }
        }
        tym++;
        int store=w.size();
        for(int i=0;i<v[tym].size();i++)
        {
            u=v[tym][i];
            s[u.x][u.y]='.';
            if(u.x-1>=0)
                visited[u.x-1][u.y]=0;
            if(u.x+1 <n)
                visited[u.x+1][u.y]=0;
            if(u.y-1>=0)
                visited[u.x][u.y-1]=0;
            if(u.y+1<m)
                visited[u.x][u.y+1]=0;
        }
        for(int i=0;i<store;i++)
        {
            u=w[i];
            if(visited[w[i].x][w[i].y])
                continue;
            visited[w[i].x][w[i].y]=1;
            
            if(valid(node(u.x-1,u.y)))
                w.pb( node(u.x-1,u.y) );
            if(valid(node(u.x+1,u.y)))
                w.pb( node(u.x+1,u.y) );
            if(valid(node(u.x,u.y-1)))
                w.pb( node(u.x,u.y-1) );
            if(valid(node(u.x,u.y+1)))
                w.pb( node(u.x,u.y+1) );
        }
    }
}
 
int main()
{
    node def(-1,-1);
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        tym=0;
        for(int i=0;i<10005;i++)
            v[i].clear();
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>s[i][j];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                node temp(i,j);
                v[a[i][j]].pb(temp);
            }
        }
        cin>>x1>>y1>>x2>>y2;
        bfs(x1,y1);
    }
}
