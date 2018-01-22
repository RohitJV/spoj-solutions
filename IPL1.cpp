#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<math.h>
using namespace std;
 
long double dp[11][125][305],overs,temp,res,p=0.1;
char input[10],ans[10];
int t,over,target,balls,wickets,score;
 
int main()
{
    cin>>t;
    while(t--)
    {
         memset(dp,0,sizeof(dp));
         cin>>overs>>input>>target;
         temp=0;
         for(int i=0;i<strlen(input);i++)
         {
             if(input[i]=='/')
             {
                 score=temp;
                 temp=0;
             }
             else
                 temp=temp*10+input[i]-48;
         }
         wickets=temp;
    
         over=overs*10;
         balls=over%10 + (over/10)*6;
         
         if(score>=target)
                          res=1;
         else if(wickets==10 || balls==120)
                   res=0;
         else
         {
             dp[wickets][balls][score]=1;
             for(int i=wickets;i<10;i++)
             {
                for(int j=balls;j<=120;j++)
                {
                    for(int k=score;k<target+6;k++)
                    {
                            if(i==wickets && j==balls && k==score)
                                          continue;
                            temp=0;
                            for(int x=0;x<=6;x++)
                            {
                               if(k-x<target && k-x>=score && j-1>=balls)
                                      temp=temp+p*dp[i][j-1][k-x];
                            }
                            if(k-1 < target && k-1>=score && j<120)
                                   temp=temp+2*p*dp[i][j][k-1];
                            if(k < target && k>=score && j-1>=balls && i-1>=wickets)
                                 temp=temp+p*dp[i-1][j-1][k];        
                            dp[i][j][k]=temp;
                    }
                }
             }
             res=0;
             for(int i=target;i<target+6;i++)
             {
                for(int j=wickets;j<10;j++) 
                {
                    for(int k=balls;k<=120;k++)
                        res=res+dp[j][k][i];
                }
             }
         }
         res=res*10000;
         res=floor(res);
         int result=res;
         ans[0]=result%10  + 48;
         result=result/10;
         ans[1]=result%10 + 48;
         result=result/10;
         ans[2]='.';
         int pos=3;
         while(1)
         {
             ans[pos++]=result%10 + 48;
             result=result/10;
             if(result==0)
             {
                 ans[pos]='\0';
                 break;
             }
         }
         for(int i=strlen(ans)-1;i>=0;i--)
            printf("%c",ans[i]);
         printf("\n");
    }
}
 
 


