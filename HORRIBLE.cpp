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
    long long int lazy;
    int flag;
    long long int value;
}tree[60000000],inf;

int n,q,t,w,x,y;
long long int z;

void build(int idx,int l,int h)
{
    if(l==h)
    {
        tree[idx].value=tree[idx].flag=tree[idx].lazy=0;
        //tree[idx*2].value=tree[idx*2].flag=tree[idx*2].lazy=0;
        //tree[idx*2+1].value=tree[idx*2+1].flag=tree[idx*2+1].lazy=0;
        return;
    }
    int mid=(l+h)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,h);
    tree[idx].value=tree[idx].flag=tree[idx].lazy=0;
    return;
}

void propagate(int idx,int l,int h)
{
    tree[idx*2].flag=tree[idx*2+1].flag=1;
    tree[idx].flag=0;
    tree[idx*2].lazy+=tree[idx].lazy;
    tree[idx*2+1].lazy+=tree[idx].lazy;
    tree[idx].value=tree[idx].value+((h-l+1)*tree[idx].lazy);
    tree[idx].lazy=0;
}

node query(int idx,int u,int v,int l,int h)
{
    if(tree[idx].flag)
        propagate(idx,l,h);
    if(v<l || u>h)
        return inf;
    if(l>=u && h<=v)
        return tree[idx];
    int mid=(l+h)/2;
    node a=query(idx*2,u,v,l,mid);
    node b=query(idx*2+1,u,v,mid+1,h);
    node temp;
    temp.value=a.value+b.value;
    return temp;
}

void update(int idx,int i,int j,int l,int h,long long int val)
{
    if(tree[idx].flag)
        propagate(idx,l,h);
    if(j<l || i>h)
        return;
    if(l>=i && h<=j)
    {
        tree[idx].value=tree[idx].value+(val*(h-l+1));
        tree[idx*2].flag=tree[idx*2+1].flag=1;
        tree[idx*2].lazy+=val;
        tree[idx*2+1].lazy+=val;
        return;
    }
    int mid=(l+h)/2;
    update(idx*2,i,j,l,mid,val);
    update(idx*2+1,i,j,mid+1,h,val);
    tree[idx].value=tree[idx*2].value+tree[idx*2+1].value;
}

int main()
{
    //freopen("input2.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    cin>>t;
    inf.value=0;
    while(t--)
    {
        cin>>n>>q;
        build(1,0,6*(n-1));
        while(q--)
        {
            cin>>w;
            if(w==0)
            {
                cin>>x>>y>>z;
                update(1,x-1,y-1,0,n-1,z);
            }
            if(w==1)
            {
                cin>>x>>y;
                cout<<query(1,x-1,y-1,0,n-1).value<<"\n";
            }
        }
    }
}
