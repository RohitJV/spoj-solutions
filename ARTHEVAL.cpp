#include<iostream>
using namespace std;
 
int i=0;
char s[10000];
 
long int brack()
{
long int a=0,b=0;
char oper='+';
while( s[i]!=')' )
{
        if( s[i] == '(' )
        {
                i++;
                b=brack();
                if(oper=='+')
                        a=a+b;
                if(oper=='-')
                        a=a-b;
                if(oper=='*')
                        a=a*b;
        }
        if( s[i]>=48 && s[i]<=57 )
        {               
                b=s[i]-48;
                if(oper=='+')
                        a=a+b;
                if(oper=='-')
                        a=a-b;
                if(oper=='*')
                        a=a*b;
                i++;
        }
        else
        {
                oper=s[i];
                i++;
        }
}
return(a);
}
 
 
int main()
{
        long int a=0,b=0;
        char oper='+';
        cin>>s;
        while(s[i]!='\0')
        {
                if( s[i] == '(' )
                {
                        i++;
                        b=brack();
                        if(oper=='+')
                                a=a+b;
                        if(oper=='-')
                                a=a-b;
                        if(oper=='*')
                                a=a*b;
                }
                else if( s[i]>=48 && s[i]<=57 )
                {               
                        b=s[i]-48;
                        if(oper=='+')
                                a=a+b;
                        if(oper=='-')
                                a=a-b;
                        if(oper=='*')
                                a=a*b;
                        i++;
                }
                else
                {
                        oper=s[i];
                        i++;
                }
        }
        cout<<a;
}
                     
