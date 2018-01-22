#include<iostream>
using namespace std;
int main()
{
	long long int n,x;
	cin>>n;
	if(n%10==0)
	{
		x=2;
		cout<<x;
	}
	else
	{
		x=1;
		n=n%10;
		cout<<x<<"\n"<<n;
	}
}