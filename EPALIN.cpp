#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
 
void failure_func(char a[100005])
{
     int m=strlen(a),n=m*2;
     char s[100005],pattern[200005];
     for(int i=0;i<m;i++)
             s[i]=a[m-1-i];
     s[m]='\0';
     strcpy(pattern,s);
     strcat(pattern,a);
     
     int F[200005];
     int i,j;
     F[0]=0;
     j=0;
     i=1;
     
     while(i<n)
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
     int temp=n;
     while(temp>m)
                 temp=F[temp-1];
     //cout<<temp<<" "<<a<<" "<<s<<" "<<pattern<<"\n";
     char ans[200005];
     strcpy(ans,a);
     int pos=m;
     for(int k=temp;k<m;k++)
             ans[pos++]=s[k];
     ans[pos]='\0';
     cout<<ans<<"\n";
}
 
int main()
{
    char a[100005];
    while(scanf("%s",a)!=EOF)
                             failure_func(a);
}
