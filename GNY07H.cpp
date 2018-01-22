#include<iostream>
using namespace std;
 
int main()
{
        int t,a[30],b[30],c[30],n;
        cin>>t;
        a[0]=a[1]=b[1]=c[1]=1;
        b[0]=c[0]=0;
        for(int i=2;i<30;i++)
        {
                a[i]=a[i-1]+a[i-2]+b[i-1]+2*c[i-1];
                b[i]=a[i-1]+b[i-2];
                c[i]=a[i-1]+c[i-1];
        }
        for(int i=1;i<=t;i++)
        {
                cin>>n;
                cout<<i<<" "<<a[n]<<"\n";
        }
}
 