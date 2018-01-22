#include<iostream>
using namespace std;
int main()
{
	int n,r;
	while(1)
	{
		r=5;
		cin>>n;
		if(n==0)
			break;
		r = r + (n-1)*5 + ( n*(n+1)/2 - 1 ) + (n-2)*(n-1);
		cout<<r<<"\n";
	}
}
