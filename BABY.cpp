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
#define INF 100000

int n,a[20],b[20],s[20][20];
int vis[100000];

int main()
{
    //freopen("input.txt","r",stdin);
    while(1)
    {
        for(int i=0;i<70000;i++)
            vis[i]=INF;
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            for(int j=0;j<n;j++)
                s[i][j]=abs(a[j]-b[i])+abs(i-j);
        }

        int m=pow(2,n);
        for(int i=1;i<m;i++)
        {
            int temp=i,cnt=0,ans;
            while(temp)
            {
                if(temp&1)
                    cnt++;
                temp>>=1;
            }
            temp=i;
            ans=--cnt;
            cnt=0;
            if(!ans)
            {
                while(temp)
                {
                    if(temp&1)
                        vis[i]=s[ans][cnt];
                    cnt++;
                    temp>>=1;
                }
            }
            else
            {
                while(temp)
                {
                    if(temp&1)
                        vis[i]=min(vis[i],vis[i^(1<<cnt)]+s[ans][cnt]);
                    cnt++;
                    temp>>=1;
                }
            }
        }
        printf("%d\n",vis[m-1]);
    }
}
