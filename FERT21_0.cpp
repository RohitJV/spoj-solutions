#include<iostream.h>
#include<math.h>
main()
{
int t,i;
long long int n,j,pro,x;
cin>>t;
for(i=0;i<t;i++)
{
pro=1;
cin>>n;
for(j=1;j<=n;j++)
{
pro=pro*5;
}
pro=pro*2;
x=(long long int)pow(10,n);
cout<<pro/x<<"."<<pro%x<<"\n";
}
}






