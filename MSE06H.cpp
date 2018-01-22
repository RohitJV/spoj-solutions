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

int t,n,m,k;
long long res;
int tree[10005],store[10005];
pair <int,int> p[1000005];

//Query
int read(int idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx,int val)
{
    while(idx<=10005)
    {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        res=0;
        memset(store,0,sizeof(store));
        scanf("%d%d%d",&n,&m,&k);

        //Initialize the tree
        memset(tree,0,sizeof(tree));
        for(int i=0;i<k;i++)
            scanf("%d%d",&p[i].X,&p[i].Y);
        sort(p,p+k);
        p[k].X=p[k].Y=0;

        //Query and Update
        int j,temp;
        for(int i=0;i<k;i++)
        {
                res=res+i-read(p[i].Y);
                update(p[i].Y,1);
        }
        printf("Test case %d: %lld\n",cas,res);
    }
}


