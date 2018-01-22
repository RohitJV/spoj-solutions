#include<iostream>
using namespace std;

int main()
{
    int t,n,r,a[100000][2],x;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            x=1;
            cin>>n>>r;
            for(int j=0;j<r;j++)
            {
                    cin>>a[j][0]>>a[j][1];
                    if(x==1)
                    {
                            for(int k=0;k<j;k++)
                            {
                                    if(a[k][1]==a[j][1] && a[j][0]==a[k][0])
                                    {
                                                x=0;
                                                break;
                                    }
                            }
                    }
            }
            if(x==0)
                    cout<<"Scenario #"<<i+1<<": impossible\n";
            else
                    cout<<"Scenario #"<<i+1<<": possible\n";
    }
}
            
    
    

