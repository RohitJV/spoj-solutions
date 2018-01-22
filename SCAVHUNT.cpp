#include<iostream>
#include<string.h>
using namespace std;

struct scav
{
       char s1[100],s2[100];
};

int main()
{
    scav x[500];
    int t,n,i,j,k,r,q;
    cin>>t;
    for(i=0;i<t;i++)
    {
            cin>>n;
            for(j=0;j<n-1;j++)
            {                
                             cin>>x[j].s1>>x[j].s2;
            }
            cout<<"Scenario #"<<i+1<<":\n";
            for(j=0;j<n-1;j++)
            {
                    r=1;
                    for(k=0;k<n-1;k++)
                    {
                                      if( strcmp(x[j].s1,x[k].s2)==0 )
                                      {
                                          r=0;
                                          break;
                                      }
                    }
                    if(r==1)
                    {
                            cout<<x[j].s1<<"\n";
                            q=j;
                    }
            }
            for(j=0;j<n-2;j++)
            {
                              for(k=0;k<n-1;k++)
                              {
                                                if( strcmp(x[q].s2,x[k].s1)==0 )
                                                {
                                                    cout<<x[q].s2<<"\n";
                                                    q=k;
                                                    break;
                                                }
                              }
            }
            cout<<x[q].s2<<"\n";
            
            cout<<"\n";
    }
}
