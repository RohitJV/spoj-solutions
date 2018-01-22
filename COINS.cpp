#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#include<map>
map <long long, long long> h;
 
long long rec(long long n)
{
    long long r;
    if(n==0)
        return 0;
    if(h.count(n)>0)
            r=h[n];
    else
        r=0;
   // cout<<n<<" "<<r<<"\n";
        if(r==0)
        {
                r=max(n,rec(n/2)+rec(n/3)+rec(n/4));
                h[n]=r;
        }
        return r;
}
 
int main()
{
    h.clear();
        long long n;
        while(scanf("%lld",&n)!=EOF)
        {
        //printf("%lld\n\n",n);
                cout<<rec(n)<<"\n";
        }
}