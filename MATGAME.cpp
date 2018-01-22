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
    int cas,t,n,m,a[55][55],res=0,sum;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        res=0;
        cin>>n>>m;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<m;j++)
                cin>>a[i][j];
            for(int j=m-1;j>=0;j--)
            	temp=a[i][j]-(a[i][j]<=temp);
            res=res^temp;
        }
        //cout<<"Case "<<cas<<": "<<(res^flag==0?"Alice\n":"Bob\n");
        cout<<(res?"FIRST\n":"SECOND\n");
    }
}
