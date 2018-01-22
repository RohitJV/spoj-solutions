#include<iostream>
using namespace std;

int main()
{
    int n,a[2000],s[2][2000],i,j,k,x,max;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
                    s[1][i]=a[i]*n;
    }
    //for(j=0;j<n;j++)
    //                cout<<s[1][j]<<" ";
    //cout<<"\n";
    x=n;
    for(j=0;j<n-1;j++)
    {
             for(k=0;k<n-j-1;k++)
             {
                                 max=-1;
                                 if(j%2==1)
                                 {
                                           if(s[0][k]+a[k+j+1]*(x-1)>max)
                                                                   max=s[0][k]+a[k+j+1]*(x-1);
                                           if(s[0][k+1]+a[k]*(x-1)>max)
                                                                       max=s[0][k+1]+a[k]*(x-1);
                                           s[1][k]=max;
                                           //cout<<s[1][k]<<" ";
                                 }
                                 else
                                 {
                                           if(s[1][k]+a[k+j+1]*(x-1)>max)
                                                                   max=s[1][k]+a[k+j+1]*(x-1);
                                           if(s[1][k+1]+a[k]*(x-1)>max)
                                                                       max=s[1][k+1]+a[k]*(x-1);
                                           s[0][k]=max;
                                           //cout<<s[0][k]<<" ";
                                 }
             }
             //cout<<"\n";
             x--;
    }
    cout<<s[(j+1)%2][0];
//    getch();
}

