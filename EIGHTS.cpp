#include<iostream>
using namespace std;
int main()
{
	unsigned long long int n,k;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>k;
		n = 250*(k-1) + 192;
		cout<<n<<"\n";	
	}
}


