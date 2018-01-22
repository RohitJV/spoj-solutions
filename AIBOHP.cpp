#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

short int dp[6200][6200];
int t;
char s[6200];

int calc(int x,int y)
{
    if(x>=y)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(s[x]==s[y])
    {
        dp[x][y]=calc(x+1,y-1);
        return dp[x][y];
    }
    else
    {
        dp[x][y]=1+min(calc(x+1,y),calc(x,y-1));
        return dp[x][y];
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%s",s);
        printf("%d\n",calc(0,strlen(s)-1));
    }
}