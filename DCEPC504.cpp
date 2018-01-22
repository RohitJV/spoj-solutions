#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    long long int k,t,n,i,count;
    cin>>t;
    for(i=0;i<t;i++)
    {
                    count=0;
                    cin>>n>>k;
                    while(k!=1)
                    {
                               if(k%2!=0)
                                         k=(k+1)/2;
                               else
                               {
                                         count++;
                                         k=k/2;  
                               }        
                    }
                    if(count%2==0)
                                  cout<<"Male\n";
                    else
                                  cout<<"Female\n";
    }
}
                    
