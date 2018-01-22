#include<iostream>
#include<iomanip>
using namespace std;
#include<math.h>
int main()
{
        int t;
        double a,b,c,d,s,x;
        cin>>t;
        for(int i=0;i<t;i++)
        {
                cin>>a>>b>>c>>d;
                s=(a+b+c+d)/2;
                x=pow((s-a)*(s-b)*(s-c)*(s-d),0.5);
                cout<<fixed<<setprecision(2)<<x<<"\n";
        }
}
