#include<stdio.h>
#include<iostream>
using namespace std;
int n,s[100000];
 
struct node
{
    int tsum;
        int lsum,rsum;
        int best;
}inf,tree[1000000];
 
void build(int i,int l,int h)
{
        if(l==h)
        {
                tree[i].tsum=tree[i].rsum=tree[i].lsum=tree[i].best=s[l];
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        tree[i].tsum=tree[2*i].tsum+tree[2*i+1].tsum;
        tree[i].lsum=max(tree[2*i].lsum,tree[2*i].tsum+tree[2*i+1].lsum);
        tree[i].rsum=max(tree[2*i+1].rsum,tree[2*i+1].tsum+tree[2*i].rsum);
        tree[i].best=max ( max( max(tree[i].lsum,tree[i].rsum) , max(tree[2*i].rsum+tree[2*i+1].lsum,tree[i].tsum) ) , ( max(tree[2*i].best,tree[2*i+1].best) ) );
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
        temp.tsum=a.tsum+b.tsum;
        temp.lsum=max(a.lsum,a.tsum+b.lsum);
        temp.rsum=max(b.rsum,b.tsum+a.rsum);
        temp.best=max( max( max(temp.lsum,temp.rsum) , max(a.rsum+b.lsum,temp.tsum) ) , max(a.best,b.best) );
        return(temp);
} 
 
int main()
{
        int total1,total2,total3,total;
        inf.rsum=inf.lsum=inf.best=-1000000;
        inf.tsum=0;
        int x1,y1,x2,y2,m,t;
        scanf("%d",&t);
        while(t--)
        {
            
        scanf("%d",&n);
        for(int i=0;i<n;i++)
                scanf("%d",&s[i]);
        build(1,0,n-1);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1--;
                y1--;
                x2--;
                y2--;
                //node temp=query(1,x-1,y-1,0,n-1);
                if(x2>y1)
                {
                    total=query(1,y1+1,x2-1,0,n-1).tsum;
                    total+=query(1,x1,y1,0,n-1).rsum;
                    total+=query(1,x2,y2,0,n-1).lsum;
                }
                else
                {
                    total=query(1,x2,y1,0,n-1).best;
                    total=max(total,max( (query(1,x1,x2-1,0,n-1).rsum) + (query(1,x2,y2,0,n-1).lsum) , (query(1,x1,y1,0,n-1).rsum) + (query(1,y1+1,y2,0,n-1).lsum) ) );
                }
                printf("%d\n",total);
        }
        
        }
}
 
