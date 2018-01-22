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
#define X first
#define Y second

long long x,ans[500005],prev,temp,store;
int tree[500005],n,t;
vector < pair<long long,int> > v;
pair<long long,int> p;

//Query
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx,int val)
{
    while(idx<=n)
    {
        tree[idx]=tree[idx]+val;
        idx = idx + (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);

    //Initialize the tree
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        v.pb(mp(x,i+1));
    }
    sort(v.begin(),v.end());
    v.pb(mp(0,0));

    //Query and Update
    int m=n,j;
    for(int i=0;i<n;i=j)
    {
        temp=v[i].X;
        for(j=i;v[j].X==temp;j++)
        {
            t=v[j].Y;
            ans[t]=store+(temp-prev-1)*m+t-read(t)+j-i;
            update(t,1);
        }
        store=store+(temp-prev)*m;
        m=m-j+i;
        prev=temp;
    }
    for(int i=0;i<n;i++)
        printf("%lld\n",ans[i+1]);
}






