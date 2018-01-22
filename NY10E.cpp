#include<iostream>
using namespace std;
 
int main()
{
        long long int i,j,t,n,m,a[64][10],k,sum;
        cin>>t;
        while(t--)
        {
                cin>>m>>n;
                for(i=0;i<10;i++)
                        a[0][i]=1;
                for(i=1;i<n;i++)
                {
                        for(j=0;j<=9;j++)
                        {
                                sum=0;
                                for(k=0;k<=j;k++)
                                {
                                        sum=sum+a[i-1][k];
                                }
                                a[i][j]=sum;
                        }
                }
                sum=0;
                for(i=0;i<=9;i++)
                        sum=sum+a[n-1][i];
                cout<<m<<" "<<sum<<"\n";
        }
}
     


