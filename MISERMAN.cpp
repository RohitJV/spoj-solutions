#include<iostream>
using namespace std;
 
int main()
{
        int a[101][101],n,m,sum=0,temp,i,j,min;
        cin>>n>>m;
        for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                        cin>>a[i][j];
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        min=200000;
                        if(i-1>=0)
                        {
                                if(j-1>=0)
                                {
                                        if(a[i][j]+a[i-1][j-1]<min)
                                                min=a[i][j]+a[i-1][j-1];
                                }
                                if(j+1<m)
                                {
                                        if(a[i][j]+a[i-1][j+1]<min)
                                                min=a[i][j]+a[i-1][j+1];
                                }
                                if(a[i][j]+a[i-1][j]<min)
                                        min=a[i][j]+a[i-1][j];
                                a[i][j]=min;
                        }
                        //cout<<a[i][j]<<" ";
                }
                //cout<<"\n";
        }
        min=200000;
        for(i=0;i<m;i++)
        {
                if(a[n-1][i]<min)
                        min=a[n-1][i];
        }
        cout<<min;
}