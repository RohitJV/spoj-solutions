#include<iostream>
using namespace std;
 
int main()
{
        long int t,i,j,n,a,sum;
        cin>>t;
        while(t--)
        {
                sum=0;
                j=1;
                cin>>n;
                for(i=0;i<n;i++)
                {
                        cin>>a;
                        if(i!=0)
                        {
                                if(a<0)
                                        j=1;
                                j++;
                        }
                         sum=sum+a*j;
                }
                cout<<sum<<"\n";
        }
}

