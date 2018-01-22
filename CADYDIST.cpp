#include<stdio.h>
using namespace std;

unsigned long long l[200000],m[200000];
int n1,n2;

void merge(unsigned long long a[200000],int p,int q,int r)
{
     int i,j,k,x=0;
     n1=q-p+1;
     n2=r-q;
     for(i=0;i<n1;i++)
             l[i]=a[p+i];
     for(j=0;j<n2;j++)
             m[j]=a[q+j+1];
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

void mergesort(unsigned long long a[200000],int p,int r)
{
     int q;
     if(p<r)
     {
                   q=(p+r)/2;
                   mergesort(a,p,q);
                   mergesort(a,q+1,r);
                   merge(a,p,q,r);
     }
}

int main()
{
    int n,t,i,j;
    unsigned long long a[200000],b[200000];
    unsigned long long sum;
    
    while(1)
    {
    sum=0;
    scanf("%d",&n);
    if(n==0)
    	break;
    for(i=0;i<n;i++)
    {
            scanf("%llu",&a[i]);
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
            scanf("%llu",&b[i]);
    }
    mergesort(b,0,n-1);  
    //for(int i=0;i<n;i++)
    //{
    //        cout<<a[i]<<" ";
    //}
    for(i=0;i<n;i++)
    {
    	sum=sum+a[i]*b[n-i-1];
    }
    printf("%llu\n",sum);   
    }
    
}
    






