#include<stdio.h>
using namespace std;

long int l[200000],m[200000];
int n1,n2;

void merge(long int a[200000],int p,int q,int r,long long int count[1])
{
     int i,j,k,x=0;
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
                               if(l[i]<=m[j])
                               {
                                    a[k]=l[i];
                                    i++;
                                    if(i==n1)
                                             x=-1;
                               }
                               else
                               {
                                    a[k]=m[j];
                                    count[0]=count[0]+(n1-i);
                                    //cout<<count[0]<<" ";
                                    j++;
                                    if(j==n2)
                                             x=1;
                               }
                      }
                      else if(x==-1)
                      {
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

void mergesort(long int a[200000],int p,int r,long long int count[1])
{
     int q;
     if(p<r)
     {
                   q=(p+r)/2;
                   mergesort(a,p,q,count);
                   mergesort(a,q+1,r,count);
                   merge(a,p,q,r,count);
     }
}

int main()
{
    int n,t;
    long int a[200000];
    long long int count[1];
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
    count[0]=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%ld",&a[i]);
    }
    mergesort(a,0,n-1,count);
    //for(int i=0;i<n;i++)
    //{
    //        cout<<a[i]<<" ";
    //}
    printf("%lld\n",count[0]);
    }
    
}
    

