#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int n;
long int s[100005];
 
struct node
{
    long int max1,max2;
}inf,tree[1000000];
 
void build(int i,int l,int h)
{
        if(l==h)
        {
                tree[i].max1=s[l];
                tree[i].max2=-1;
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        long int x[4];
        x[0]=tree[2*i].max1;
        x[1]=tree[2*i].max2;
        x[2]=tree[2*i+1].max1;
        x[3]=tree[2*i+1].max2;
        vector<long int> y (x,x+4);
        sort(y.begin(),y.begin()+4);
        tree[i].max1=y[3];
        tree[i].max2=y[2];
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<"\n";
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
        long int x[4];
        x[0]=a.max1;
        x[1]=a.max2;
        x[2]=b.max1;
        x[3]=b.max2;
        vector<long int> y (x,x+4);
        sort(y.begin(),y.begin()+4);
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<"\n";
        temp.max1=y[3];
        temp.max2=y[2];
        return(temp);
} 
 
void update(int in,int i,int j,int l,int h)
{
        if(i<l || i>h)
                return;
        if(l==i && h==i)
        {
                tree[in].max1=j;
                tree[in].max2=-1;
                return;
        }
        int mid=(l+h)/2;
        update(2*in,i,j,l,mid);
        update(2*in+1,i,j,mid+1,h);
        long int x[4];
        x[0]=tree[2*in].max1;
        x[1]=tree[2*in].max2;
        x[2]=tree[2*in+1].max1;
        x[3]=tree[2*in+1].max2;
        vector<long int> y (x,x+4);
        sort(y.begin(),y.begin()+4);
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<"\n";
        tree[in].max1=y[3];
        tree[in].max2=y[2];
        return;
}
 
int main()
{
        inf.max1=-1;
        inf.max2=-1;
        int mode,x,y,m;
        char c;
        cin>>n;
        for(int i=0;i<n;i++)
                cin>>s[i];
       // cout<<"============ build ===========\n";
        build(1,0,n-1);
        //cout<<"\n\n\n";
        cin>>m;
        for(int i=0;i<m;i++)
        {
                cin>>c>>x>>y;
                if(c=='Q')
                {
                        //cout<<"============ query ============\n";
                        node temp=query(1,x-1,y-1,0,n-1);
                        //cout<<"\n\n";
                        //cout<<temp.max1<<" "<<temp.max2<<"\n";
                        cout<<temp.max1+temp.max2<<"\n";
                }
                else
                {
                        //cout<<"============ update ============\n";
                        update(1,x-1,y,0,n-1);
                        //cout<<"\n\n";
                        //cout<<s[x-1]<<"\n";
                }
        }
}
 
