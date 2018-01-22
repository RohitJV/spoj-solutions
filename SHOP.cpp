#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

char s[105][105];
int visited[105][105],w,h,flag=0;

struct cord
{
    int x,y;
    int time;
    cord() {x=y=time=-1;}
    cord(int _x,int _y,int _t) {x=_x; y=_y; time=_t; }
};

bool valid(cord temp)
{
    if(temp.x>=0 && temp.x<h && temp.y>=0 && temp.y<w && s[temp.x][temp.y]!='X')
        return true;
    return false;
}

int bfs(cord s1)
{
    int res=1000000;
    queue <cord> q;   
    q.push(s1);
    cord first;
    memset(visited,1000000,sizeof(visited));
    while(!q.empty())
    {
        first=q.front();
        q.pop();
        
        if(!valid(first))
            continue;
        
        if(first.time < visited[first.x][first.y])
        {
            visited[first.x][first.y]=first.time;
            //cout<<"valid "<<first.x<<","<<first.y<<" "<<first.time<<"\n";
        }
        else
            continue;
        
        if(s[first.x][first.y]=='D')
        {
            if(visited[first.x][first.y] < res)
                res=visited[first.x][first.y];
            continue;
        }
        
        int x=first.x;
        int y=first.y;
        int t=first.time;
        
        q.push( cord(x-1,y,t+s[x-1][y]-48) );
        q.push( cord(x,y-1,t+s[x][y-1]-48) );
        q.push( cord(x+1,y,t+s[x+1][y]-48) );
        q.push( cord(x,y+1,t+s[x][y+1]-48) );
    }
    return res;
}

int main()
{
    cord temp;
    while(1)
    {
    cin>>w>>h;
    if(w==0 && h==0)
        break;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='S')
            {
                temp.x=i;
                temp.y=j;
                temp.time=0;
            }
        }
    }
    int res=bfs(temp);
    cout<<res+48-'D'<<"\n";
    }
}