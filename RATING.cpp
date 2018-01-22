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

int n,x,y,z,res,temp;
int tree[300005],ans[300005];
pair< int,pair<int,int> > p[300005];

//Query
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum=sum+tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx,int val)
{
    while(idx<=100005)
    {
        tree[idx]=tree[idx]+val;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].X,&p[i].Y.X);
        p[i].Y.Y=i;
    }
    sort(p,p+n);

    //Query and Update
    for(int i=0;i<n;i++)
    {
        x=p[i].X;
        y=p[i].Y.X;
        z=p[i].Y.Y;
        if(i!=0 && x==p[i-1].X && y==p[i-1].Y.X)
        {
            ans[z]=ans[p[i-1].Y.Y];
            update(y,1);
            continue;
        }
        temp=read(y);
        ans[z]=temp;
        update(y,1);
    }

    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
}

