#include<iostream>
using namespace std;
int main()
{
    long long int j,min,sum,a[1000000];
    int n,check,i,t;
    cin>>t;
    for(i=0;i<t;i++)
    {
            check=1;
            min=0;
            sum=0;
            cin>>n;
            for(j=0;j<n;j++)
            {
                            cin>>a[j];
                            sum=sum+a[j];
                            if(sum<=0)
                            {
                                      check=0;
                                      min=min+(sum*-1)+1;
                                      sum=1;
                            }
            }
            if(check==0)
                        cout<<"Scenario #"<<i+1<<": "<<min<<"\n";
            else
                        cout<<"Scenario #"<<i+1<<": "<<1<<"\n";
    }
}
