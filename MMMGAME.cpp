#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 10000007
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin)

int main()
{
    //fi;
    int cas,t,n,m,a[1005],res=0,sum;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        res=0;
        cin>>n;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>1)
                flag=1;
            res=res^a[i];
        }
        //cout<<"Case "<<cas<<": "<<(res^flag==0?"Alice\n":"Bob\n");
        cout<<(res^flag==0?"John\n":"Brother\n");
    }
}
