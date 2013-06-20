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
    int mirrors;
    int dir;
    cord() {x=y=mirrors=dir=-1;}
    cord(int _x,int _y,int _m,int _d) {x=_x; y=_y; mirrors=_m; dir=_d; }
};
 
bool valid(cord temp)
{
    if(temp.x>=0 && temp.x<h && temp.y>=0 && temp.y<w && s[temp.x][temp.y]!='*')
        return true;
    return false;
}
 
int bfs(cord s1)
{
    int res=1000000;
    queue <cord> q;   
    q.push(s1);
    cord temp,first;
    memset(visited,1000000,sizeof(visited));
    while(!q.empty())
    {
        first=q.front();
        q.pop();
        
        if(!valid(first))
            continue;
        //cout << endl << first.x << "," << first.y << "   " << first.mirrors << "  " << first.dir;
        if(s[first.x][first.y]=='E' && first.mirrors<res)
        {
            res=first.mirrors;
            continue;
        }
            
        
        if(first.mirrors <= visited[first.x][first.y])
            visited[first.x][first.y]=first.mirrors;
        else
            continue;
            
        int x=first.x;
        int y=first.y;
        int m=first.mirrors;
        int d=first.dir;
        
        if(d==0)
        {
            q.push( cord(x-1,y,m+1,1) );
            q.push( cord(x,y+1,m+1,2) );
            q.push( cord(x+1,y,m+1,3) );
            q.push( cord(x,y-1,m+1,4) );
        }
        else if(d==1)
        {
            q.push( cord(x-1,y,m,1) );
            q.push( cord(x,y-1,m+1,4) );
            q.push( cord(x,y+1,m+1,2) );
        }
        else if(d==2)
        {
            q.push( cord(x-1,y,m+1,1) );
            q.push( cord(x,y+1,m,2) );
            q.push( cord(x+1,y,m+1,3) );
        }
        else if(d==3)
        {
            q.push( cord(x,y+1,m+1,2) );
            q.push( cord(x+1,y,m,3) );
            q.push( cord(x,y-1,m+1,4) );
        }
        else if(d==4)
        {
            q.push( cord(x+1,y,m+1,3) );
            q.push( cord(x,y-1,m,4) );
            q.push( cord(x-1,y,m+1,1) );
        }
    }
    return res;
}
 
int main()
{
    cord temp;
    cin>>w>>h;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='C')
            {
                if(!flag)
                {
                    flag=1;
                    temp.x=i;
                    temp.y=j;
                    temp.mirrors=-1;
                    temp.dir=0;
                }
                else
                    s[i][j]='E';
            }
        }
    }
    flag=0;
    int res=bfs(temp);
    cout<<res;
}
