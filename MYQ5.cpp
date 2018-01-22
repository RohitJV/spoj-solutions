#include<iostream>
using namespace std;
int main()
{
	long long int t,n,k,a[1000000],x,pro,p,q;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		x=n/k;
		for(int j=1;j<=x;j++)
		{
			p=(n-k*j)+j-1;
			q=j-1;
			pro=1;
			for(int k=1;k<=q;k++)
			{
				pro=pro*(p-q+k)/k;
			}
			a[i]=(a[i]+pro)%1000000007;
		}
	}
	for(int i=0;i<t;i++)
		cout<<a[i]<<"\n";
}	
