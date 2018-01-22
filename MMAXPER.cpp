#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int m1,m2,n1,n2,n,a1=0,b1=0,a2=0,b2=0,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(i==0)
            b1=b2=y;
        m1=a1+x+abs(b1-y);
        if(a2+x+abs(b2-y)>m1)
            m1=a2+x+abs(b2-y);
        if(i==0)
            b1=b2=x;
        m2=a1+y+abs(b1-x);
        if(a2+y+abs(b2-x)>m2)
            m2=a2+y+abs(b2-x);
        a1=m1;
        b1=y;
        a2=m2;
        b2=x;
    }
    if(a1>a2)
            cout<<a1;
        else
            cout<<a2;
        cout<<"\n";
}
