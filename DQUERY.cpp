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
#define INF 1000000

int t,n,q,x,y;
int a[100005],b[100005],tree[100005];
int cur[1000005],r[100005];
bool vis[1000005];
int ans[300000];
vector < pair< pair<int,int>,int > > v;

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
    while(idx<=n)
    {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    memset(cur,INF,sizeof(cur));
    scanf("%d",&n);

    //Initialize the tree
    a[0]=tree[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=n;i>0;i--)
    {
        r[i]=cur[a[i]];
        cur[a[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[a[i]])
        {
            b[i]=b[i-1]+1;
            vis[a[i]]=true;
        }
        else
            b[i]=b[i-1];
        tree[i]=b[i]-b[i-(i & -i)];
    }

    //Get and Sort Queries
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        v.pb(mp(mp(x,y),i));
    }
    sort(v.begin(),v.end());

    //Query and Update
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        while((v[pos].X).X==i)
        {
            ans[(v[pos].Y)]=read((v[pos].X).Y);
            pos++;
        }
        update(i,-1); //Unmark
        update(r[i],1);  //Mark
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<"\n";
}
