#include<iostream>
using namespace std;

long int l[30000],m[30000];
int n1,n2;

void merge(long int a[30000],int p,int q,int r)
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

void mergesort(long int a[30000],int p,int r)
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
    int n,t,i,j,k;
    long int a[30000],min;
    cin>>t;
    for(i=0;i<t;i++)
    {
                    cin>>n>>k;
                    for(j=0;j<n;j++)
                            cin>>a[j];
                    mergesort(a,0,n-1);
                    min=1000000000;
                    for(j=0;j<n-k+1;j++)
                    {
                                        if(a[j+k-1]-a[j]<min)
                                                             min=a[j+k-1]-a[j];
                    }
                    cout<<min<<"\n";
    }
    //for(int i=0;i<n;i++)
    //{
    //        cout<<a[i]<<" ";
    //}
}
    

