#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
 
int n,dp[5001][5001];
char s[5001];
 
int calc(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(x>=y)
        return 0;
    if(s[x]==s[y])
        dp[x][y]=calc(x+1,y-1);
    else
        dp[x][y]=1+min(calc(x,y-1),calc(x+1,y));
    return dp[x][y];
}
 
int main()
{
    scanf("%d%s",&n,s);
    memset(dp,-1,sizeof(dp));
    printf("%d",calc(0,n-1));
}