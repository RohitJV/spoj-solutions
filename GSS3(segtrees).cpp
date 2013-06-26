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
                //cout<<tree[i].best<<"end\n";
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        tree[i].tsum=tree[2*i].tsum+tree[2*i+1].tsum;
        tree[i].lsum=max(tree[2*i].lsum,tree[2*i].tsum+tree[2*i+1].lsum);
        //cout<<"a.lsum = "<<tree[i].lsum;
        tree[i].rsum=max(tree[2*i+1].rsum,tree[2*i+1].tsum+tree[2*i].rsum);
        //cout<<"        a.rsum = "<<tree[i].rsum;
        tree[i].best=max ( max( max(tree[i].lsum,tree[i].rsum) , max(tree[2*i].rsum+tree[2*i+1].lsum,tree[i].tsum) ) , ( max(tree[2*i].best,tree[2*i+1].best) ) );
        //cout<<"\n"<<tree[i].best<<"\n";
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
 
void update(int in,int i,int j,int l,int h)
{
        if(i<l || i>h)
                return;
        if(l==i && h==i)
        {
                tree[in].tsum=tree[in].rsum=tree[in].lsum=tree[in].best=j;
                return;
        }
        int mid=(l+h)/2;
        update(2*in,i,j,l,mid);
        update(2*in+1,i,j,mid+1,h);
        tree[in].tsum=tree[2*in].tsum+tree[2*in+1].tsum;
        tree[in].lsum=max(tree[2*in].lsum,tree[2*in].tsum+tree[2*in+1].lsum);
        tree[in].rsum=max(tree[2*in+1].rsum,tree[2*in+1].tsum+tree[2*in].rsum);
        tree[in].best=max ( max( max(tree[in].lsum,tree[in].rsum) , max(tree[2*in].rsum+tree[2*in+1].lsum,tree[in].tsum) ) , ( max(tree[2*in].best,tree[2*in+1].best) ) );
        return;
}
 
int main()
{
        inf.tsum=inf.rsum=inf.lsum=inf.best=-1000000;
        int mode,x,y,m;
        cin>>n;
        for(int i=0;i<n;i++)
                cin>>s[i];
        build(1,0,n-1);
        cin>>m;
        for(int i=0;i<m;i++)
        {
                cin>>mode>>x>>y;
                if(mode==1)
                {
                        node temp=query(1,x-1,y-1,0,n-1);
                        cout<<temp.best<<"\n";
                }
                else
                {
                        update(1,x-1,y,0,n-1);
                }
        }
}

