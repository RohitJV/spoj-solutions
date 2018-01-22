#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return(a);
	gcd(b,a%b);
}

int main()
{
	long long n,a[100000],x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	x=a[1]-a[0];
	for(int j=2;j<n;j++)
	{
		x=gcd(x,a[j]-a[j-1]);
	}
	for(int j=1;j<n;j++)
	{
		sum=sum+(a[j]-a[j-1])/x-1;
		
	}
cout<<sum;
}
