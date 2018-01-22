#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
 
#define INF 1000000
 
int t,n,m,x,y,adj[400][400],store,visited[400],prev[400],temp,path_capacity;
 
int bfs()
{
    int flag=0;
    queue <int> q;
    visited[350]=1;
    q.push(350);
    
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=0;i<400;i++)
        {
            if(!visited[i] && adj[temp][i]>0)
            {
                //cout<<i<<" ";
                visited[i]=1;
                q.push(i);
                prev[i]=temp;
                if(i==351)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            break;
    }
    if(flag==0)
        return -1;
    int cur=351,path_cap=INF;
    while(prev[cur]!=-1)
    {
        temp=prev[cur];
        path_cap=min(path_cap,adj[temp][cur]);
        cur=temp;
    }
    cur=351;
    while(prev[cur]!=-1)
    {
        temp=prev[cur];
        adj[temp][cur]-=path_cap;
        adj[cur][temp]+=path_cap;
        cur=temp;
    }
    return path_cap;
}
 
int maxflow()
{
    int result=0;
    while(1)
    {
        memset(visited,0,sizeof(visited));
        memset(prev,-1,sizeof(prev));
        path_capacity=bfs();
        if(path_capacity == -1)
            break;
        result = result + path_capacity;
        //getch();
        //cout<<"\n";
    }
    return result;
}
 
int main()
{
    cin>>t;
    while(t--)
    {
        memset(adj,0,sizeof(adj));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            adj[350][x]=adj[150+y][351]=1;
            adj[x][150+y]=1;
        }
        cout<<maxflow()<<"\n";
    }
}
