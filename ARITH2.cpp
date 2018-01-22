#include<iostream>
using namespace std;
#include<stdio.h>
 
int main()
{
    int t,i,a[10000],x,j,p;
    char s[100000];
    cin>>t;
    for(i=0;i<t;i++)
    {
                p=-1;
                   for(j=0;j<10000;j++)
                        a[j]=0;
                    x=0;
                    do
                    {
                            gets(s);
                    }while(s[0]=='\0');
                    
                    for(j=0;s[j]!='\0';j++)
                    {
                            if(s[j]=='+' || s[j]=='-' || s[j]=='/' || s[j]=='*' ||s[j]=='=')
                            {
                                          if(p!=-1)
                                          {
                                                if(p==1)
                                                        a[x]=a[x-1]+a[x];
                                                if(p==2)
                                                        a[x]=a[x-1]-a[x];
                                                if(p==3)
                                                        a[x]=a[x-1]*a[x];
                                                if(p==4)
                                                        a[x]=a[x-1]/a[x];
                                          }
                                          if(s[j]=='+')
                                                p=1;
                                          if(s[j]=='-')
                                                p=2;
                                          if(s[j]=='*')
                                                p=3;
                                          if(s[j]=='/')
                                                p=4;
                                          x++;
                            }
                                          
                            else if(s[j]!=' ' && s[j]!='+' && s[j]!='=' && s[j]!='-' && s[j]!='/' && s[j]!='*')
                                          a[x]=a[x]*10 + s[j]-48;
                     
                    }       
                    cout<<a[x-1]<<"\n";         
    }
 
}