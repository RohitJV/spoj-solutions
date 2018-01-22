#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
using namespace std;

#define mp make_pair
#define pb push_back

int inf=5000000,MAX=0;
int t,n,k;
int store[10001],inp[10001];
map <int,int> map1;
int tree[60][10001],vis[60][10001];

//Query
int read(int a[],int idx)
{
    if(a==tree[0])
        return 1;
    int sum=0;
    while(idx>0)
    {
        if( (sum+=a[idx]) >= inf)
            sum=sum-inf;
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int a[],int idx,int val)
{
    while(idx<MAX)
    {
        if( (a[idx]+=val) >= inf )
            a[idx]-=inf;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inp[i]);
        store[i]=inp[i];
    }
    sort(inp,inp+n);
    map1[inp[0]]=++MAX;
    for(int i=1;i<n;i++)
    {
        if(inp[i]==inp[i-1])
            map1[inp[i]]=MAX;
        else
            map1[inp[i]]=++MAX;
    }
    ++MAX;

    for(int i=0;i<n;i++)
    {
        int temp=map1[store[i]];
        for(int j=0;j<k;j++)
        {
            int x=read(tree[j],temp-1);
            int y=vis[j][temp-1];
            if(x!=y)
            {
                vis[j][temp-1]=x;
                x=x-y;
                if(x<0)
                    x=x+inf;
                update(tree[j+1],temp,x);
            }
        }
    }
    printf("%d\n",read(tree[k],MAX-1));
}

