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
int tree[100005];
typedef pair< int,pair<int,int> > pip;
pip p[100005];
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
    //freopen("input.txt","r",stdin);

    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        memset(tree,INF,sizeof(tree));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&p[i].X,&p[i].Y.X,&p[i].Y.Y);
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
}



