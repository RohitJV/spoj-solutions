#include<iostream>
using namespace std;
int main()
{
    int a[500000],b[500000],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
                    b[a[i]-1]=i;
    }
    for(i=n-2;i>=0 && b[i]<b[i+1];i--);
    cout<<i+1<<"\n";
}
