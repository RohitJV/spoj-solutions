#include<iostream>
using namespace std;

int a,b;

void rec(int n)
{
     if(n==1)
     {
             a=1;
             b=1;
     }
     else
     {
             rec(n/2);
             if(n%2==0)
                       b=a+b;
             else
                       a=a+b;
     }
}

int main()
{
    long long int n;
    while(1)
    {
            cin>>n;
            if(n==0)
                    break;
            rec(n);
            cout<<a<<"/"<<b<<"\n";
    }
}
