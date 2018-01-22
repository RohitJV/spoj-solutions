#include<stdio.h>
#include<iostream>
using namespace std;
int n,s[100000];
 
struct node
{
        int l,r;
        int lsum,rsum;
        int best;
}inf,tree[1000000];
 
void build(int i,int l,int h)
{
        if(l==h)
        {
                tree[i].lsum=tree[i].rsum=tree[i].best=1;
                tree[i].l=tree[i].r=s[l];
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        tree[i].lsum=(tree[2*i].l==tree[2*i+1].l ? tree[2*i].lsum+tree[2*i+1].lsum : tree[2*i].lsum);
        tree[i].rsum=(tree[2*i].r==tree[2*i+1].r ? tree[2*i].rsum+tree[2*i+1].rsum : tree[2*i+1].rsum);
        tree[i].l=tree[2*i].l;
        tree[i].r=tree[2*i+1].r;
        int m=0;
        if(tree[2*i].r==tree[2*i+1].l)
            m=tree[2*i].rsum+tree[2*i+1].lsum;
        int temp=max(m,max(tree[i].lsum,tree[i].rsum));
        tree[i].best=max(temp,max(tree[2*i].best,tree[2*i+1].best));
        return;
}
 
node query(int in,int i,int j,int u,int v)
{
        if(v<i || u>j)
                return(inf);
        if(i<=u && j>=v)
                return(tree[in]);
        int mid=(u+v)/2;
        node a=query(2*in,i,j,u,mid);
        node b=query(2*in+1,i,j,mid+1,v);
        node temp;
        temp.lsum=(a.l==b.l ? a.lsum+b.lsum : a.lsum);
        temp.rsum=(a.r==b.r ? a.rsum+b.rsum : b.rsum);
        temp.l=a.l;
        temp.r=b.r;
        int m=0;
        if(a.r==b.l)
            m=a.rsum+b.lsum;
        int temp1=max(m,max(temp.lsum,temp.rsum));
        temp.best=max(temp1,max(a.best,b.best));
        return(temp);
} 
 
int main()
{
        inf.rsum=inf.lsum=inf.best=-1;
        inf.r=inf.l=-100009;
        int x,y,m;
        while(1)
        {   
            scanf("%d",&n);
            if(n==0)
                break;
            scanf("%d",&m);
            for(int i=0;i<n;i++)
                scanf("%d",&s[i]);
            build(1,0,n-1);
            for(int i=0;i<m;i++)
            {
                scanf("%d%d",&x,&y);
                node temp=query(1,x-1,y-1,0,n-1);
                printf("%d\n",temp.best);                
            }
        }
}