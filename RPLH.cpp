#include<iostream>
using namespace std;
#include<math.h>
#include<iomanip>

int main()
{
    int t,i;
    double n,d,g=9.806,pi=2*acos(0.0),a;
    cin>>t;
    for(i=0;i<t;i++)
    {
                    cin>>d>>n;
                    a=g*d/(n*n);
                    a=asin(a)/2;
                    a=a*180/pi;
                    cout<<"Scenario #"<<i+1<<": ";
                    if(d>(n*n)/g)
                    {
                                 cout<<-1<<"\n";
                    }
                    else             
                                     cout<<fixed<<setprecision(2)<<a<<"\n";
    }
}
                    
