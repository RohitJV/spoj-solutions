#include<iostream>
using namespace std;
int main()
{
	int t;
	long long int a[1000],n,k;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		a[i]=1;
		cin>>n>>k;
		n=n-1;
		k=k-1;
		for(int j=1;j<=k;j++)
		{
			a[i]=a[i]*(n-k+j)/j;
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<a[i]<<"\n";
	}
}
	


