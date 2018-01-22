#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
 
int r=0,count=0;
 
void build_failure_function(char pattern[],int m,int F[])
{
  // let m be the length of the pattern 
 
  F[0] = F[1] = 0; // always true
  
  for(int i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    int j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
          r=1;
          count++;
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) 
      { 
          r=count=0;
          F[i] = 0; 
          break; 
      }
      // else go to the next best "candidate" partial match
      j = F[j];
      r=count=0;
    }
  }   
  /*for(int i=0;i<=m;i++)
    cout<<"\nF["<<i<<"] = "<<F[i];*/
}
 
int main()
{
    int res;
    char s[100005];
    int f[100005];
    while(1)
    {
        r=count=0;
        cin>>s;
        if(strcmp(s,"*")==0)
            break;
        build_failure_function(s,strlen(s),f);
        if(r==0)
            res=1;
        else
        {
            if(strlen(s)%(strlen(s)-count)!=0)
                res=1;
            else
                res=strlen(s)/(strlen(s)-count);
        }
        //cout<<f[strlen(s)]<<"  "<<count<<"\n";
        cout<<res<<"\n";
    }
}