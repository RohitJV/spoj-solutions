#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

long long tree[200005],a[200005],b[200005],ans;
map <long long,int> m;
int t,n;

long long read(int idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx,int val)
{
    while(idx<=n+2)
    {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0;i<n;i++)
            m[b[i]]=i+1;
        for(int i=n-1;i>=0;i--)
        {
            ans=ans+read(m[a[i]]);
            update(m[a[i]],1);
        }
        cout<<ans<<"\n";
    }
}


