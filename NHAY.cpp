#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
 
void failure_func(string pattern,int F[],int m)
{
     int i,j;
     F[0]=0;
     j=0;
     i=1;
     
     while(i<m)
     {
               if(pattern[i]==pattern[j])
               {
                    F[i]=j+1;
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
 
void KMP(string pattern,string text)
{
    int m=pattern.length();
    int n=text.length();
    
    int F[m];
    failure_func(pattern,F,m);
    
    int i=0,j=0;
    while(i<n)
    {
              if(text[i]==pattern[j])
              {
                     if(j==m-1)
                     {
                         cout<<i-j<<"\n";
                         j=F[j];
                         i++;
                     }
                     else
                     {
                         i++;
                         j++;
                     }
              }
              else if(j>0)
                   j=F[j-1];
              else
                   i++;
    }
    return;
}
 
int main()
{
    int t,n;
    string pattern,text;
    cin>>t;
    while(scanf("%d",&n)!=EOF)
    {
              cin>>pattern>>text;
              KMP(pattern,text);
              cout<<"\n";
    }    
}