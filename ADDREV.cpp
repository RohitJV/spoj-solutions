#include<iostream>
using namespace std;
 
int t,a,b,c,a1,b1,c1;
 
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a1=0;
        b1=0;
        c=0;
        while(a!=0)
        {
            a1=a1*10+(a%10);
            a=a/10;
        }
        while(b!=0)
        {
            b1=b1*10+(b%10);
            b=b/10;
        }
        c1=a1+b1;
        while(c1!=0)
        {
            c=c*10+(c1%10);
            c1=c1/10;
        }
        cout<<c<<"\n";
    }
}