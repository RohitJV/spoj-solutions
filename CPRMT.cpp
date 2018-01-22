#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct str
{
        char m;
        int n;
};
 
int main()
{
        str c[2000],temp;
        char a[2000],b[2000];
        int i,x,j,l1,l2;
        while(scanf("%s",a)!=EOF)
        {
                x=0;
                scanf("%s",b);
		l1=strlen(a);
		l2=strlen(b);
                for(i=0;i<l1;i++)
                {
                        for(j=0;j<l2;j++)
                        {
                                if(a[i]==b[j])
                                {
                                        c[x].m=a[i];
                                        c[x].n=c[x].m;
                                        a[i]='$';
                                        b[j]='$';
					//cout<<c[x].m<<"\n";
                                        x++;
					//cout<<a<<"\n"<<b<<"\n\n";
					break;
                                }
                        }
                }
                for(i=0;i<x;i++)
                {
                        for(j=i+1;j<x;j++)
                        {
                                if(c[i].n>c[j].n)
                                {
                                        temp=c[i];
                                        c[i]=c[j];
                                        c[j]=temp;
                                }
                        }
                        cout<<c[i].m;
                }
                cout<<"\n";
        }
}