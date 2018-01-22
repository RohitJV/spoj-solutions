#include<iostream>
using namespace std;
int main()
{
	int t,n,a[1000],b[1000],s[10000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		s[i]=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int j=0;j<n;j++)
		{
			cin>>b[j];
		}
		for(int j=0;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[j]<a[k])
				{
					int temp;
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
				if(b[j]<b[k])
				{
					int temp;
					temp=b[j];
					b[j]=b[k];
					b[k]=temp;
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			s[i]=s[i]+(a[j]*b[j]);
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<s[i]<<"\n";
	}
}