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
#define REP(x,y) for(int x=0;x<y;x++)

int t,a[105][105],b[105][105],m,n;
long long int c[105][105],ans;

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        for(int i=0;i<m;i++)
        {
            long long int temp=0;
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&c[i][j]);
                c[i][j]=c[i][j]*min(b[i][j],a[i][j]);
                temp=max(temp,c[i][j]);
            }
            ans=ans+temp;
        }
        printf("%lld\n",ans);
    }
}
