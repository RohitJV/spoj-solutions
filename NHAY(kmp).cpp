#include<iostream>
#include <stdlib.h>
#include<stdio.h>
using namespace std;
 
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
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) 
      { 
          F[i] = 0; 
          break; 
      }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
  /*for(int i=0;i<=m;i++)
    cout<<"\nF["<<i<<"] = "<<F[i];*/
}
 
int main()
{
    int n,r;
    char s;
    while(1)
    {
        int i=0,pos=0,bpos=0,j=0;
        scanf("%d",&n);
        char *a=(char *)malloc(n+1);
        //char *b=(char *)malloc(n+1);
        int *f=(int *)malloc((n+1)*sizeof(int));
        cin>>a;
        //cout<<a;
        build_failure_function(a,n,f);
        scanf("%c",&s);
        r=0;
        while(scanf("%c",&s)!=EOF)
        {
            if(s=='\n')
            {
                pos=0;
                cout<<"\n";
                r=1;
                break;
            }
            //cout<<s<<" "<<a[i]<<"\n";;
            while(1)
            {
                if(s==a[i])
                {
                    i++;
                    if(i==n)
                    {
                        i=f[n];
                        cout<<pos-n+1<<"\n";
                    }
                    break;
                }
                else if(i>0)
                {
                    i=f[i];
                }
                else
                    break;
            }
            pos++;
            //cout<<j++<<" : i : "<<i<<"\n";
        }
        if(r==0)
            break;
    }
}
