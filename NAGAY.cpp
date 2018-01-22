#include<iostream>
using namespace std;
int main()
{
	long long int n,k,r=0;
	cin>>n>>k;
	for(int i=1;i<k;i++)
	{
		r=r+(k%i);
	}
	r=r+((n-k)*k);	
	cout<<r;
}
