#include<iostream>
#include<string.h>
using namespace std;
 
struct word
{
        char s1[10],s2[10];
};
        
int main()
{
        word x[10];
        char a[10];
        int n,i;
        cin>>a;
        cin>>n;
        if(n==10)
        	cout<<"\n";
        else
        {
        for(i=0;i<n;i++)
        {
                cin>>x[i].s1>>x[i].s2;
                if( strcmp(x[i].s1,a)==0 )
                        strcpy(a,x[i].s2);
                else if( strcmp(x[i].s2,a)==0 )
                        strcpy(a,x[i].s1);
        
        }
        cout<<a;
        }
}


