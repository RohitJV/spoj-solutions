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

int n,a[20],dp[40000][20],total[40000][20],pos;

int check(int num)
{
    int cnt=0,pos=0,ret;
    while(num)
    {
        if(num&1)
        {
            ret=pos;
            cnt++;
        }
        if(cnt>1)
            return -1;
        pos++;
        num>>=1;
    }
    return ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    while(1)
    {
        memset(dp,-1,sizeof(dp));
        memset(total,0,sizeof(total));
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=1;i<pow(2,n);i++)
        {
            if((pos=check(i))!=-1)
            {
                dp[i][pos]=a[pos]*2+1;
                total[i][pos]=1;
                //cout<<"yes : "<<i<<","<<dp[i][pos]<<"\n";
            }
            else
            {
                int temp=i,cnt=0;
                while(temp)
                {
                    if(temp&1)
                    {
                        int store=i^(1<<cnt),temp2=store,cnt2=0;
                        while(temp2)
                        {
                            if(temp2&1)
                            {
                                int c=dp[store][cnt2]-a[cnt2]+abs(a[cnt2]-a[cnt])+1+a[cnt];
                                if(dp[i][cnt]==c)
                                    total[i][cnt]+=total[store][cnt2];
                                else if(c>dp[i][cnt])
                                {
                                    dp[i][cnt]=c;
                                    total[i][cnt]=total[store][cnt2];
                                }
                            }
                            cnt2++;
                            temp2>>=1;
                        }
                    }
                    cnt++;
                    temp>>=1;
                }
            }
        }
        int temp=pow(2,n)-1,cnt=0,ans=-1,store=pow(2,n)-1;
        int res=0;
        while(temp)
        {
            int c=dp[store][cnt];
            if(c==ans)
                res+=total[store][cnt];
            else if(c>ans)
            {
                ans=c;
                res=total[store][cnt];
            }
            temp>>=1;
            cnt++;
        }
        cout<<ans+n<<" "<<res<<"\n";
    }
}
