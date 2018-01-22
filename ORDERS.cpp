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
#define INF 0

struct node
{
    int x,y;
}tree[1000000];

int n,q,t,a[1000000];
vector <int> v;

void build(int idx,int l,int h)
{
    if(l==h)
    {
        tree[idx].x=1;
        tree[idx].y=h+1;
        return;
    }
    int mid=(l+h)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,h);
    tree[idx].x=tree[idx*2].x+tree[idx*2+1].x;
    tree[idx].y=-1;
    return;
}

int update(int idx,int k)
{
    if(tree[idx].x==1 && tree[idx].y!=-1)
    {
        tree[idx].x=0;
        return tree[idx].y;
    }
    int temp;
    if(tree[idx*2].x >= k)
        temp=update(idx*2,k);
    else
        temp=update(idx*2+1,k-tree[idx*2].x);
    tree[idx].x=tree[idx*2].x+tree[idx*2+1].x;
    return temp;
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        build(1,0,n-1);
        for(int i=n;i>0;i--)
            v.pb(update(1,i-a[i-1]));
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<"\n";
    }
}
