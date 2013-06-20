#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
int x,y,check[10005],volume;
 
struct node
{
    int gap,size,ele;
};
 
queue <node> q[10005];
 
node dfs(node cur)
{
    node temp,first,res;
    temp.size=temp.gap=0;
    check[cur.ele]=1;
    int size=q[cur.ele].size();
    first=q[cur.ele].front();
    if(size==1 && check[first.ele])
    {
            temp.size=temp.gap=1;
            q[cur.ele].pop();
            volume++;
            return(temp);
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            first=q[cur.ele].front();
            q[cur.ele].pop();
            if(!check[first.ele])
            {
                check[first.ele]=1;
                temp.ele=first.ele;
                res=dfs(temp);
                temp.size=temp.size+res.size+res.gap;
            }
        }
        temp.size=temp.size+1;
        temp.gap=1;
        volume+=temp.size;
        return(temp);
    }
}
 
int main()
{
    node temp;
    int t,n;
    cin>>t;
    while(t--)
    {
        volume=0;
        memset(check,0,sizeof(check));
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            cin>>x>>y;
            temp.ele=y;
            temp.gap=temp.size=0;
            q[x].push(temp);
            temp.ele=x;
            q[y].push(temp);
        }
        check[0]=1;
        temp.ele=0;
        temp=dfs(temp);
        cout<<volume<<"\n";
    }
}
