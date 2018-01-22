#include<iostream.h>
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>i;
		if(i%2==0)
			cout<<i-1<<"\n";
		else
			cout<<i<<"\n";
	}
}
