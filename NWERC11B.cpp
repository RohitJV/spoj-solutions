#include<iostream>
using namespace std;

int main()
{
    int t,x,i,j;
    long int a[2];
    char s[30];
    cin>>t;
    for(i=0;i<t;i++)
    {
                    a[0]=0;
                    a[1]=0;
                    x=0;
                    cin>>s;
                    for(j=0;s[j]!='\0';j++)
                    {
                                           if(s[j]=='/')
                                                        x++;
                                           else
                                               a[x] = a[x]*10 + (s[j]-48);
                    }
                    while(1)
                    {
                            if(a[0]==1 && a[1]==2)
                                       break;
                            if(a[0]==2 && a[1]==1)
                                       break;
                            if(a[0]>a[1])
                            {
                                         a[1]=a[0]-a[1];
                                         a[0]=a[0]-a[1];
                                         cout<<"R";
                                         //cout<<" R "<<a[0]<<" "<<a[1];
                            }
                            else if(a[0]<a[1])
                            {
                                         a[0]=a[1]-a[0];
                                         a[1]=a[1]-a[0];
                                         cout<<"L";
                                         //cout<<" L "<<a[0]<<" "<<a[1];
                            }
                    }
                    if(a[0]==1 && a[1]==2)
                               cout<<"L\n";
                    else
                               cout<<"R\n";
    }
}
                                               
                                           
