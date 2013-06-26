#include<stdio.h>
 
struct node
{
    int on,lazy;
    int flag;
}tree[6000000],inf;
//int g=0;
 
void build(int i,int l,int h)
{
        if(l==h)
        {
                tree[i].on=tree[i].lazy=tree[i].flag=0;
                return;
        }
        int mid=(l+h)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,h);
        tree[i].on=tree[i].lazy=tree[i].flag=0;
        return;
}
 
void propagate(int in,int l,int h)
{
    tree[in*2].flag=tree[in*2+1].flag=1;
    tree[in].flag=0;
    tree[in*2].lazy+=tree[in].lazy;
    tree[in*2+1].lazy+=tree[in].lazy;
    if(tree[in].lazy % 2!=0)
        tree[in].on = (h-l+1) - tree[in].on;
    tree[in].lazy=0;
}
 
void update(int in,int i,int j,int l,int h)
{
  //  g++;
    //    if(g>100)
      //      return;
        if(l>h)
            return;
        if(tree[in].flag)
            propagate(in,l,h);
        if(l>j || h<i)
            return;
        int left=in*2;
        int right=left+1;
        int mid=(l+h)/2;
        if(l>=i & h<=j)
        {
            tree[in].on=(h-l+1)-tree[in].on;
            tree[left].flag=tree[right].flag=1;
            tree[left].lazy++;
            tree[right].lazy++;
            return;
        }
        update(left,i,j,l,mid);
        update(right,i,j,mid+1,h);
        tree[in].on=tree[left].on+tree[right].on;
}
 
node query(int in,int i,int j,int l,int h)
{
        //g++;
      //  if(g>100)
        //    return(inf);
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
        temp.on=a.on+b.on;
        return(temp);
} 
 
int main()
{
    inf.on=0;
    int p,q,m,n,c;
    
        scanf("%d%d",&n,&c);
        build(1,0,n);
        while(c--)
        {
          //  g=0;
            scanf("%d%d%d",&m,&p,&q);
            if(m==0)
                update(1,p-1,q-1,0,n-1);
            if(m==1)
                printf("%d\n",query(1,p-1,q-1,0,n-1).on);
        }
}



