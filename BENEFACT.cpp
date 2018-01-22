#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<queue>
//#include<conio.h>
using namespace std;
 
int check[50005];
int maxd,maxe;
 
struct node
{
    int ele,wt;  
};
 
void dfs(node a,queue <node> q[50005],int sum)
{
    node temp;
    while(!q[a.ele].empty())
    {
        check[a.ele]=1;
        temp=q[a.ele].front();
        //cout<<temp.ele<<" "<<sum<<"\n";
        //getch();
        if(!check[temp.ele])
        {
            check[temp.ele]=1;
            dfs(temp,q,sum+temp.wt);     
            if(sum+temp.wt > maxd)
            {
                maxd=sum+temp.wt;
                maxe=temp.ele;
            }
        }
        q[a.ele].pop();
    }
}
 
int main()
{
    node newnode;
    int t,n,x[50005],y[50005],w[50005];
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(check,0,sizeof(check));
        queue <node> q1[50005];
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            cin>>x[i]>>y[i]>>w[i];
            x[i]--;
            y[i]--;
            newnode.ele=y[i];
            newnode.wt=w[i];
            q1[x[i]].push(newnode);
            //q2[x].push(newnode);
            newnode.ele=x[i];
            q1[y[i]].push(newnode);
            //q2[y].push(newnode);
        }
        maxd=0;
        newnode.ele=0;
        newnode.wt=0;
        dfs(newnode,q1,0);
        maxd=0;
        memset(check,0,sizeof(check));
        /*for(int i=0;i<n;i++)
        {
                if(q1[i].empty())
                                cout<<"YES\n";
                else
                    cout<<"NO\n";
        }*/
        for(int i=0;i<n-1;i++)
        {
            newnode.ele=y[i];
            newnode.wt=w[i];
            q1[x[i]].push(newnode);
            //q2[x].push(newnode);
            newnode.ele=x[i];
            q1[y[i]].push(newnode);
            //q2[y].push(newnode);
        }
        newnode.ele=maxe;
        newnode.wt=0;
        dfs(newnode,q1,0);
        //cout<<"Case "<<cas<<": "<<maxd<<"\n";
        cout<<maxd<<"\n";
    }
    //getch();
}