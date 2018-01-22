#include<stdio.h>
#include<iostream>
using namespace std;

int a[1000005];
long long int n,m,i,maxi=0,store=0,l,h,mid,res;

int main() 
{
    scanf("%lld%lld",&n,&m);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if ( a[i] > maxi )
            maxi = a[ i ];
    }
    l=0;
    h=maxi;
    while(l<=h)
    {
        mid=(l+h)/2;
        res=0;
        for(i=0;i<n;i++)
        {
            if(a[i]-mid > 0)
                res=res+a[i]-mid;
        }
        if(res>m)
        {
            l=mid+1;
            if(mid>store)
                store = mid;
        }
        else if(res<m)
            h=mid-1;
        else
        {
            store = mid;
            break;
        }
    }
    printf( "%lld\n", store );
    return 0;
}


