#include<iostream>
using namespace std;
 
int n,dp[1005][1005],sum,a[1005],total;
 
int calc(int x,int y)
{
    if(y-x==1)
    {
        dp[x][y]=max(a[x],a[y]);
    }
    if(dp[x][y]==-1)
    {
        int max1,max2;
        if(a[y]>a[x+1])
            max1=a[x]+calc(x+1,y-1);
        else
            max1=a[x]+calc(x+2,y);
    
        if(a[y-1]>a[x])
            max2=a[y]+calc(x,y-2);
        else
            max2=a[y]+calc(x+1,y-1);
            
        if(max1>max2)
        {
            dp[x][y]=max1;
            //cout<<x<<" "<<y<<" "<<a[x]<<"\n";
        }
        else
        {
            dp[x][y]=max2;
            //cout<<x<<" "<<y<<" "<<a[y]<<"\n";
        }
    }
    return(dp[x][y]);
}
 
int main()
{
    int z=1;
    while(1)
    {
        sum=total=0;
        for(int i=0;i<1005;i++)
            for(int j=0;j<1005;j++)
                dp[i][j]=-1;
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            dp[i][i]=a[i];
            total+=a[i];
        }
        sum=calc(0,n-1);
        sum=sum-(total-sum);
        cout<<"In game "<<z++<<", the greedy strategy might lose by as many as "<<sum<<" points.\n";
    }    
}