#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
int n,z;
pair<int,int> a[101][101],ans;
 
pair<int,int> calc(int x,int y)
{
    pair<int,int> temp1,temp2,store1,store2;
    if(a[x][y].first!=-1)
        return(a[x][y]);
    else
    {
        int mini=1000000;
        for(int i=x;i<y;i++)
        {
            temp1=calc(x,i);
            temp2=calc(i+1,y);
            if( temp1.second + temp2.second + (temp1.first * temp2.first) < mini )
            {
                mini=temp1.second + temp2.second + (temp1.first * temp2.first);
                store1=temp1;
                store2=temp2;
            }
        }
        a[x][y]=make_pair((store1.first+store2.first)%100,mini);
        return(a[x][y]);
    }
}
 
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j].first=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&z);
            a[i][i].first=z;
            a[i][i].second=0;
        }
        ans=calc(0,n-1);
        printf("%d\n",ans.second);
    }
}