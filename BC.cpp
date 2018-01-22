#include<iostream>
using namespace std;
 
int main()
{
        long long t,n,m,k,i=1,count;
        cin>>t;
        while(t--)
        {
                count=0;
                cin>>n>>m>>k;
                cout<<"Case #"<<i++<<": "<<n*m*k-1<<" ";
                while(!(n==1 && k==1 && m==1))
                {
                        if(n>=m && n>=k)
                        {
                                if(n%2!=0)
                                        n++;
                                n=n/2;
                        }
                        else if(m>=n && m>=k)
                        {
                                if(m%2!=0)
                                        m++;
                                m=m/2;
                        }
                        else
                        {
                                if(k%2!=0)
                                        k++;
                                k=k/2;
                        }
                        count++;
                }
                cout<<count<<"\n";
        }
}