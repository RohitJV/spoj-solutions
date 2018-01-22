#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 100005
#define MOD 1000000000
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);

long long n,m,rank[MAX],parent[MAX],sz[MAX],x,y,z,res=0,sum[MAX],sumedges[MAX];
typedef pair<long long,long long> pii;
typedef pair<long long,pii> piii;
vector <piii> v;


void initialize()
{
    for(int i=1;i<=n;i++)
    {
        rank[i]=0;
        sz[i]=1;
        parent[i]=i;
        sumedges[i]=0;
    }
}

long long find(long long x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}

void merge(long long x,long long y,long long z)
{
    long long px=find(x);
    long long py=find(y);
    long long f;
    if(px==py)
        return;
    else
        f=sz[px]*sz[py];
    res=(res+(f*z)%MOD)%MOD;

    // Union
    if(rank[px] > rank[py])
    {
        parent[py]=px;
        sz[px]=sz[px]+sz[py];
        //cout<<sz[px]<<"\n";
    }
    else
    {
        parent[px]=py;
        sz[py]=sz[py]+sz[px];
        //cout<<sz[py]<<"\n";
    }
    if(rank[px]==rank[py])
        rank[py]++;
    //cout<<"res : "<<res<<"\n";
}

int main()
{
    //fi;
    cin>>n>>m;
    initialize();
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        pii temp=pii(x,y);
        v.pb(piii(z,temp));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=m-1;i>=0;i--)
    {
        if(i==m-1)
            sum[i]=v[i].X;
        else
            sum[i]=sum[i+1]+v[i].X;
    }
    for(int i=0;i<m;i++)
        merge(v[i].Y.X,v[i].Y.Y,sum[i]);
    cout<<res<<"\n";
}
