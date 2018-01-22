#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 
int dp[100005],n,m,a[100005],b[100005],pos[100005],pos1=0,cumu[100005];
 
int calc(int ini,int posi)
{
    if(dp[ini])
    {
        if(dp[ini]==-1)
            return 0;
        return(dp[ini]);
    }
    if(posi>=pos1)
    {
        dp[ini]=-1;
        return 0;
    }
    if(ini < pos[posi]-b[pos[posi]]+1)
    {
        dp[ini]=calc(ini+1,posi);
        return(dp[ini]);
    }
    else
    {
        if(ini+b[pos[posi]]-1<=n && ini+b[pos[posi]]-1<pos[posi+1] && ini<=pos[posi])
                dp[ini]=max(calc(ini+1,posi),cumu[ini+b[pos[posi]]-1]-cumu[ini]+a[ini]+calc(ini+b[pos[posi]],posi+1));
        return(dp[ini]);
    }
}
 
int main()
{
    int x,y;
    scanf("%d",&n);
    scanf("%d",&a[1]);
    cumu[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cumu[i]=cumu[i-1]+a[i];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        b[x]=y;
    }
    for(int i=0;i<=n;i++)
    {
        if(b[i])
            pos[pos1++]=i;      
    }
    pos[pos1]=n+1;
    printf("%d",calc(1,0));
}


