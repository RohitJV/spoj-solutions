#include<iostream>
using namespace std;
#include<math.h>
main()
{
long int a;
int i,j,b,x;
cin>>x;
for(i=0; i<x ;i++)
        {
        b=0;
        cin>>a;
        j=1;
        while(1)
        	{
         	if(a/pow(5,j)<1) break;
         	b=b+ a/pow(5,j); 
         	}       	
        cout<<b<<"\n";
        }
}









