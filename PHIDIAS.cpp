#include<iostream>
#include<stdio.h>
using namespace std;
#define INF -1
 
int dp[610][610],ht[250],wt[250],n;
 
int calc(int x,int y)
{
    //cout<<x<<" "<<y<<"\n";
    int m=1000000,temp;
    if(dp[x][y]!=INF)
        return(dp[x][y]);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(wt[i]<=x && ht[i]<=y)
        {
                flag=1;
                temp=min( calc(x,y-ht[i])+calc(x-wt[i],ht[i]) , calc(x-wt[i],y)+calc(wt[i],y-ht[i]) );
                if(temp<m)
                    m=temp;
        }   
    }
    if(flag==0)
    {
        dp[x][y]=x*y;
        return(dp[x][y]);
    }
    else
    {
        dp[x][y]=m;
        return(dp[x][y]);
    }
}
 
int main()
{
    int h,w,t;
    cin>>t;
    while(t--)
    {
        cin>>w>>h;
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>wt[j]>>ht[j];
        for(int i=0;i<=w;i++)
            for(int j=0;j<=h;j++)
                dp[i][j]=INF;
        cout<<calc(w,h)<<"\n";
    }
}
