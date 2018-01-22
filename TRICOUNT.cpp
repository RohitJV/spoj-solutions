#include<iostream>
using namespace std;
int main()
{
	long long int a[10000],n,m;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		a[i]=0;
		cin>>n;
		m=n/2;
		a[i] = ( (n*(n+1)*(2*n+1))/6 + (n*(n+1))/2 )/2  +  
		( (n*n*m) + 2*(m*(m+1)*(2*m+1))/3 - (2*m*(m+1)*n) + (3*n*m)
		- (3*m*(m+1)) + (2*m) )/2;
	}
	for(int i=0;i<t;i++)
		cout<<a[i]<<" ";
}




