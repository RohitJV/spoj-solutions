#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
 
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                  static int c[3005][3005];
              for(int i=0;i<2001;i++)
                c[i][0]=c[0][i]=i;
                  int sum=0;
                  string a,b;
                  cin>>a>>b;
                  for(int i=0;i<a.length();i++)
                  {
                              for(int j=0;j<b.length();j++)
                              {
                                          if(a[i]==b[j])
                                                    c[i+1][j+1]=c[i][j];
                                              else          
                                    c[i+1][j+1]=1+min(min(c[i][j+1],c[i][j]),c[i+1][j]);
                                     }
                          }
                                  cout<<c[a.length()][b.length()]<<"\n";
                                 }
                                }
                    