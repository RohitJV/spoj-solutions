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
#define fi freopen("input","r",stdin)

int t,n,a[50],res;

int main()
{
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=0;j<a[i];j++)
                res=res^i;
        }
        cout<<(res?"Tom Wins\n":"Hanks Wins\n")<<"\n";
    }
}
