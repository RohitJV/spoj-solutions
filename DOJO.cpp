#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
char n[50],m[30000],i[50],j[30000];
int t,len1,len2,len3,len4,res;
 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",n,m);
        scanf("%s%s",i,j);
        len1=strlen(n);
        len2=strlen(m);
        if( (n[len1-1]-48)%2!=0 && (m[len2-1]-48)%2!=0)
        {
            len3=strlen(i);
            len4=strlen(j);
            res=(i[len3-1]-48) + (j[len4-1]-48);
            if(res%2==0)
                cout<<"Possible.\n";
            else
                cout<<"Impossible.\n";
        }
        else
            cout<<"Impossible.\n";
    }
}