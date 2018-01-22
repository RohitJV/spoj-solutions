#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
int dp[50005],t,n,y,c,val[15],in[15],rem,store;
 
int calc(int x)
{
    int res=-1;
    for(int i=0;i<=x;i++)
        dp[i]=0;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-val[j] >= 0)
            {
                dp[i]=max(dp[i],in[j]+dp[i-val[j]]); 
            }
        }
        res=max(res,dp[i]);
    }
    return(res);
}
 
int main()
{
    cin>>t;
    while(t--)
    {
        store=0;
        cin>>c>>y>>n;
        rem=c%1000;
        c=c/1000;
        for(int i=0;i<n;i++)
        {
            cin>>val[i]>>in[i];
            val[i]=val[i]/1000;
        }
        for(int i=0;i<y;i++)
        {
            int temp=calc(c);
            rem=rem+temp%1000;
            if(rem>=1000)
            {
                c=c+(rem/1000);
                rem=rem%1000;
            }
            c=c+(temp/1000);
        }
        cout<<c*1000+rem<<"\n";
    }
}
 

