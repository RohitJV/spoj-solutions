#include<iostream>
using namespace std;
int main()
{
	int n,a[10000],i;
	long long int sum,s[1000000];
	for(i=0;;i++)
	{
		s[i]=0;
		cin>>n;
		if(n==-1)
			break;
		sum=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			sum=sum+a[j];
		}
		if(sum%n==0)
		{
			for(int j=0;j<n;j++)
			{
				if(sum/n > a[j])
					s[i]=s[i]+sum/n-a[j];
			}
		}
		else
			s[i]=-1;
	}
	for(int j=0;j<i;j++)
	{
		cout<<s[j]<<"\n";
	}
}
