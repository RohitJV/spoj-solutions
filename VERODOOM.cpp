#include<iostream>
using namespace std;
int main()
{
	unsigned long long int t,n[150000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		n[i]=n[i]*(n[i]+1)/2*(n[i]+2);
	}
	for(int i=0;i<t;i++)
		cout<<n[i]<<"\n";
}


