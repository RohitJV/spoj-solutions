#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;

#define mp make_pair
#define pb push_back

int t,n,ans,x,y,a,b;
int store[100005],tree[100005];

//Query
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx,int val)
{
    while(idx<=100005)
    {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        //Query and Update
        a=read(x);
        b=read(y);
        ans=a+b-store[x]-store[y];
        store[x]=a;
        store[y]=b;
        update(x+1,1);
        update(y,-1);
        printf("%d\n",ans);
    }
}
