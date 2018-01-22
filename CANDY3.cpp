#include<iostream>
using namespace std;

int main()
{
	long long int n,a,arr[100],t,i,j;
	cin>>t;
	
	for(i=0;i<t;i++)
	{
		cin>>n;
		arr[i]=0;
		for(j=0;j<n;j++)
		{
			cin>>a;
			arr[i]=(arr[i]+a)%n;
		}
	}	
	
	for(i=0;i<t;i++)
	{
		if(arr[i]==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}	
			