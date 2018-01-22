#include<iostream>
#include<string.h>
using namespace std;
int main()
{
        char s[10000][5];
        int t,a=0,b=0,c=0,sum=1;
        cin>>t;
        for(int i=0;i<t;i++)
                cin>>s[i];
        for(int i=0;i<t;i++)
        {
                if( strcmp(s[i],"1/4")==0 )
                        a++;
                else if( strcmp(s[i],"1/2")==0 )
                        b++;
                else if( strcmp(s[i],"3/4")==0 )
                        c++;
        }
//cout<<a<<"\t"<<b<<"\t"<<c<<"\n";
        sum=sum+b/2;
//cout<<"\n"<<sum;
        if(c>=a)
        {
                sum=sum+a;
//              cout<<"\t"<<sum;
                c=c-a;
                a=0;
                if(b%2!=0)
                {
                        sum++;
//cout<<"\t"<<sum;
                }
                sum=sum+c;
//cout<<"\t"<<sum;      
        }
        
        else
        {
                sum=sum+c;
//cout<<"\t"<<sum;
                a=a-c;
                c=0;
                if(b%2!=0)
                {
                        sum++;
//cout<<"\t"<<sum;
                        a=a-2;
                	if(a>0)
                        	sum=sum+a;
                }
                else if(a!=0)
                	sum=sum+(a-1)/4+1;
//cout<<"\t"<<sum;
        }
        cout<<sum;
}


