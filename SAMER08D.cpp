#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdio.h>
using namespace std;
 
struct node
{
    int len,n;
};
 
int k,temp;
node dp[1005][1005];
string s1,s2;
 
int main()
{
        /*for(int i=0;i<1005;i++)
        {
                dp[i][0].len=dp[i][0].n=0;
                dp[0][i].len=dp[0][i].n=0;
        }*/
        while(1)
        {
                scanf("%d",&k);
                if(k==0)
                        break;
                cin>>s1>>s2;
                for(int i=1;i<=s1.size();i++)
                {
                        for(int j=1;j<=s2.size();j++)
                        {
                                if(s1[i-1]==s2[j-1])
                                {
                                        dp[i][j].len = max(dp[i-1][j].len,dp[i][j-1].len);
                                        dp[i][j].n = dp[i-1][j-1].n + 1;
                                        temp=dp[i][j].n;
                                      
                                        if(temp>k)
                                            dp[i][j].len=max(dp[i][j].len,dp[i-1][j-1].len+1);
                                        if(temp>=k)
                                                dp[i][j].len=max(dp[i][j].len,k+dp[i-k][j-k].len);
                                }
                               
                                        else
                                        {
                                            dp[i][j].n=0;
                                            dp[i][j].len=max(dp[i-1][j].len,dp[i][j-1].len);
                                        }
                                //cout<<dp[i][j].len<<","<<dp[i][j].n<<"  ";
                        }
                        //cout<<"\n";
                }
                printf("%d\n",dp[s1.size()][s2.size()]);
        }
}
 







