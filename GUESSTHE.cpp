#include<iostream>
#include<string.h>
using namespace std;
 
int gcd(int x,int y)
{
        if(x%y==0)
                return(y);
        else
                gcd(y,x%y);
}
 
int main()
{
        char s[21];
        int n,i,j,k,num;
        while(1)
        {
                num=1;
                cin>>s;
                if(s[0]=='*')
                        break;
                n=strlen(s);
                if(s[0]=='N')
                        num=-1;
                else
                {
                        for(i=0;i<n;i++)
                        {
                                if(s[i]=='Y')
                                        num=num/gcd(num,i+1)*(i+1);
                        }
                }
                if(num!=-1)
                {
                        for(i=0;i<n;i++)
                        {
                                if(s[i]=='N' && num%(i+1)==0)
                                {
                                        num=-1;
                                        break;
                                }
                        }
                }
                cout<<num<<"\n";
        }
}