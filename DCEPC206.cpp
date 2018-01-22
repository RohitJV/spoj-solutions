#include<iostream>
using namespace std;

long long int l[100000],m[100000];
int n1,n2;

void merge(long long int a[100000],int p,int q,int r,long long int sum[1])
{
     int i,j,k,x=0;
     long long int lsum=0;
     n1=q-p+1;
     n2=r-q;
     for(i=0;i<n1;i++)
             l[i]=a[p+i];
     for(j=0;j<n2;j++)
             m[j]=a[q+j+1];
     l[i]=20000000;
     m[j]=20000000;
     i=0;
     j=0;
     for(k=p;k<=r;k++)
     {
                      if(x==0)
                      {
                               if(l[i]<m[j])
                               {
                                    a[k]=l[i];
                                    i++;
                                    lsum=lsum+a[k];
                                    if(i==n1)
                                             x=-1;
                               }
                               else
                               {
                                    sum[0]=sum[0]+lsum;
                                    a[k]=m[j];
                                    j++;
                                    if(j==n2)
                                             x=1;
                               }
                      }
                      else if(x==-1)
                      {
                           sum[0]=sum[0]+lsum;
                           a[k]=m[j];
                           j++;
                      }
                      else
                      {
                           a[k]=l[i];
                           i++;
                      }
     }
}

void mergesort(long long int a[100000],int p,int r,long long int sum[1])
{
     int q;
     if(p<r)
     {
                   q=(p+r)/2;
                   mergesort(a,p,q,sum);
                   mergesort(a,q+1,r,sum);
                   merge(a,p,q,r,sum);
     }
}

int main()
{
    int n,t;
    long long int a[100000],sum[1];
    cin>>t;
    for(int j=0;j<t;j++)
    {
    sum[0]=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    mergesort(a,0,n-1,sum);
    cout<<sum[0]<<"\n";
    } 
}
    
