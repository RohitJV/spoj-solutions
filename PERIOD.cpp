#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
 
#define pb push_back
#define mp make_pair
 
int t,n;
 
void failure_func(string pattern,int m)
{
     int i,j;
     int F[1000000];
     j=0;
     i=1;
     F[0]=0;
     
     while(i<m)
     {
               if(pattern[i]==pattern[j])
               {
                    F[i]=j+1;
                    if(F[i]>0 && (i+1)%(i+1-F[i])==0)
                        cout<<i+1<<" "<<(i+1)/(i+1-F[i])<<"\n";
                    i++;
                    j++;
               }
               else if(j>0)
                    j=F[j-1];
               else
               {
                    F[i]=0;
                    i++;
               }
     }
}
 
int main()
{
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
         cin>>n;
         cin>>s;
         cout<<"Test case #"<<i+1<<"\n";
         failure_func(s,n);
         cout<<"\n";
    }
}
 
