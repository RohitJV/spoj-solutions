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
#define INF 1000000
#define X first
#define Y second

int t,n,x,y,z,ans;
int tree[500005];
typedef pair< int,pair<int,int> > pip;
pip p[500005];
pair <int,int> pr1[500005],pr2[500005],pr3[500005];
//vector <pip> v;

//Query
int read(int idx)
{
    int sum=INF;
    while(idx>0)
    {
        sum=min(sum,tree[idx]);
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx,int val)
{
    while(idx<=n)
    {
        tree[idx]=min(tree[idx],val);
        idx += (idx & -idx);
    }
}

int main()
{
    freopen("input.txt","r",stdin);

        memset(tree,INF,sizeof(tree));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            pr1[i]=mp(x,i+1);
        }
        sort(pr1,pr1+n);
        for(int i=0;i<n;i++)
            p[i].X=pr1[i].Y;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            pr2[i]=mp(x,i+1);
        }
        sort(pr2,pr2+n);
        for(int i=0;i<n;i++)
            p[i].Y.X=pr2[i].Y;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            pr3[i]=mp(x,i+1);
        }
        sort(pr3,pr3+n);
        for(int i=0;i<n;i++)
            p[i].Y.Y=pr3[i].Y;

        sort(p,p+n);
        for(int i=0;i<n;i++)
        {
            int x1=p[i].Y.X , y1=p[i].Y.Y;
            int temp=read(x1);
            if(y1 < temp)
            {
                ans++;
                update(x1,y1);
            }
        }
        printf("%d\n",ans);
}
