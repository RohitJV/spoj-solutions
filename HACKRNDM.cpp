#include<iostream>
using namespace std;
int main()
{
	int i,n,k,a[1000000],j,sum=0;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i] && a[i]-a[j]==k)
				sum++;
			else if(a[i]>=a[j] && a[i]-a[j]==k)
				sum++;
		}
	}
	cout<<sum;
}
		