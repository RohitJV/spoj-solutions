#include<iostream>
using namespace std;

struct busy
{
       int x;
       int y;
       int z;
};

busy l[100000],m[100000];
int n1,n2;

void merge(busy a[100000],int p,int q,int r)
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
                               if(l[i].x<m[j].x || (l[i].x==m[j].x && l[i].z<m[j].z) )
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

void mergesort(busy a[100000],int p,int r)
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
    int n,t,i,j,count;
    busy a[100000],min;
    cin>>t;
    for(i=0;i<t;i++)
    {
                    count=1;
                    cin>>n;
                    for(j=0;j<n;j++)
                    {               
                                    cin>>a[j].x>>a[j].y;
                                    a[j].z = a[j].y-a[j].x;
                    }
                    mergesort(a,0,n-1);
                    //for(j=0;j<n;j++)
                    //{
                    //                cout<<"  "<<a[j].x<<"  "<<a[j].y;
                    //}
                    min.x=a[0].x;
                    min.y=a[0].y;
                    for(j=1;j<n;j++)
                    {
                                   if(a[j].x>min.x && a[j].y<min.y)
                                   {
                                                   min=a[j];
                                   }
                                   else if(a[j].x>=min.x && a[j].x>=min.y)
                                   {
                                                   min=a[j];
                                                   count++;
                                   }
                    }
                    cout<<count<<"\n";
    } 

}
    
