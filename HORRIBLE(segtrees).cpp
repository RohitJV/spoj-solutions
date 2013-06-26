#include<iostream>
using namespace std;
 
struct node
{
    long long int sum,lazy;
    int flag;
}tree[6000000],inf;
 
void build(int i,int l,int h)
{
        if(l==h)
        {
                tree[i].sum=tree[i].lazy=tree[i].flag=0;
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        tree[i].sum=tree[i].lazy=tree[i].flag=0;
        return;
}
 
void propagate(int in,int l,int h)
{
    //cout<<"propagate : "<<in*2<<" "<<in*2+1<<" ";
    tree[in*2].flag=tree[in*2+1].flag=1;
    tree[in].flag=0;
    tree[in*2].lazy+=tree[in].lazy;
    tree[in*2+1].lazy+=tree[in].lazy;
    tree[in].sum=tree[in].sum+(h-l+1)*tree[in].lazy;
    tree[in].lazy=0;
    //cout<<tree[in].sum<<"\n";
}
 
void update(int in,int i,int j,int l,int h,long long int v)
{
        //cout<<l<<" "<<h<<"\n";
        if(l>h)
        {
            //cout<<"wrong\n";
            return;
        }
        if(tree[in].flag)
            propagate(in,l,h);
        if(l>j || h<i)
        {
            //cout<<"outofscope\n";
            return;
        }
        int left=in*2;
        int right=left+1;
        int mid=(l+h)/2;
        if(l>=i & h<=j)
        {
            tree[in].sum=tree[in].sum+((h-l+1)*v);
            tree[left].flag=tree[right].flag=1;
            tree[left].lazy+=v;
            tree[right].lazy+=v;
            //cout<<l<<" "<<h<<" "<<tree[in].sum<<"\n";
            return;
        }
        //cout<<mid<<"\n";
        update(left,i,j,l,mid,v);
        update(right,i,j,mid+1,h,v);
        tree[in].sum=tree[left].sum+tree[right].sum;
}
 
node query(int in,int i,int j,int l,int h)
{
        if(tree[in].flag)
            propagate(in,l,h);
        if(h<i || l>j)
                return(inf);
        if(i<=l && j>=h)
                return(tree[in]);
        int mid=(l+h)/2;
        node a=query(2*in,i,j,l,mid);
        node b=query(2*in+1,i,j,mid+1,h);
        node temp;
        temp.sum=a.sum+b.sum;
        return(temp);
} 
 
int main()
{
    inf.sum=0;
    int t,p,q,m,n,c;
    long long int v;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        build(1,0,6*(n-1));
        while(c--)
        {
            cin>>m;
            if(m==0)
            {
                cin>>p>>q>>v;
                update(1,p-1,q-1,0,n-1,v);
            }
            if(m==1)
            {
                cin>>p>>q;
                cout<<query(1,p-1,q-1,0,n-1).sum<<"\n";
            }
            //cout<<"\n";
        }
    }
}




