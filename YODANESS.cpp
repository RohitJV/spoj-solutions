#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
using namespace std;

#define mp make_pair
#define pb push_back

int t,n,ans;
int tree[30005];
string s;
map <string,int> m;

//Query
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//Update
void update(int idx)
{
    while(idx<=n)
    {
        tree[idx]++;
        idx += (idx & -idx);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        ans=0;
        m.clear();
        cin>>n;
        for(int i=n;i>0;i--)
        {
            cin>>s;
            m[s]=i;
            tree[i]=0;
        }

        tree[0]=0;
        for(int i=n;i>0;i--)
        {
            cin>>s;
            ans=ans+read(m[s]);
            update(m[s]);
        }
        cout<<ans<<"\n";
    }
}

