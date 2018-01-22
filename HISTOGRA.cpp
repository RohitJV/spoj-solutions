#include<iostream>
using namespace std;

long long int cross(long long int a[100000],long long int p,long long int q,long long int r)
{
    long long int minl=a[q],minr=a[q];
    long long int count=1,maxsum=0,sum=0,posr=q,posl=q,i;  
    for(i=q+1;i<=r;i++)
    {
                     if(a[i]<minr)
                     {
                                  minr=a[i];
                                  posr=i;
                                  break;
                     }
                     count++;
    }
    if(i==r+1)
    {
              minr=-1;
    }
    for(i=q-1;i>=p;i--)
    {
                       if(a[i]<minl)
                       {
                                    minl=a[i];
                                    posl=i;
                                    break;
                       }
                       count++;
    }
    if(i==p-1)
              minl=-1;
    maxsum=count*a[q];
    //cout<<"\tmaxsum: "<<maxsum<<"\n\tminl: "<<minl<<"\tposl: "<<posl<<"\nminr: "<<minr<<"\tposr: "<<posr<<"\n\n";
    
    while(minl!=-1 || minr!=-1)
    {
            if(minl>minr)
            {
                         for(i=posl;i>=p;i--)
                         {
                                             if(a[i]<minl)
                                             {
                                                          sum=count*minl;
                                                          minl=a[i];
                                                          posl=i;
                                                          break;
                                             }
                                             count++;
                         }
                         if(sum>maxsum)
                                       maxsum=sum;
                         if(i==p-1)
                         {
                                  sum=minl*count;
                                  if(sum>maxsum)
                                                maxsum=sum;
                                  minl=-1;
                         }       
            }
            else
            {
                         for(i=posr;i<=r;i++)
                         {
                                             //cout<<"\\n\t\tright\n";
                                             if(a[i]<minr)
                                             {
                                                          sum=count*minr;
                                                          minr=a[i];
                                                          posr=i;
                                                          break;
                                             }
                                             count++;
                         }
                         if(sum>maxsum)
                                       maxsum=sum;
                         if(i==r+1)
                         {
                                   sum=minr*count;
                                  if(sum>maxsum)
                                                maxsum=sum;
                                   minr=-1;
                         }
                         //cout<<"    count : "<<count<<"\n";
                         //cout<<"    maxsum : "<<maxsum<<"\n";
            }
    }
    return(maxsum);
}

long long int sub(long long int a[100000],long long int p,long long int r)
{
    long long int q;
    long long int left,right,mid;
    if(p==r)
            return(a[p]);
    else
    {
            q=(p+r)/2;
            left=sub(a,p,q);
            right=sub(a,q+1,r);
            //cout<<p<<" "<<q<<" "<<r<<" : \n\n";
            mid=cross(a,p,q,r);
            if(left>=right && left>=mid)
                           return(left);
            else if(right>=left && right>=mid)
                           return(right);
            else
                           return(mid);
    }
}

int main()
{
    long long int n,j;
    long long int a[100000];
    long long int sum;
    while(1)
    {
            cin>>n;
            if(n==0)
                    break;
            for(j=0;j<n;j++)
            {
                    cin>>a[j];
            }
            sum=sub(a,0,n-1);
            cout<<sum<<"\n";
    } 
}
    
    
            
            
