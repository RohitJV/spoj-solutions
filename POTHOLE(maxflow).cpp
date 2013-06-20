#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
 
#define INF 1000000
 
int t,n,m,x,y,adj[205][205],store,visited[205],prev[205],temp,path_capacity;
 
int bfs()
{
    int flag=0;
    queue <int> q;
    visited[1]=1;
    q.push(1);
    
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && adj[temp][i]>0)
            {
                visited[i]=1;
                q.push(i);
                prev[i]=temp;
                if(i==n)
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
    int cur=n,path_cap=INF;
    while(prev[cur]>0)
    {
        temp=prev[cur];
        path_cap=min(path_cap,adj[temp][cur]);
        cur=temp;
    }
    cur=n;
    while(prev[cur]>0)
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
        memset(prev,0,sizeof(prev));
        path_capacity=bfs();
        if(path_capacity == -1)
            break;
        result = result + path_capacity;
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
        for(int i=1;i<n;i++)
        {
            cin>>m;
            if(i==1)
                store=m;
            while(m--)
            {
                cin>>x;
                if(i==1 || x==n)
                    adj[i][x]=1;
                else
                    adj[i][x]=store;
            }
        }
        cout<<maxflow()<<"\n";
    }
}
