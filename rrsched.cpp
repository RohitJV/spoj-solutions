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

long long x,ans[500005];
int tree[500005],n;
vector < pair<long long,int> > v;
pair<long long,int> p;

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
    freopen("input.txt","r",stdin);

    cin>>n;
    memset(tree,0,sizeof(tree));

    //Initialize the tree
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.pb(mp(x,i+1));
    }
    sort(v.begin(),v.end());
    v.pb(mp(0,0));

    //Query and Update
    int m=n,j;
    long long prev=0,store=0;
    for(int i=0;i<n;i=j)
    {
        long long temp=v[i].X;
        for(j=i;v[j].X==temp;j++)
        {
            ans[v[j].Y]=store+(temp-prev-1)*m+v[j].Y-read(v[j].Y)+(j-i);
            update(v[j].Y,1);
        }
        store=store+(temp-prev)*m;
        m=m-(j-i);
        prev=temp;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i+1]<<"\n";
}

