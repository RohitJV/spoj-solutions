#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
    int t,i,a[3],x,j;
    char s[100000];
    cin>>t;
    for(i=0;i<t;i++)
    {
                    a[0]=0;
                    a[1]=0;
                    a[2]=0;
                    x=0;
                    do
                    {
                            gets(s);
                    }while(s[0]=='\0');
                            /*if(s=='\r' || x==3)
                                       break;
                            else if(s>57)
                                 a[x]=-1;
                            else if(s!=' ' && s!='+' && s!='=')
                                 a[x]=a[x]*10 + s-48;
                            else if(s=='+'|| s=='=')
                                 x++;*/
                            for(j=0;s[j]!='\0';j++)
                            {
                                                   if(s[j]=='+' || s[j]=='=')
                                                               x++;
                                                   else if(s[j]>57)
                                                                   a[x]=-1;
                                                   else if(s[j]!=' ' && s[j]!='+' && s[j]!='=')
                                                                 a[x]=a[x]*10 + s[j]-48;
                      //                             cout<<j<<" "<<s[j]<<"   "<<x<<" "<<a[x]<<"\n"
                            }
                       
                    //cout<<"\n\n"<<a[0]<<"\n"<<a[1]<<"\n"<<a[2]<<"\n\n";   
                          
                    if(a[0]<=-1)
                                a[0]=a[2]-a[1];
                    else if(a[1]<=-1)
                                     a[1]=a[2]-a[0];
                    else if(a[2]<=-1)
                                     a[2]=a[1]+a[0];
                    cout<<a[0]<<" + "<<a[1]<<" = "<<a[2]<<"\n";
    }
 
}
                                
                            
