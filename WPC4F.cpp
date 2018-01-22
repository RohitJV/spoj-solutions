#include<iostream>
using namespace std;
 
int main()
{
        int a[30][3],n,temp,i,j,min,t;
        cin>>t;
        while(t--)
        {        
        cin>>n;
        for(i=0;i<n;i++)
                for(j=0;j<3;j++)
                        cin>>a[i][j];
        for(i=0;i<n;i++)
        {
                if(i!=0)
                {
                        for(j=0;j<3;j++)
                        {
                        	min=200000;
                                if(j==0)
                                {
                                        if(a[i][j]+a[i-1][j+1]<min)
                                                min=a[i][j]+a[i-1][j+1];
                                        if(a[i][j]+a[i-1][j+2]<min)
                                                min=a[i][j]+a[i-1][j+2];
                                }
                                else if(j==1)
                                {
                                        if(a[i][j]+a[i-1][j-1]<min)
                                                min=a[i][j]+a[i-1][j-1];
                                        if(a[i][j]+a[i-1][j+1]<min)
                                                min=a[i][j]+a[i-1][j+1];
                                }       
                                else
                                {
                                        if(a[i][j]+a[i-1][j-1]<min)
                                                min=a[i][j]+a[i-1][j-1];
                                        if(a[i][j]+a[i-1][j-2]<min)
                                                min=a[i][j]+a[i-1][j-2];
                                }
                                a[i][j]=min;
                        }
                        
                }                                                       
        }
        min=200000;
        for(i=0;i<3;i++)
        {
                if(a[n-1][i]<min)
                        min=a[n-1][i];
        }
        cout<<min<<"\n";
        }
}


