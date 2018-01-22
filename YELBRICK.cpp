#include<iostream>
using namespace std;
 
int main()
{
        long long int n,a,min,sum,pro,i;
        while(1)
        {
                pro=1;
                min=2000;
                sum=0;
                cin>>n;
                if(n==0)
                        break;
                for(i=1;i<=n*3;i++)
                {
                        cin>>a;
                        pro=pro*a;
                        if(a<min)
                                min=a;
                        if(i%3==0)
                        {
                                sum=sum+pro;
                                pro=1;
                        }
                }
                cout<<sum/(min*min*min)<<"\n";
        }
}