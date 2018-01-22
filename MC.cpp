#include<iostream>
//#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;

string s1,s2;
int dp[1005][1005];

int calc(int x,int y)
{
    if(dp[x][y]!=0)
                   return dp[x][y];
    if(x==s1.size())
    {
         dp[x][y]=30*(s2.size()-y);
         return dp[x][y];
    }
    if(y==s2.size())
    { 
         dp[x][y]=15*(s1.size()-x);
         return dp[x][y];
    }
    if(s1[x]==s2[y])
                    dp[x][y]=calc(x+1,y+1);
    else
                    dp[x][y]=min(15+calc(x+1,y),30+calc(x,y+1));
    return dp[x][y];
}

int main()
{
    while(1)
    {
            cin>>s1;
            if(s1[0]=='#')
                          break;
            cin>>s2;
            memset(dp,0,sizeof(dp));
            cout<<calc(0,0)<<"\n";
    }
}
